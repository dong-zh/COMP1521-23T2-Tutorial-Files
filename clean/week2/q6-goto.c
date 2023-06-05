// Prints whether a number is small/big or medium but using goto
// COMP1521 week 2 question 6
// Dongzhu Huang (z5257526)
// 23T2

#include <stdio.h>

int main(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);

	if (x > 100 && x < 1000) {
		printf("medium\n");
	} else {
		printf("small/big\n");
	}

	return 0;
}
