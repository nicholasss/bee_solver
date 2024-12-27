#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Signatures
typedef struct trieNode trieNode;

// Structures Definitions
struct trieNode {
	char letter;
	int numLetters;
	trieNode *followingLetters;
};

// Function Signatures
void printHelp();
int uniqueLetters(int strlen, char *letters);
trieNode *initTrie();
void printTrie(trieNode *trie);
void r_printTrie(trieNode *node, int numLetters);
void freeTrie(trieNode *trie);
void r_freeTrie(trieNode *node, int numLetters);
void addTrieLetter(char letter, trieNode *onNode);

// Function definitions
void printHelp() {
	printf(" This program solves the spelling bee.\n");
	printf(" Please provide the letters for searching.\n");
	printf(" i.e. 'abcdef'\n");
	printf(" Written by Nicholas Zingleman\n");
}

int uniqueLetters(int len, char *letters) {
	if (len < 1 || len > 7) {
		printf("Please check the number of letters once more.\n");
		return 0; // false
	} 
	if (letters == NULL) {
		// not sure letters will ever be null, but doesnt hurt to check.
		printf("Unable to check letters, null pointer.\n");
		return 0; // false
	}

	// compare each and every letter
	int unique = 1;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i == j) {
				// comparing the same letter skips to next loop
				continue;
			} else if (letters[i] == letters[j]) {
				// printf(" FOUND: letter %c and %c are the same.\n", letters[i], letters[j]);
				unique = 0; // set to false
			}
		}
	}
	
	return unique;
}

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

	printf("{\n %c:\n [", trie->letter);
	for (int i = 0; i < trie->numLetters; i++) {
		r_printTrie(trie->followingLetters + i, trie->numLetters + i);
	}
}

void r_printTrie(trieNode *node, int numLetters) {
	// TODO: TEST
	// prints the trie recursively

	for (int i = 0; i < numLetters; i++) {
		if (node->followingLetters + i == NULL) {
			continue;
		} else if (node->numLetters == 0) {
			printf("letter \n");
		} else {
			r_printTrie(node->followingLetters, node->numLetters);
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
		if (trie->followingLetters + i == NULL) {
			continue;
		}
		
		r_freeTrie(trie->followingLetters, trie->numLetters);
	}
}

void r_freeTrie(trieNode *node, int numLetters) {
	// TODO: TEST
	// is called recursively to free the nodes

	for (int i = 0; i < numLetters; i++) {
		if (node->followingLetters + i == NULL) {
			continue;
		} else if (node->numLetters == 0) {
			free(node);
		} else {
			r_freeTrie(node->followingLetters, node->numLetters);
		}
	}
}

void addTrieLetter(char letter, trieNode *onNode) {
	
}

// Main Function
int main(int argc, char **argv) {
	char *wordPath = "/usr/share/dict/words";
	FILE *wordsFile = fopen(wordPath, "r");

	char *arg = argv[1];

	if (argc > 2) {
		printf(" ERROR: Please only provide one argument!\n i.e. 'abcdef'\n Type help for more information\n");
		exit(-1);
	} else if (argc == 1) {
		printf(" ERROR: Please provide the letters to be used.\n i.e. 'abcdef'\n Type help for more information\n");
		exit(-1);
	} else {

		// one argument was provided
		size_t argLength = strlen(arg);
		if (strncmp(arg, "help", argLength) == 0) { // enter if same word
			printHelp();
			exit(1);
		} else if (argLength != 7) {
			printf(" ERROR: Please provide 7 letters.\n");
			exit(-1);
		} else if (uniqueLetters(argLength, arg) == 0) { // enter if false
			printf(" ERROR: Please provide 7 unique letters.\n");
			exit(-1);
		} else {
			printf(" ### Letters provided %s\n", arg);
		}
	}
	
	printf(" ### Proceeding to program...\n");

	// reading from word file
	size_t lineBufferSize = 16; // words should be under 16
	char *lineBuffer = malloc(lineBufferSize);
	
	int count = 1;
	while(fgets(lineBuffer, lineBufferSize, wordsFile)) {
		// printf("word %d: %s", count, lineBuffer);
		// count += 1;
	}

	// free(buffer);
	return 0;
}
