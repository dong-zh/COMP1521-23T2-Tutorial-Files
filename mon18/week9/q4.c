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

	for (int i = 1; i < argc; i++) {
		chmodIfPublicWritable(argv[i]);
	}
}


void chmodIfPublicWritable(char *fileName)
{
	struct stat fileStat;
	if (stat(fileName, &fileStat) == -1) {
		err(EXIT_FAILURE, "failed to stat %s\n", fileName);
	}

	mode_t oldMode = fileStat.st_mode;

	if (oldMode & S_IWOTH) {
		// We need to unset public writable
		mode_t newMode = oldMode & ~S_IWOTH;
		chmod(fileName, newMode);
		printf("Changed %s to not public writable\n", fileName);
	} else {
		// Nothing to do
		printf("Nothing to do for %s\n", fileName);
	}
}
