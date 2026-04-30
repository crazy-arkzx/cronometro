#!/bin/bash

if ! command -v sox &> /dev/null; then
    apt install -y sox
fi

if ! command -v wavpack &> /dev/null; then
    apt install -y wavpack
fi

clang -w src/main.c -o bin/main && cd bin && ./main
