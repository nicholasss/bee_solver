#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "words.h"
// #include "trie.h"


// Function definitions
void printHelp() {
	printf(" This program solves the spelling bee.\n");
	printf(" Please provide the letters for searching.\n");
	printf(" i.e. 'abcdef'\n");
	printf(" Written by Nicholas Zingleman\n");
}

bool checkLettersInWord(char *letters, char *word) {
	int wordLen = strlen(word);
	if (wordLen < 4) {
		return false;
	}

	for (int i = 0; i < wordLen; i++) {
		bool match = false;
		for (int j = 0; j < 7; j++) {
			// for each letter provided (spelling bee)
			// if the (word) letter does not match a (bee) letter
			// then return false
			if (word[i] == letters[j]) {
				match = true;
			}
		}
		
		if (match == false) {
			// printf("%s not a match due to %c.\n", word, word[i]);
			return false;
		}
	}

	return true;
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

// Main Function
int main(int argc, char **argv) {
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

	char *wordPath = "./words_alpha.txt";
	FILE *wordsFile = fopen(wordPath, "r");

	// reading from word file
	size_t lineBufferSize = 32; // words should be under 16
	char *wordBuffer = malloc(lineBufferSize);

	while(fgets(wordBuffer, lineBufferSize, wordsFile)) {
		// removing newlines from lineBuffer
		wordBuffer[strcspn(wordBuffer, "\n\r")] = 0;

		bool valid = checkLettersInWord(arg, wordBuffer);
		if (valid) {
			printf("%s\n", wordBuffer);
		}

	}

	free(wordBuffer);
	return 0;
}
