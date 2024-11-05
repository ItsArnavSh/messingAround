#!/bin/bash

# Check if the filename is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <filename_without_extension>"
  exit 1
fi

# Get the filename without extension
FILENAME="$1"

# Assemble the NASM file
echo "Assembling $FILENAME.asm..."
nasm -f elf64 "$FILENAME.asm" -o "$FILENAME.o"
if [ $? -ne 0 ]; then
  echo "Assembly failed."
  exit 1
fi

# Link the object file
echo "Linking $FILENAME.o..."
ld "$FILENAME.o" -o "$FILENAME"
if [ $? -ne 0 ]; then
  echo "Linking failed."
  exit 1
fi

# Run the executable
echo "Running $FILENAME..."
./"$FILENAME"
