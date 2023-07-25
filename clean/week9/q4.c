#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>

void chmodIfPublicWritable(char *filename);

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s <file1> [file2]\n", argv[0]);
		return EXIT_FAILURE;
	}
}


void chmodIfPublicWritable(char *filename)
{
}
