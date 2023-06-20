# Header comment goes here

	.data
numbers:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9

	.text
main:
	# i = $t0
	# address calculation = $t1
	# numbers[i] = $t2

main__i_init:
	li	$t0, 0
main__i_cond:
	# if (i >= 10) goto main__i_end;
	bge	$t0, 10, main__i_end
main__i_body:
	# address of an element =
	# base address of array
	# + (index * size of each element)

	# if (numbers[i] >= 0)

	# index * sizeof element (4)
	mul	$t1, $t0, 4
	# Right now, $t1 holds the address numbers[i]
	# t1 = 0x1000
	# lw	<REGISTER>, <MEMORY ADDRESS>
	# add	$t1, $t1, numbers and load the value into $t2
	lw	$t2, numbers($t1)
	# t1 = 0x1000
	# t2 = numbers[i]

	# if (numbers[i] >= 0) goto main__if_positive;
	bgez	$t2, main__if_positive

main__if_negative:
	add	$t2, 42

	# put our new incremented number back into the array
	sw	$t2, numbers($t1)
main__if_positive:
main__i_step:
	add	$t0, 1
	b	main__i_cond

main__i_end:
	jr	$ra
