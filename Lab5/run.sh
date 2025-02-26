#!/bin/bash

dir="$1"

# create the output dir for the testcases
if [ ! -d "output/$dir" ]; then
    mkdir -p "output/$dir"
fi

for f in "testcases/$dir"/*.txt; do
    filename=$(basename "$f")

    # create output file if it doesn't exist
    if [ ! -f "output/$dir/$filename" ]; then
        touch "output/$dir/$filename"
    fi

    ./"$dir.exe" < "$f" > "output/$dir/$filename"

    diff "output/$dir/$filename" "expected/$dir/$filename" > /dev/null

    if [ $? -eq 0 ]; then
        echo "$filename: PASSED ✅"
    else
        echo "$filename: FAILED 💀"
    fi
done
