// Sarcasises stuff
// Dongzhu Huang (z5257526)
// 23T2

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		printf("Usage: ./sarcasm [your string]\n");
		return 1;
	}
	char *message = argv[1];

	for (int i = 0; i < strlen(message); i++) {
		if (i % 2 == 0) {
			putchar(tolower(message[i]));
		} else {
			putchar(toupper(message[i]));
		}
	}
	putchar('\n');


}
