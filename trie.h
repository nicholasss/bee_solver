#ifndef TRIE
#define TRIE

typedef struct trieNode trieNode;

// Structures Definitions
struct trieNode {
	char letter;
	int numLetters;
	trieNode **followingLetters;
};

// Function Signatures
trieNode *initTrie();
void printTrie(trieNode *trie);
void r_printTrie(trieNode *node, int numLetters, int level);
void freeTrie(trieNode **trie);
void r_freeTrie(trieNode **node, int numLetters);
void freeNode(trieNode **node);
trieNode *addTrieLetter(char letter, trieNode *onNode);

#endif
