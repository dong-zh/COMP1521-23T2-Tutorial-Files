// Prints a triangle but using goto
// COMP1521 week 2 question 8
// Dongzhu Huang (z5257526)
// 23T2

#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			putchar('*');
		}
		putchar('\n');
	};
	return 0;
}
