# Header comment

	.data

prompt_str:
	.asciiz "Enter a number: "
medium_str:
	.asciiz "medium\n"
small_big_str:
	.asciiz "small/big\n"
	.text

main:
	# x = $t0

	# Print string syscall (code 4)
	# Put the number 4 into $v0
	li	$v0, 4
	la	$a0, prompt_str
	syscall

	# Read int syscall (code 5)
	li	$v0, 5
	syscall
	move	$t0, $v0

	ble	$t0, 100, main__x_small_big
	bge	$t0, 1000, main__x_small_big
main__x_medium:
	# Print string syscall (code 4)
	# Put the number 4 into $v0
	li	$v0, 4
	la	$a0, medium_str
	syscall
	b	main__x_end
main__x_small_big:
	# Print string syscall (code 4)
	# Put the number 4 into $v0
	li	$v0, 4
	la	$a0, small_big_str
	syscall
main__x_end:

	# return
	jr	$ra
