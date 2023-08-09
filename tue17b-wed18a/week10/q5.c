#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <stdlib.h>

void *sayHi(void *data)
{
	char *name = (char *)data;
	sleep(1);
	printf("Hello, %s\n", name);
	return "This is a return value! Yay!";
}

int main(void)
{
	pthread_t thread;
	int error;
	if ((error = pthread_create(&thread, NULL, sayHi, "Dong") != 0)) {
		errno = error;
		err(EXIT_FAILURE, "couldn't pthread_create");
	}


	void *retVal;
	if ((error = pthread_join(thread, &retVal)) != 0) {
		errno = error;
		err(EXIT_FAILURE, "couldn't pthread_join");
	}

	printf("MAIN: Done!\n");
	printf("Child returned %s\n", (char *)retVal);
}
