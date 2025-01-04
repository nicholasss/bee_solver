#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

trieNode *initTrie() {
	// Initialize with root of trie as '@'
	size_t trieSize = sizeof(trieNode);
	trieNode *trie = malloc(trieSize);
	if (trie == NULL) {
		// malloc failed
		printf("Malloc failed during Trie init.\n");
		exit(-1);
	}

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
	printf("{\n root:\n");
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

void freeTrie(trieNode **trie) {
	if (trie == NULL || *trie == NULL) {
		// printf("Trie was null. Returning.\n");
		return; 
	} else if ((*trie)->followingLetters == NULL) {
		// printf("Trie's 'followingLetters' is null. Returning.\n");
		return;
	}

	for (int i = 0; i < 7; i++) {
		// look through 7 nodes attached to root
		if ((*trie)->followingLetters[i] == NULL) {
			// printf("Trie's %d following letter was null. Continuing.\n", i);
			continue;
		}
		
		r_freeTrie(&((*trie)->followingLetters[i]), (*trie)->numLetters);
	}

	// printf("Trie's graph was cleared.\n");
	free((*trie)->followingLetters);
	(*trie)->followingLetters = NULL;

	free(*trie);
	*trie = NULL;
	// printf("Trie was fully freed.\n");
}

void r_freeTrie(trieNode **node, int numLetters) {
	if (node == NULL || *node == NULL) {
		return;
	}
	// printf("Looking at '%c'.\n", (*node)->letter);

	if ((*node)->numLetters == 0) {
		// printf("Freeing '%c' final letter in sequence.\n", node->letter);
		freeNode(node);
		return;
	}

	for (int i = 0; i < numLetters; i++) {
		if ((*node)->followingLetters == NULL) {
			break; // break instead of return
		}

		if ((*node)->followingLetters[i] == NULL) {
			break; // break instead of return
		} 
		
		// printf("Looking at '%c's %d letter.\n", node->letter, i);
		r_freeTrie(&((*node)->followingLetters[i]), (*node)->numLetters);
	}

	freeNode(node);
}

void freeNode(trieNode **node) {
	// printf("Finally freeing '%c'.\n", (*node)->letter);
	if (node == NULL || *node == NULL) {
		return;
	}

	if ((*node)->followingLetters == NULL) {
		free(*node);
		*node = NULL;
		return;
	}

	free((*node)->followingLetters);
	(*node)->followingLetters = NULL;
	
	free(*node);
	*node = NULL;
}

trieNode *addTrieLetter(char letter, trieNode *onNode) {
	if (onNode == NULL) {
		return NULL;
	}

	int num;
	if (onNode != NULL) {
		num = onNode->numLetters;
	} else {
		num = 0;
	}

	if (num > 7) {
		printf("unable to add after the 7th letter\n");
		return NULL;
	}

	// check if followingLetters array is initialized
	if (onNode->followingLetters == NULL) {
		onNode->followingLetters = malloc(sizeof(trieNode *) * 7);
		if (onNode->followingLetters == NULL) {
			printf("Malloc failed for argument onNode's following letters.\n");
			exit(-1);
		}
	}

	trieNode *newNode = NULL;
	if (onNode->followingLetters[num] == NULL) {
		// num will always be the index for a new item
		newNode = malloc(sizeof(trieNode));
		if (newNode == NULL) {
			printf("Malloc failed for newNode\n");
			exit(-1);
		}
		newNode->followingLetters = malloc(sizeof(trieNode *) * 7);
		if (newNode->followingLetters == NULL) {
			printf("Malloc failed for following letters of newNode\n");
			exit(-1);
		}

		// setting values after initializing
		newNode->letter = letter;
		newNode->numLetters = 0;

		// update onNode after adding
		onNode->followingLetters[num] = newNode;
		onNode->numLetters++;
	}

	return newNode;
}
