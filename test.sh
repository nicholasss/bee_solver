#!/bin/bash

rm "~/Developer/Projects/spelling_bee/test.o"
clang trie.c test.c -Wall -Wextra -std=c99 -g -O0 -o test.o
~/Developer/Projects/spelling_bee/test.o
