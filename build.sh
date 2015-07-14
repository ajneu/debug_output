#!/usr/bin/env bash

mkdir -p build
cd build

while true; do
    read -p "Debug (d) or Release (r) build ? -> " BUILD_TYPE
    BUILD_TYPE=${BUILD_TYPE^^} # to upper case
    if   [[ $BUILD_TYPE == D ]]; then
        FLAG="-DCMAKE_BUILD_TYPE=Debug"
        break
    elif [[ $BUILD_TYPE == R ]]; then
        FLAG="-DCMAKE_BUILD_TYPE=Release"
        break
    fi
done

echo
echo "calling cmake like this..."
echo "cmake $FLAG .."
cmake $FLAG ..
make

echo
echo "starting program ./go ..."
./go
