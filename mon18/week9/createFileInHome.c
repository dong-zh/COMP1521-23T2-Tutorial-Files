/**
 * @file createFileInHome.c
 * @author Dongzhu Huang (z5257526)
 * @brief Create a file with the argument as the filename in the home directory.
 * @date 23T2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *homeDir = getenv("HOME");
	// homeDir = "/import/kamen/4/z5257526"
	// argv[1] = "hello.txt"
	if (homeDir == NULL) {
		fprintf(stderr, "Can't get $HOME\n");
		return EXIT_FAILURE;
	}


	// +1 for the slash, +1 for the '\0'
	int length = strlen(homeDir) + strlen(argv[1]) + 2;
	char filePath[length];
	snprintf(filePath, length, "%s/%s", homeDir, argv[1]);

	FILE *file = fopen(filePath, "w");
	if (file == NULL) {
		err(EXIT_FAILURE, "failed to create %s", filePath);
	}

	fclose(file);
}
