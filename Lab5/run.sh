#!/bin/bash

dir="$1"

green='\033[0;32m'
resetCol='\033[0m'
red='\033[0;31m'

# create the output dir for the testcases
if [ ! -d "output/$dir" ]; then
    mkdir -p "output/$dir"
fi

# Check operating system
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Give permission to execute the program

    chmod +x "./$dir"
    program="./$dir"
else
    program="./$dir.exe"
fi

for f in testcases/"$dir"/*.txt; do
    filename=$(basename "$f")
    # create output file if it doesn't exist
    if [ ! -f "output/$dir/$filename" ]; then
        touch "output/$dir/$filename"
    fi

    # Convert input file to Unix line endings if on Linux
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        dos2unix "$f" 2>/dev/null || true
    fi

    "$program" < "$f" > "output/$dir/$filename"

    # Convert output and expected files to Unix line endings if on Linux
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        dos2unix "output/$dir/$filename" 2>/dev/null || true
        dos2unix "expected/$dir/$filename" 2>/dev/null || true
    fi

    diff "output/$dir/$filename" "expected/$dir/$filename" > /dev/null

    if [ $? -eq 0 ]; then
        echo -e "$filename:$green PASSED$resetCol ✅"
    else
        echo -e "$filename:$red FAILED$resetCol ❌"
    fi
done
