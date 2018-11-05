#!/usr/bin/env sh
sudo apt install build-essential g++ clang cmake

gcc --version
clang --version

git clone https://github.com/Dobiasd/FunctionalPlus
cd FunctionalPlus
mkdir build
cd build
cmake ..
sudo make install -j

