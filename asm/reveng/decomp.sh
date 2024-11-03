#!/bin/bash

# Check if a filename was provided as an argument
if [ -z "$1" ]; then
    echo "Error: No filename provided."
    echo "Usage: $0 <filename>"
    exit 1
fi

# Set the filename from the first argument
filename="$1"

# Compile the C file into an object file with specified options
gcc -fno-asynchronous-unwind-tables -s -c -o "${filename}.o" "${filename}.c"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Convert the object file to NASM assembly format
./objconv -fnasm "${filename}.o"

# Check if the conversion was successful
if [ $? -ne 0 ]; then
    echo "Object file conversion failed."
    exit 1
fi

# Remove the intermediate object file
rm "${filename}.o"

echo "Conversion complete for ${filename}.c"

echo "/*" >>  "${filename}.c"
cat "${filename}.asm" >> "${filename}.c"
rm "${filename}.asm"
