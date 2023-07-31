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
}
