/**
 * @file seek.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the innocent text file
 * @date 23T2
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILE_NAME "innocentTextFile.txt"
#define OFFSET (22)
#define WORD_LENGTH (8)

int main(void)
{
	FILE *file = fopen(FILE_NAME, "r");
	if (file == NULL) {
		// Something's gone wrong
		err(EXIT_FAILURE, "can't fopen %s", FILE_NAME);
	}

	fseek(file, -OFFSET, SEEK_END);

	for (int i = 0; i < WORD_LENGTH; i++) {
		putchar(fgetc(file));
	}
	putchar('\n');
}
