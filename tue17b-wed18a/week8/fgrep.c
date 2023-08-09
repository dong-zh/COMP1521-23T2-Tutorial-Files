#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH (65535)

void findString(char *target, FILE *file, char *fileName);
int main(int argc, char *argv[])
{
	// Arg check
	if (argc < 2) {
		errx(EXIT_FAILURE, "Usage: %s <string to find> [files]\n", argv[0]);
	} else if (argc == 2) {
		// ./a.out hello
		findString(argv[1], stdin, "stdin");
	} else if (argc > 2) {
		// ./a.out hello file1.txt file2.txt file3.txt
		for (int i = 2; i < argc; i++) {
			FILE *file = fopen(argv[i], "r");
			findString(argv[1], file, argv[i]);
			fclose(file);

		}
	}

	// fgets is for strings
	// char arr = [ 'h', 'i', '\0' ];
	// fgetc is for reading bytes
}

void findString(char *target, FILE *file, char *fileName)
{
	// target == hello, fileName == file1.txt

	// 1. Open the file
	// 2. read/write to the file
	// 3. close the file

	if (file == NULL) {
		// Something's gone wrong
		err(EXIT_FAILURE, "failed to fopen %s", fileName);

	}

	char currentLine[MAX_LINE_LENGTH];

	for (unsigned lineCounter = 1; fgets(currentLine, MAX_LINE_LENGTH, file) != NULL; lineCounter++) {
		if (strstr(currentLine, target) != NULL) {
			// target has been found!
			printf("%s:%d %s\n", fileName, lineCounter, currentLine);
		}
	}

}
