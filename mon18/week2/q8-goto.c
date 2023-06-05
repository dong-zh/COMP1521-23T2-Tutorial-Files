// Prints a triangle but using goto
// COMP1521 week 2 question 8
// Dongzhu Huang (z5257526)
// 23T2

#include <stdio.h>

int main(void)
{

main__i_init:;
	int i = 1;
main__i_cond:
	if (i > 10) goto main__i_end;
main__i_body:
main__j_init:;
	int j = 0;
main__j_cond:
	if (j >= i) goto main__j_end;
main__j_body:
	putchar('*');
main__j_step:
	j++;
	goto main__j_cond;
main__j_end:
	putchar('\n');
main__i_step:
	i++;
	goto main__i_cond;
main__i_end:

	return 0;


	// for (int i = 1; i <= 10; i++) {
	// 	// for (int j = 0; j < i; j++) {
	// 	// 	putchar('*');
	// 	// }
	// 	putchar('\n');
	// };
	// return 0;
}
