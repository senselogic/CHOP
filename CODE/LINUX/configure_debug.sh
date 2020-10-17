#!/bin/sh
set -x
./clean.sh
cmake -DCMAKE_BUILD_TYPE=Debug ..
