# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/giacomo/CLionProjects/lab_ocv_template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/flags.make

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/flags.make
src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.o"
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.o" -c /Users/giacomo/CLionProjects/lab_ocv_template/src/main.cpp

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.i"
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giacomo/CLionProjects/lab_ocv_template/src/main.cpp > "CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.i"

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.s"
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giacomo/CLionProjects/lab_ocv_template/src/main.cpp -o "CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.s"

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.requires

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.provides: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.requires
	$(MAKE) -f "src/CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/build.make" "src/CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.o.provides.build"
.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.provides

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.provides.build: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o


# Object files for target assignment1 ~ Giacomo Chiarot 854893
assignment1 ~ Giacomo Chiarot 854893_OBJECTS = \
"CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/main.cpp.o"

# External object files for target assignment1 ~ Giacomo Chiarot 854893
assignment1 ~ Giacomo Chiarot 854893_EXTERNAL_OBJECTS =

src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/build.make
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_stitching.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_superres.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_videostab.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_aruco.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_bgsegm.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_bioinspired.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_ccalib.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_dpm.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_face.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_fuzzy.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_img_hash.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_line_descriptor.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_optflow.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_reg.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_rgbd.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_saliency.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_stereo.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_structured_light.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_surface_matching.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_tracking.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_xfeatures2d.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_ximgproc.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_xobjdetect.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_xphoto.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_shape.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_photo.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_datasets.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_plot.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_text.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_dnn.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_ml.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_video.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_calib3d.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_features2d.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_highgui.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_videoio.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_phase_unwrapping.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_flann.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_imgcodecs.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_objdetect.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_imgproc.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: /usr/local/lib/libopencv_core.3.4.0.dylib
src/assignment1\ ~\ Giacomo\ Chiarot\ 854893: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable \"assignment1 ~ Giacomo Chiarot 854893\""
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script "CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/link.txt" --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/build: src/assignment1\ ~\ Giacomo\ Chiarot\ 854893

.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/build

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/requires: src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/requires

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/clean:
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src && $(CMAKE_COMMAND) -P "CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/cmake_clean.cmake"
.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/clean

src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/depend:
	cd /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/giacomo/CLionProjects/lab_ocv_template /Users/giacomo/CLionProjects/lab_ocv_template/src /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug /Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src "/Users/giacomo/CLionProjects/lab_ocv_template/cmake-build-debug/src/CMakeFiles/assignment1 ~ Giacomo Chiarot 854893.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/assignment1\ ~\ Giacomo\ Chiarot\ 854893.dir/depend

