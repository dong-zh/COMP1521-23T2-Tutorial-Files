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

	char *homePath = getenv("HOME");
	if (homePath == NULL) {
		fprintf(stderr, "couldn't get $HOME\n");
		return EXIT_FAILURE;
	}
	char *fileName = argv[1];
	// homePath = "/home/dong"
	// fileName = "hello.txt"


	// filePath = "/home/dong/hello.txt"

	int pathLength = strlen(homePath) + strlen(fileName) + 2;
	char fullPath[pathLength];
	snprintf(fullPath, pathLength, "%s/%s", homePath, fileName);

	FILE *file = fopen(fullPath, "w");
	if (file == NULL) {
		err(EXIT_FAILURE, "couldn't create %s", fullPath);
	}


	fclose(file);

}
