#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include "trie.h"

// TESTING
//

int main() {
	// size_t tn_size = sizeof(trieNode *);
	
	// TEST 1
	trieNode *node = malloc(sizeof(trieNode));
	node->letter = '@';
	node->numLetters = 0;
	node->followingLetters = malloc(sizeof(trieNode *) * 7);
	
	trieNode *a = malloc(sizeof(trieNode));
	a->letter = 'a';
	a->numLetters = 0;
	a->followingLetters = NULL;

	node->numLetters += 1;
	node->followingLetters[0] = a;

	trieNode *b = malloc(sizeof(trieNode));
	b->letter = 'b';
	b->numLetters = 0;
	b->followingLetters = NULL;

	node->numLetters += 1;
	node->followingLetters[1] = b;
	// printf("%c\n", node->followingLetters[1]->letter);

	assert(node->letter == '@');
	assert(a->letter == 'a');
	assert(b->letter == 'b');

	assert(node->numLetters == 2);
	assert(node->followingLetters[0]->letter == 'a');
	assert(node->followingLetters[1]->letter == 'b');

	printTrie(node);

}

