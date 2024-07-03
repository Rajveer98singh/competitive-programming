#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename_without_extension>"
    exit 1
fi

filename=$1

g++ -std=c++11 -o $filename $filename.cpp
if [ $? -eq 0 ]; then
    ./$filename
    rm $filename
else
    echo "Compilation failed."
fi
