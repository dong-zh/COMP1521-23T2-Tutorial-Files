#include <stdio.h>
#include <stdint.h>


int main(void)
{
#define int int16_t

	int answer = 30000 + 30000;
	printf("Answer is %d\n", answer);

#undef int
}
