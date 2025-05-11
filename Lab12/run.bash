#!/bin/bash

for file in $(find . -name "*.c"); do
    echo "Compiling $file"
    gcc -o "${file%.c}.out" "$file"
done

for exe in $(find . -name "*.out"); do
    echo "Running $exe"
    ./$exe >> "test.txt"
done
