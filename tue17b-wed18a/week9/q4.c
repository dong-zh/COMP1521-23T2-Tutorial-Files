#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>

void chmodIfPublicWritable(char *fileName);

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s <file1> [file2]\n", argv[0]);
		return EXIT_FAILURE;
	}
	// ./a.out file1.txt readme.md file2.txt

	for (int argIndex = 1; argIndex < argc; argIndex++) {
		chmodIfPublicWritable(argv[argIndex]);
	}
}


void chmodIfPublicWritable(char *fileName)
{
	// fileName = "hello.txt"
	struct stat fileStat;
	if (stat(fileName, &fileStat) == -1) {
		err(EXIT_FAILURE, "couldn't stat %s", fileName);
	}

	mode_t oldFileMode = fileStat.st_mode;

	if (oldFileMode & S_IWOTH) {
		// We need to change it to not public writable
		mode_t newFileMode = oldFileMode & ~S_IWOTH;

		// Actually apply the new permissions
		if (chmod(fileName, newFileMode) == -1) {
		err(EXIT_FAILURE, "couldn't chmod %s", fileName);
		}
		printf("Changed %s to not public writable\n", fileName);
	} else {
		// Nothing to do
		printf("Nothing to do for %s\n", fileName);
	}
}
