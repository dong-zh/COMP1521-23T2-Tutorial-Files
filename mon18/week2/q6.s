	.data
prompt_str:
	.asciiz "Enter a number: "
medium_str:
	.asciiz "medium\n"
small_big_str:
	.asciiz "small/big\n"
	.text

main:
	# x = t0

	# Print string syscall (code 4)
	li	$v0, 4
	# Put the char * into $a0
	la	$a0, prompt_str
	syscall

	# Scan int syscall (code 5)
	li	$v0, 5
	syscall
	move	$t0, $v0

	# if (x <= 100) goto main__x_small_big;
	ble	$t0, 100, main__x_small_big
	bge	$t0, 1000, main__x_small_big
main__x_medium:
	# Print string syscall (code 4)
	li	$v0, 4
	# Put the char * into $a0
	la	$a0, medium_str
	syscall
	b	main__x_end
main__x_small_big:
	# Print string syscall (code 4)
	li	$v0, 4
	# Put the char * into $a0
	la	$a0, small_big_str
	syscall
main__x_end:

	li	$v0, 0
	jr	$ra
