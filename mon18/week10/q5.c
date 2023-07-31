#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

void *thread_run(void *data) {
	// Casting from a void * to a char *
	char *name = (char *)data;
	printf("Hello %s\n", name);
	sleep(1);
	return "This is a return value!";
}

int main(void) {
	pthread_t thread;
	int error = pthread_create(
		&thread,    // the pthread_t handle that will represent this thread
		NULL,       // thread-attributes -- we usually just leave this NULL
		thread_run, // the function that the thread should start executing
		"Dong"        // data we want to pass to the thread -- this will be
					// given in the `void *data` argument above
	);


	if (error) {
		errno = error;
		err(EXIT_FAILURE, "couldn't pthread_create");
	}

	// sleep(1);

	void *retVal;
	pthread_join(thread, &retVal);

	printf("Main is done\n");

	printf("retVal = %s\n", (char *)retVal);

	return 0;
}
