#!/bin/bash

set -e

if [ -z "$1" ]; then
    echo "Usage: $0 <file.cpp>"
    exit 1
fi

if [[ "$1" == *.cpp ]]; then
    out="${1%.cpp}"
    g++ -std=c++17 -O2 -Wall "$1" -o "$out"

    if [ -f input.txt ]; then
        ./"$out" < input.txt
    else
        ./"$out"
    fi

    rm "$out"
else
    echo "Unsupported file"
    exit 1
fi