#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename_without_extension>"
    exit 1
fi

filename=$1
base_dir="$(dirname "$0")"
header_dir="$base_dir/../headers"
data_structures_dir="$base_dir/../i-structures"

# Collect all .cpp files in the data-struct directory
data_structures_files=$(find "$data_structures_dir" -name '*.cpp')

# Compile the target file along with all data structure files
g++ -std=c++11 -I"$header_dir" -o "$filename" "$filename.cpp" $data_structures_files
if [ $? -eq 0 ]; then
    ./"$filename"
    rm "$filename"
else
    echo "Compilation failed."
fi

# '../scripts/runCode.sh example' to run the code in library-use directory and example.cpp must belong to the library-use directory
