#!/usr/bin/env sh
mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=$CGET_PREFIX/cget/cget.cmake ..
cd -
