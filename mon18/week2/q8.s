
	.data
	.text
main:
	# i = $t0
	# j = $t1
main__i_init:
	li	$t0, 1
main__i_cond:
	bgt	$t0, 10, main__i_end
main__i_body:
main__j_init:
	li	$t1, 0
main__j_cond:
	bge	$t1, $t0, main__j_end
main__j_body:
	# put char syscall (code 11)
	li	$v0, 11
	li	$a0, '*'
	syscall
main__j_step:
	# j = j + 1
	add	$t1, $t1, 1
	b	main__j_cond;
main__j_end:
	# put char syscall (code 11)
	li	$v0, 11
	li	$a0, '\n'
	syscall

main__i_step:
	# i = i + 1
	add	$t0, $t0, 1
	b	main__i_cond
main__i_end:

	li	$v0, 0
	jr	$ra
