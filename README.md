# How to use
The only file you need to build `./words.c` is itself.
Have clang/gcc output the executible and run it with an argument of seven letters.
See below for examples:
```sh
./words.o abcdefg
./words.o aeiouyn
./words.o monacry
./words.o tiopale
```

# Why is there a trie.c?
I had thought the solution would require a trie data structure. However, once I completed the whole thing, it ended up not needing it after all.

The lesson learned from this is to not have a solution in search of a problem.
