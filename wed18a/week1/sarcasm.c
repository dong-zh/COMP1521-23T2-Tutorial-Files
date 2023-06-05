// Sarcasises stuff
// Dongzhu Huang (z5257526)
// 23T2

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ./sarcasise 'hello world'

int main(int argc, char *argv[])
{
	// argument count
	// argc == 2
	// argv[0] == "./scarcaise"
	// argv[1] == "hello world"

	char *message = argv[1];

	if (argc != 2) {
		printf("Wrong number of args\n");
		return 1;
	}

	for (int i = 0; i < strlen(message); i++) {
		if (i % 2 == 0) {
			putchar(tolower(message[i]));
		} else {
			putchar(toupper(message[i]));
		}

	}
	putchar('\n');
}
