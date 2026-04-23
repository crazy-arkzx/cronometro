#!/bin/bash

if ! command -v sox &> /dev/null; then
    sudo apt install -y sox
fi

if ! command -v wavpack &> /dev/null; then
    sudo apt install -y wavpack
fi

if ! command -v gcc &> /dev/null; then
    sudo apt install -y gcc
fi

gcc -o main main.c && ./main