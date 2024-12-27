#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHelp();

void printHelp() {
	printf(" This program solves the spelling bee.\n");
	printf(" Please provide the letters for searching.\n");
	printf(" i.e. 'abcdef'\n");
	printf(" Written by Nicholas Zingleman\n");
}

int main(int argc, char **argv) {
	char *wordPath = "/usr/share/dict/words";
	FILE *wordsFile = fopen(wordPath, "r");

	if (argc > 2) {
		printf(" Please only provide one argument!\n i.e. 'abcdef'\n Type help for more information\n");
		exit(-1);
	} else if (argc == 1) {
		printf(" Please provide the letters to be used.\n i.e. 'abcdef'\n Type help for more information\n");
		exit(-1);
	} else {
		// one argument was provided
		char *arg = argv[1];
		size_t argLength = strlen(arg);
		if (strncmp(arg, "help", argLength) == 0) {
			printHelp();
			exit(1);
		} else if (argLength != 7) {
			printf("Please provide 7 letters.\n");
		} else {
			printf("Arguments provided %s\n", arg);
			
		}
	}
	
	printf("Proceeding to program...\n");

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
