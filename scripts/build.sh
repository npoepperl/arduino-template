#!/bin/bash

sketchDir="sketch/"
buildDir=$sketchDir"build/"

workingDir=$(pwd)

rebuild="no"
test="no"
buildSuccessful="no"

while [ "$1" != '' ]
  do
    [ $1 == "-r" ] && rebuild="yes" && echo "A rebuild will be performed!" && shift
    [ $1 == "-t" ] && test="yes" && echo "All tests will be executed after successful build!" && shift
done


if [ $rebuild == "yes" ]; then
    if [ -d $buildDir ]; then
        rm -r -f $buildDir
    else
        echo "The build-directory doesn't exist."
    fi
fi

if [ -d $sketchDir ]; then
    if [ ! -d $buildDir ]; then
        mkdir $buildDir
    fi

    cd $buildDir

    cmake .. 1> cmake.log 2> /dev/null

    if [ $? -eq 0 ]; then
        echo "Cmake successfully created buildfiles."
    else
        echo "Error creating buildfiles."
        exit 1
    fi

    make 1> build.log 2> /dev/null

    if [ $? -eq 0 ]; then
        echo "Build was successful."
    else
        echo "Error building library."
        exit 1
    fi

    if [ $test == "yes" ]; then
        echo "Tests will be executed."
        # add all testrunners here - path is relative from build directory
        ./test/testGameOfLife/testGameOfLife
    fi
fi

cd $workingDir