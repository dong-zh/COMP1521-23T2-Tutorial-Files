/**
 * @file sarcasm2.c
 * @author Dongzhu Huang
 * @brief Reads a text file and outputs a sarcastic version of it
 * @date 23T2
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <err.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
	// a.out input.txt output.txt

	// Arg check
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *input_file_name = argv[1]; // "input.txt"
	char *output_file_name = argv[2]; // "output.txt"

	FILE *input_file = fopen(input_file_name, "r");
	if (input_file == NULL) {
		// Something's gone wrong
		err(EXIT_FAILURE, "Failed to fopen");
	}

	FILE *output_file = fopen(output_file_name, "w");
	if (output_file == NULL) {
		// Something's gone wrong
		err(EXIT_FAILURE, "Failed to fopen");
	}

	bool shouldCapitalise = false;
	int c;
	while ((c = fgetc(input_file)) != EOF) {
		if (shouldCapitalise) {
			fputc(toupper(c), output_file);
		} else {
			fputc(tolower(c), output_file);
		}
		shouldCapitalise = !shouldCapitalise;
	}

	fclose(input_file);
	fclose(output_file);
}
