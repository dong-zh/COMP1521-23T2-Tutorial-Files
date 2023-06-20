int main(void)
{
	int i;
	int numbers[10] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};
main__i_init:
	i = 0;
main__i_cond:
	if (i >= 10) goto main__i_end;
main__i_body:

	if (numbers[i] >= 0) goto main__if_positive;
main__if_negative:
	numbers[i] += 42;
main__if_positive:
main__i_step:
	i++;
	goto main__i_cond;
main__i_end:

	// while (i < 10) {
	// 	if (numbers[i] < 0) {
	// 		numbers[i] += 42;
	// 	}
	// 	i++;
	// }
	// numbers = {0, 1, 2, 39, 4, 37, 6, 35, 8, 9}
}
