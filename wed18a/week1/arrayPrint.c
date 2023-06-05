// Prints 10 numbers in an array
// 23T2
// Dongzhu Huang

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (10 + 1)

void printArrayR(int numbers[], int i);

int main(void)
{
	// Numbers to print
	int numbers[ARRAY_LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	printArrayR(numbers, 0);
	// for (int i = 0; i < ARRAY_LENGTH; i++) {
	// 	printf("%d\n", numbers[i]);
	// }

	int x = 10 + 1 * 5;
}

void printArrayR(int numbers[], int i)
{
	// Terminating case
	if (i >= ARRAY_LENGTH) {
		return;
	}

	// Recursive call
	printArrayR(numbers, i + 1);

	// Work
	printf("%d\n", numbers[i]);

}
