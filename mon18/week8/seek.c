/**
 * @file seek.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the innocent text file
 * @date 22T1
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILENAME "sus.txt"
#define OFFSET (22)
#define WORD_LENGTH (8)

int main(void)
{
	FILE *file = fopen(FILENAME, "r");
	if (file == NULL) {
		err(EXIT_FAILURE, "failed to fopen");
	}

	fseek(file, -OFFSET, SEEK_END);

	for (int i = 0; i < WORD_LENGTH; i++) {
		putchar(fgetc(file));
	}
	putchar('\n');
}
