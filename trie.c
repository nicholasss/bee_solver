#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

trieNode *initTrie() {
	// Initialize with root of trie as '@'
	size_t trieSize = sizeof(trieNode);
	trieNode *trie = malloc(trieSize);

	trie->letter = '@';
	trie->numLetters = 0;
	trie->followingLetters = malloc(sizeof(trieNode *) * 7);
	return trie;
}

void printTrie(trieNode *trie) {
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
	} else if (trie->followingLetters == NULL) {
		return;
	}

	for (int i = 0; i < 7; i++) {
		// look through 7 nodes attached to root
		if (trie->followingLetters[i] == NULL) {
			continue;
		}
		
		r_freeTrie(trie->followingLetters[i], trie->numLetters);
	}

	free(trie->followingLetters);
	trie->followingLetters = NULL;
	free(trie);
	trie = NULL;
}

void r_freeTrie(trieNode *node, int numLetters) {
	// TODO: TEST
	if (node == NULL) {
		return;
	}

	if (node->numLetters == 0) {
		freeNode(node);
		return;
	}

	for (int i = 0; i < numLetters; i++) {
		if (node->followingLetters == NULL) {
			continue;
		}

		if (node->followingLetters[i] == NULL) {
			continue;
		} 
		
		r_freeTrie(node->followingLetters[i], node->numLetters);
	}

	freeNode(node);
}

void freeNode(trieNode *node) {
	if (node == NULL) {
		return;
	}

	if (node->followingLetters == NULL) {
		free(node);
		node = NULL;
		return;
	}

	free(node->followingLetters);
	node->followingLetters = NULL;
	
	free(node);
	node = NULL;
}

trieNode *addTrieLetter(char letter, trieNode *onNode) {
	int num = onNode->numLetters;
	if (num > 7) {
		printf("unable to add after the 7th letter\n");
		return NULL;
	}

	// check if followingLetters array is initialized
	if (onNode->followingLetters == NULL) {
		onNode->followingLetters = malloc(sizeof(trieNode *) * 7);
	}

	trieNode *newNode = NULL;
	if (onNode->followingLetters[num] == NULL) {
		// num will always be the index for a new item
		newNode = malloc(sizeof(trieNode));
		newNode->followingLetters = malloc(sizeof(trieNode *) * 7);

		// setting values after initializing
		newNode->letter = letter;
		newNode->numLetters = 0;

		// update onNode after adding
		onNode->followingLetters[num] = newNode;
		onNode->numLetters++;
	}

	return newNode;
}
