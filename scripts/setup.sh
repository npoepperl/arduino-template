#!/bin/bash

# print welcome message
clear
echo "
##################################################################
______       _ _     _   _____                    _       _
| ___ \     (_) |   | | |_   _|                  | |     | |
| |_/ /_   _ _| | __| |   | | ___ _ __ ___  _ __ | | __ _| |_ ___
| ___ \ | | | | |/ _  |   | |/ _ \ '_ ' _ \| '_ \| |/ _' | __/ _ \ 
| |_/ / |_| | | | (_| |   | |  __/ | | | | | |_) | | (_| | ||  __/
\____/ \__,_|_|_|\__,_|   \_/\___|_| |_| |_| .__/|_|\__,_|\__\___|
                                           | |
                                           |_|
##################################################################


"

# store working dir to cd back at the end
currentWorkingDir=$PWD

# change directory to project root
scriptLocation=$(dirname "$(readlink -e "$0")")
cd $scriptLocation/..

# download arduino ide and unzip
if [ ! -d "$PWD/arduino" ]; then
    echo "Arduino IDE not found in project. Downloading and installing"
    curl -O https://downloads.arduino.cc/arduino-1.8.5-linux64.tar.xz
    tar -xf arduino-1.8.5-linux64.tar.xz > /dev/null 2>&1
    rm arduino-1.8.5-linux64.tar.xz > /dev/null 2>&1
    mv arduino-1.8.5 arduino > /dev/null 2>&1
else
    echo "Arduino IDE found in project - skipping download."
fi

# set sektchbook path to sketch folder
printf "\033[1;31mWARNING:\033[0m Setting libraries folder to $PWD/sketch/.\n"
printf "\033[1;31mWARNING:\033[0m This applies to all calls to Arduino IDE in future.\n"
./arduino/arduino --pref sketchbook.path=$PWD/sketch/ --save-prefs > /dev/null 2>&1

# install libraries (latest versions)
./arduino/arduino --install-library LedControl > /dev/null 2>&1

cd $currentWorkingDir