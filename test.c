#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include "trie.h"

// TESTING
//

int main() {
	trieNode *root = initTrie();

	trieNode *a = addTrieLetter('a', root);
	trieNode *s = addTrieLetter('s', a);

	trieNode *b = addTrieLetter('b', root);
	trieNode *e = addTrieLetter('e', b);
	trieNode *h = addTrieLetter('h', e);
	trieNode *a1 = addTrieLetter('a', h);
	trieNode *v = addTrieLetter('v', a1);
	trieNode *e1 = addTrieLetter('e', v);

	assert(root->letter == '@');
	assert(a->letter == 'a');
	assert(b->letter == 'b');

	assert(root->numLetters == 2);
	assert(root->followingLetters[0]->letter == 'a');
	assert(root->followingLetters[0]->followingLetters[0]->letter == 's');
	assert(root->followingLetters[1]->letter == 'b');

	printTrie(root);

	// testing freeing the trie
	freeTrie(root);
	assert(root == NULL);

}

