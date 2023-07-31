#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

void *sayWorld(void *data)
{
	while (1) {
		printf("world\n");
		sleep(2);
	}

	return NULL;
}

int main(void)
{
	pthread_t thread;

	int error = pthread_create(&thread, NULL, sayWorld, NULL);

	if (error != 0) {
		errno = error;
		err(EXIT_FAILURE, "couldn't pthread_create");
	}

	while (1) {
		printf("hello\n");
		sleep(1);
	}

	// sayWorld();


}
