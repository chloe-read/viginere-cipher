#!/bin/bash

ls
gcc -o ViginereCipherInator ./ViginereCipherInator.c


if [ $? -eq 0 ]; then
  ./ViginereCipherInator
else
  echo "Compilation failed. Check your C code for errors."
fi
