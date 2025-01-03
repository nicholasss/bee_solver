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
	
	trieNode *s = malloc(sizeof(trieNode));
	s->letter = 's';
	s->numLetters = 0;
	s->followingLetters = NULL;

	a->numLetters++;
	a->followingLetters = malloc(sizeof(trieNode *) * 7);
	a->followingLetters[0] = s;

	trieNode *b = malloc(sizeof(trieNode));
	b->letter = 'b';
	b->numLetters = 0;
	b->followingLetters = NULL;

	node->numLetters += 1;
	node->followingLetters[1] = b;

	assert(node->letter == '@');
	assert(a->letter == 'a');
	assert(b->letter == 'b');

	assert(node->numLetters == 2);
	assert(node->followingLetters[0]->letter == 'a');
	assert(node->followingLetters[0]->followingLetters[0]->letter == 's');
	assert(node->followingLetters[1]->letter == 'b');

	printTrie(node);

}

