#!/bin/bash

if ! command -v wavpack &> /dev/null; then
    apt install -y wavpack
fi

clang -w src/main.c -o bin/main -lpthread -lm -ldl && cd bin && ./main
