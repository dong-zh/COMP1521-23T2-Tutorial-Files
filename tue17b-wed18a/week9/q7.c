// Spawn the date program,

#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>
#include <unistd.h>

extern char **environ;

int main(void)
{

	pid_t pid;
	// argv[0] = /bin/date
	// argv[1] = +%d-%m-%Y
	char *argv[] = { "/bin/date", "+%d-%m-%Y", NULL };
	// Spawns the date program
	if (posix_spawn(&pid, argv[0], NULL, NULL, argv, environ) != 0) {
		err(EXIT_FAILURE, "couldn't posix spawn %s", argv[0]);
	}

	int returnCode;
	// Waits until the date program fully finishes
	waitpid(pid, &returnCode, 0);

	printf("%s returned %d\n", argv[0], returnCode);

	printf("Done\n");
}
