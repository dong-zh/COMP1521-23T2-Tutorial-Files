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


	if (x <= 100) goto main__x_small_big;
	if (x >= 1000) goto main__x_small_big;
main__x_medium:
	printf("medium\n");
	goto main__x_end;
main__x_small_big:
	printf("small/big\n");
main__x_end:


	return 0;

// 	if (x > 100 && x < 1000)
// 		printf("medium\n");

// 		printf("small/big\n");


// 	return 0;
}
