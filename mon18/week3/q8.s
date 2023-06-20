	.data
numbers:
	.word	0, 1, 2, 3, 4, 5, 6, 7, 8, 9

	.text
main:

	# i = $t0
	# temp working out = $t9
	# address calculation = $t1
	# numbers[9 - i] = $t2

	# int y = numbers[9 - i]
	# address = base + (index * sizeof element)

	# $t9 = 9 - i
	sub	$t9, 9, $t0
	# $t1 = (9 - i) * sizeof element
	mul	$t1, $t9, 4

	# load word from numbers[9 - i]
	lw	$t2, numbers($t1)
