#!/usr/bin/env bash
set -e

PROJ_PATH="$(dirname $0)"
PROJ_PATH="$( cd $PROJ_PATH && pwd )"

mkdir -p "$PROJ_PATH/build"

cd "$PROJ_PATH/build"
echo "Cmake configuration"
cmake -DCMAKE_BUILD_TYPE=Release ..
echo "Compilation"
make -j6
mv composite ../
