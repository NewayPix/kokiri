#!/bin/bash

# Yes I do have to prefix the directory of where to glob.
for i in ./src/3rd/glad/*.c; do
    echo $i
done
