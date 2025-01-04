!#/bin/bash

rm "~/Developer/Projects/spelling_bee/words.o"
clang words.c -Wall -Wextra -std=c99 -g -O0 -o words.o
~/Developer/Projects/spelling_bee/words.o $1
