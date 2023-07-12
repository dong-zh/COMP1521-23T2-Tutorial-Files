#include <stdio.h>
#include <stdint.h>


int main(void)
{
#define int double

	int answer = 30000 + 30000;
	printf("Answer is %f\n", answer);

#undef int
}
