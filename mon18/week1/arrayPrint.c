// Prints 10 numbers in an array
// Dongzhu Huang
// 23T2

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (10)

// void printArray( ??? );
void printArrayR(int array[], int i);

int main(void)
{
	// Numbers to print
	int numbers[ARRAY_LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	printArrayR(numbers, 0);


}

void printArrayR(int array[], int i)
{
	// Terminating case (when do we stop calling ourselves)
	if (i == ARRAY_LENGTH) {
		return;
	}


	// Recursive call
	printArrayR(array, i + 1);

	// Work
	printf("%d\n", array[i]);
}
