How to build:

$ mkdir build
$ cd build
$ cmake ../ -DOpenCV_DIR="<insert the path of your opencv/build directory>"
$ make


How to run:

$ cd build
$ make run


or, alternatively:

$ make install
$ cd dist/bin

and run the generated executable


--------------------------------------------------------------------------------
 NOTE:
   Before submitting any assignment, remember to delete both the generated
   "build" and "dist" directories:

    $ rm -Rf build
    $ rm -Rf dist
--------------------------------------------------------------------------------
