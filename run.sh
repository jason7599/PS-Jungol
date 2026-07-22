#!/bin/bash 
set -e 
if [[ "$1" == *.cpp ]]; then
    g++ -std=c++17 -O2 -Wall \
    -Wno-sign-compare \
    -Wno-unused-parameter \
    -Wno-missing-field-initializers \
    "$1" -o a.out
else 
    echo "Unsupported file"
    exit 1 
fi

./a.out
rm a.out