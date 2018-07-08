#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <list>

int main() {
    //In cardsOriginal is stored the image containing all the cards together and thresholded
    cv::Mat cardsOriginal = cv::imread("cards.jpg");
    cv::cvtColor(cardsOriginal, cardsOriginal, cv::COLOR_RGB2GRAY);
    cv::threshold(cardsOriginal, cardsOriginal, 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY_INV);

    //Computing the size of one single card
    int widthCardPx = cardsOriginal.cols / 4;
    int heightCardPx = cardsOriginal.rows / 13;

    //Where training seed and numbers are stored (with 50x20 dimensions)
    cv::Mat seeds[4];
    cv::Mat numbers[13];

    //Storing labels and ranks of cards
    std::string seedDescription[] =  {"spades", "clubs", "diamonds", "hearts"};
    std::string numberDescription[] =  {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    //Storing the status of single cards (O - out, D - on deck, T - on table)
    int cardStatus[13][4];

    //Storing the rank of the table and the previous one
    int totalRank = 0;
    int oldRank = 0;

    //Considering how many frames are with rank = 0 together
    int voidTable = 40;

    //Cutting cards to separate seeds of first 4 cards
    for (int i = 0; i < 4; i++) {
        int startX = i * widthCardPx;
        cv::Rect myROI(startX, 0, widthCardPx, heightCardPx);
        cv::Mat imgCropped(cardsOriginal, myROI);

        cv::Rect myROI1(25, 110, 60, 60);
        cv::Mat seed(imgCropped, myROI1);

        std::vector<std::vector<cv::Point>> contoursSeed;
        std::vector<cv::Vec4i> hierarchySeed;
        cv::findContours(seed, contoursSeed, hierarchySeed, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));;

        cv::Rect seedR = cv::boundingRect(contoursSeed[0]);

        seed = cv::Mat(seed, seedR);

        //Resize to a 50x20 img
        cv::resize(seed, seed, cv::Size_(50, 20));

        seeds[i] = seed;
    }

    //Cutting cards to separate numbers of first 13 cards
    for (int i = 0; i < 13; i++) {
        int startY = i * heightCardPx;
        cv::Rect myROI(0, startY, widthCardPx, heightCardPx);
        cv::Mat imgCropped(cardsOriginal, myROI);

        cv::Rect myROI1(20, 30, 70, 80);
        cv::Mat number(imgCropped, myROI1);

        std::vector<std::vector<cv::Point>> contoursNumber;
        std::vector<cv::Vec4i> hierarchySeed;
        cv::findContours(number, contoursNumber, hierarchySeed, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));;

        int index = 0;
        int maxArea = 0;
        int m = -1;
        for (auto j = contoursNumber.begin(); j != contoursNumber.end(); j++) {
            m++;
            if (cv::contourArea(j.operator*()) > maxArea) {
                maxArea = cv::contourArea(j.operator*());
                index = m;
            }
        }

        cv::Rect numberR = cv::boundingRect(contoursNumber[index]);
        number = cv::Mat(number, numberR);

        //Resize to a 50x20 img
        cv::resize(number, number, cv::Size_(50, 20));

        numbers[i] = number;
        for (int j = 0; j < 4; j++)
            cardStatus[i][j] = 10;
    }

    //Loading the video
    cv::VideoCapture video("test_video_2.mp4");

    //Analyzing frames of the video one by one
    cv::Mat frame;
    for (int frameNum = 0; frameNum < video.get(CV_CAP_PROP_FRAME_COUNT); frameNum++) {
        //Extracting the frame
        video >> frame;
        totalRank = 0;

        //Thresholding the frame
        cv::Mat frameThresholded;
        cv::cvtColor(frame, frameThresholded, cv::COLOR_RGB2GRAY);
        cv::threshold(frameThresholded, frameThresholded, 0, 255, CV_THRESH_OTSU);

        //Finding contours on frameThresholded
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        cv::findContours(frameThresholded, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));;

        //Considering each contour one by one
        for (auto i = contours.begin(); i != contours.end(); i++) {
            //Getting the area of the current contour
            double area = cv::contourArea(i.operator*());

            //Considering the contour only if its area is between 10000 and 100000.
            //These values are chosen to select only contours related to cards, with the smallest margin of error.
            //The interval is modelled for the two video case-study.
            if (area > 10000 && area < 100000) {
                //Finding perimeter and corner points.
                double perimeter = cv::arcLength(i.operator*(), true);
                std::vector<cv::Point> cornersApproximated;
                cv::approxPolyDP(i.operator*(), cornersApproximated, 0.01 * perimeter, true);

                //Finding width, height and corner NE coordinates of the card
                cv::Rect dimensions = cv::boundingRect(i.operator*());
                int cardHeight = dimensions.height;
                int cardWidth = dimensions.width;

                //Finding the central point of the card.
                int centralX = 0;
                int centralY = 0;
                int num = 0;
                for (auto j = cornersApproximated.begin(); j != cornersApproximated.end(); j++) {
                    centralX += j.operator*().x;
                    centralY += j.operator*().y;
                    num++;
                }
                centralX /= num;
                centralY /= num;

                //Transforming the image to a rectangle prospective to be compared with training images.
                cv::Mat transformedCard;

                int minSum = cornersApproximated[0].x + cornersApproximated[0].y;
                int maxSum = 0;
                int minDiff = cornersApproximated[0].x - cornersApproximated[0].y;
                int maxDiff = 0;
                int minIndexSum = 0;
                int maxIndexSum = 0;
                int minIndexDiff = 0;
                int maxIndexDiff = 0;
                int index = 0;
                for (auto j = cornersApproximated.begin(); j != cornersApproximated.end(); j++) {
                    int sum = j.operator*().x + j.operator*().y;
                    int diff = j.operator*().x - j.operator*().y;

                    if (sum > maxSum) {
                        maxSum = sum;
                        maxIndexSum = index;
                    }
                    if (sum < minSum) {
                        minSum = sum;
                        minIndexSum = index;
                    }
                    if (diff > maxDiff) {
                        maxDiff = diff;
                        maxIndexDiff = index;
                    }
                    if (diff < minDiff) {
                        minDiff = diff;
                        minIndexDiff = index;
                    }
                    index++;
                }

                //Ordering point as: top left, top right, bottom right, bottom left
                cv::Point2f points[4];
                //In case the card is vertical
                if (cardWidth <= 0.8 * cardHeight) {
                    points[0] = cornersApproximated[minIndexSum];
                    points[3] = cornersApproximated[minIndexDiff];
                    points[2] = cornersApproximated[maxIndexSum];
                    points[1] = cornersApproximated[maxIndexDiff];
                }
                //In case the card is horizontal
                if (cardWidth >= 1.2 * cardHeight) {
                    points[3] = cornersApproximated[maxIndexSum];
                    points[2] = cornersApproximated[maxIndexDiff];
                    points[1] = cornersApproximated[minIndexSum];
                    points[0] = cornersApproximated[minIndexDiff];
                }

                //In case the card has different shape
                if (cardWidth > 0.8 * cardHeight && cardWidth < 1.2 * cardHeight) {
                    cv::Point p0 = cornersApproximated[0];
                    cv::Point p1 = cornersApproximated[1];
                    cv::Point p2 = cornersApproximated[2];
                    cv::Point p3 = (cornersApproximated.end() - 1).operator*();

                    //In case the up-left point is upper respect to the up-right
                    if (cornersApproximated[1].y <= cornersApproximated[3].y) {
                        if (cardWidth < cardHeight + 40) {
                            points[0] = p1;
                            points[1] = p0;
                            points[2] = p3;
                            points[3] = p2;
                        } else {
                            points[1] = p1;
                            points[2] = p0;
                            points[3] = p3;
                            points[0] = p2;
                        }
                    } else {
                        if (cardWidth < cardHeight + 40) {
                            points[0] = p0;
                            points[1] = p3;
                            points[2] = p2;
                            points[3] = p1;
                        }
                        else {
                            points[3] = p0;
                            points[0] = p3;
                            points[1] = p2;
                            points[2] = p1;
                        }
                    }
                }

                //Finding edges
                cv::Point2f dst[4];
                dst[0] = cv::Point(0, 0);
                dst[1] = cv::Point(widthCardPx - 1, 0);
                dst[2] = cv::Point(widthCardPx - 1, heightCardPx - 1);
                dst[3] = cv::Point(0, heightCardPx - 1);

                //Warping image
                transformedCard = cv::getPerspectiveTransform(points, dst);
                cv::warpPerspective(frame, transformedCard, transformedCard, cv::Size_(widthCardPx, heightCardPx));
                cv::cvtColor(transformedCard, transformedCard, cv::COLOR_BGR2GRAY);

                //Threasholding card
                cv::threshold(transformedCard, transformedCard, 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY_INV);

                //Cutting number and seed
                cv::Rect numberRect(385, 20, 55, 85);
                cv::Mat number(transformedCard, numberRect);

                cv::Rect seedRect(385, 90, 55, 75);
                cv::Mat seed(transformedCard, seedRect);

                //Finding contours of number
                std::vector<std::vector<cv::Point>> contoursNumber;
                std::vector<cv::Vec4i> hierarchyNumber;
                cv::findContours(number, contoursNumber, hierarchyNumber, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));;

                //Finding contours of seed
                std::vector<std::vector<cv::Point>> contoursSeed;
                std::vector<cv::Vec4i> hierarchySeed;
                cv::findContours(seed, contoursSeed, hierarchySeed, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));;

                //Getting the contour with max area for the number
                int indexN = 0;
                int m = -1;
                int maxArea = 0;
                for (auto i = contoursNumber.begin(); i != contoursNumber.end(); i++) {
                    m++;
                    if (cv::contourArea(i.operator*()) > maxArea) {
                        indexN = m;
                        maxArea = cv::contourArea(i.operator*());
                    }
                }

                //Getting the contour with max area for the seed
                int indexS = 0;
                m = -1;
                maxArea = 0;
                for (auto i = contoursSeed.begin(); i != contoursSeed.end(); i++) {
                    m++;
                    if (cv::contourArea(i.operator*()) > maxArea) {
                        indexS = m;
                        maxArea = cv::contourArea(i.operator*());
                    }
                }

                if (contoursNumber.size() > 0 && contoursSeed.size() > 0) {
                    //Extracting only the number and seed
                    cv::Rect numberR = cv::boundingRect(contoursNumber[indexN]);
                    cv::Rect seedR = cv::boundingRect(contoursSeed[indexS]);

                    //Creating a new image containing only number or seed
                    number = cv::Mat(number, numberR);
                    seed = cv::Mat(seed, seedR);

                    //Resize to a 50x20 img
                    cv::resize(number, number, cv::Size_(50, 20));
                    cv::resize(seed, seed, cv::Size_(50, 20));

                    //Finding which is the training seed that match better with the card seed
                    //by counting the difference of pixels
                    int matchSeed = 0;
                    int minDifferencesSeed = 1000;
                    for (int i = 0; i < 4; i++) {
                        int differences = 0;
                        bool stop = false;
                        for (int j = 0; j < 20 && !stop; j++) {
                            for (int k = 0; k < 50 && !stop; k++) {
                                if (seeds[i].at<uchar>(j, k) != seed.at<uchar>(j, k))
                                    differences++;
                                if (differences > 275)
                                    stop = true;
                            }
                        }
                        stop = false;
                        if (differences < minDifferencesSeed) {
                            minDifferencesSeed = differences;
                            matchSeed = i;
                        }
                    }

                    //If difference is less than 275 it means that it is a seed
                    //so doing the same for the number
                    if (minDifferencesSeed < 275) {
                        int matchNumber = 0;
                        int minDifferencesNumber = 1000;
                        for (int i = 0; i < 13; i++) {
                            int differences = 0;
                            for (int j = 0; j < 20; j++) {
                                for (int k = 0; k < 50; k++) {
                                    if (numbers[i].at<uchar>(j, k) != number.at<uchar>(j, k))
                                        differences++;
                                }
                            }
                            if (differences < minDifferencesNumber) {
                                matchNumber = i;
                                minDifferencesNumber = differences;
                            }
                        }

                        //If the differnece is less than 300 it is a number
                        if (minDifferencesNumber < 300) {
                            totalRank += values[matchNumber];

                            if (cardStatus[matchNumber][matchSeed] > 0)
                                cardStatus[matchNumber][matchSeed]--;

                            //drawing contours
                            cv::drawContours(frame, std::vector<std::vector<cv::Point>>(1, i.operator*()), 0,
                                             cv::Scalar(0, 255, 0), 2);

                            //Writing description
                            std::string description = numberDescription[matchNumber] + " of " + seedDescription[matchSeed];
                            cv::putText(frame, description, cv::Point_(centralX - 80, centralY), 0, 1, cv::Scalar(255, 255, 255), 2);
                        }
                    }
                }
            }
        }

        //Computing the rank:
        //it only increase and it is zero when the table has zero rank for 40 frames and it has reached 21.
        if (totalRank < oldRank) {
            if (totalRank > 0 || oldRank < 21) {
                totalRank = oldRank;
                voidTable = 40;
            }
            else {
                voidTable--;
                if (voidTable == 0) {
                    oldRank = 0;
                    totalRank = 0;
                }
                else
                    totalRank = oldRank;
            }
        } else if (totalRank > oldRank) {
            oldRank = totalRank;
            voidTable = 40;
        }

        //Computing probabilities by looking at how many cards are left to win, loose or be less than 21.
        float probWin = 0, probLoose = 0, probMin = 1;
        std::string status[] = {"", "", "", ""};

        if (totalRank != 0) {
            float cardWin = 0, cardLoose = 0, cardMin = 0, total = 0;

            for (int i = 0; i < 13; i++) {
                int totalTemp = 0;
                for (int j = 0; j < 4; j++) {
                    if (cardStatus[i][j] > 0) {
                        total++;
                        totalTemp++;
                        status[j] += (i == 0) ? "D" : " - D";
                    }
                    if (cardStatus[i][j] == 0)
                        status[j] += (i == 0) ? "T" : " - T";
                    if (cardStatus[i][j] == -1)
                        status[j] += (i == 0) ? "O" : " - O";
                }
                if (totalRank + values[i] == 21)
                    cardWin += totalTemp;
                if (totalRank + values[i] < 21)
                    cardMin += totalTemp;
                if (totalRank + values[i] > 21)
                    cardLoose += totalTemp;
            }

            probWin = cardWin / total;
            probMin = cardMin / total;
            probLoose = cardLoose / total;
        } else {
            for (int i = 0; i < 13; i++)
                for (int j = 0; j < 4; j++)
                    if (cardStatus[i][j] == 0 || cardStatus[i][j] == -1) {
                        cardStatus[i][j] = -1;
                        status[j] += (i == 0) ? "O" : " - O";
                    } else {
                        status[j] += (i == 0) ? "D" : " - D";
                        cardStatus[i][j] = 10;
                    }

        }

        //Showing total rank on table.
        cv::putText(frame, "Total rank: " + std::to_string(totalRank), cv::Point_(20, 50), 0, 1, cv::Scalar_(255, 255, 255), 2);
        cv::putText(frame, "Prob win: " + std::to_string(probWin), cv::Point_(20, 100), 0, 1, cv::Scalar_(255, 255, 255), 2);
        cv::putText(frame, "Prob loose: " + std::to_string(probLoose), cv::Point_(20, 150), 0, 1, cv::Scalar_(255, 255, 255), 2);
        cv::putText(frame, "Prob min: " + std::to_string(probMin), cv::Point_(20, 200), 0, 1, cv::Scalar_(255, 255, 255), 2);

        //If winning or loosing it is shown.
        if (totalRank == 21)
            cv::putText(frame, "WIN", cv::Point_(20, 250), 0, 1, cv::Scalar_(0, 255, 0), 2);
        if (totalRank > 21)
            cv::putText(frame, "LOOSE", cv::Point_(20, 250), 0, 1, cv::Scalar_(0, 0, 255), 2);

        //Showing the status of each card
        cv::putText(frame, "Spades: " + status[0], cv::Point_(20, 550), 0, 1, cv::Scalar_(255, 255, 255), 1);
        cv::putText(frame, "Clubs: " + status[1], cv::Point_(20, 600), 0, 1, cv::Scalar_(255, 255, 255), 1);
        cv::putText(frame, "Diamonds: " + status[2], cv::Point_(20, 650), 0, 1, cv::Scalar_(255, 255, 255), 1);
        cv::putText(frame, "Hearts: " + status[3], cv::Point_(20, 700), 0, 1, cv::Scalar_(255, 255, 255), 1);

        cv::imshow("Giacomo Chiarot - 854893", frame);
        //The video is paused when pressed space and replay with space
        if (cv::waitKey(1) == 32) {
            while (cv::waitKey(1) != 32);
        }
    }
    return 0;
}
