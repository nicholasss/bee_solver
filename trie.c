#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

trieNode *initTrie() {
	// Initialize with root of trie as '@'
	size_t trieSize = sizeof(trieNode);
	trieNode *trie = malloc(trieSize);
	trie->letter = '@';
	return trie;
}

void printTrie(trieNode *trie) {
	// TODO: TEST
	// prints tree
	if (trie == NULL) {
		return;
	}

	int level = 1;
	printf("{ root:\n");
	for (int i = 0; i < trie->numLetters; i++) {
		r_printTrie(trie->followingLetters[i], trie->numLetters + i, level);
	}
	printf("}\n");
}

void r_printTrie(trieNode *node, int numLetters, int level) {
	// TODO: TEST
	// prints the trie recursively
	if (node == NULL) {
		return;
	}
	

	level += 2;
	int spaces = level;
	while(spaces > 0) {
		printf(" ");
		spaces -= 1;
	}
	printf("%c\n", node->letter);

	for (int i = 0; i < numLetters; i++) {
		if (node->followingLetters == NULL) {
			continue;
		} else {
			r_printTrie(node->followingLetters[i], node->numLetters, level);
		}
	}
}

void freeTrie(trieNode *trie) {
	// TODO: TEST
	// Up to seven nodes under root, then undetermined branches
	if (trie == NULL) {
		return; 
	}

	for (int i = 0; i < 7; i++) {
		// look through 7 nodes attached to root
		if (trie->followingLetters[i] == NULL) {
			continue;
		}
		
		r_freeTrie(trie->followingLetters[i], trie->numLetters);
	}
}

void r_freeTrie(trieNode *node, int numLetters) {
	// TODO: TEST
	// is called recursively to free the nodes

	for (int i = 0; i < numLetters; i++) {
		if (node->followingLetters[i] == NULL) {
			continue;
		} else if (node->numLetters == 0) {
			free(node);
		} else {
			r_freeTrie(node->followingLetters[i], node->numLetters);
		}
	}
}

void addTrieLetter(char letter, trieNode *onNode) {
	
}
