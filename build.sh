#!/usr/bin/env bash
set -e

mkdir -p build

cd build
echo "Cmake configuration"
cmake -DCMAKE_BUILD_TYPE=Release ..
echo "Compilation"
make -j6
