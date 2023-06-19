	.data
flag:
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

flag_pole:
	.asciiz	"|\n|\n|\n|\n|\n|\n|\n|\n"

# Constants
NUM_ROWS = 6
NUM_COLS = 12

	.text

# ------------------------------------------------------------------------------
#                                 Main Function
# ------------------------------------------------------------------------------
main:
main__prologue:
	begin
	push	$ra
main__body:
	jal	print_flag

	# print flag pole
	# syscall 4 (print string)
	li	$v0, 4
        la	$a0, flag_pole
	syscall

	li	$a0, 8
	jal     print_hill
main__epilogue:
	pop	$ra
	end
	jr	$ra
# ------------------------------------------------------------------------------
#                              Print Flag Function
# ------------------------------------------------------------------------------
print_flag:
print_flag__prologue:
	begin
	push	$ra
	push	$s0

print_flag__body:
	# row = $s0
print_flag__row_init:
	li	$s0, 0
print_flag__row_cond:
	bge	$s0, NUM_ROWS, print_flag__row_end
print_flag__row_body:
	move	$a0, $s0
	jal	print_row
	# Assume all $t and $a registers have been clobbered
print_flag__row_step:
	add	$s0, 1
	b	print_flag__row_cond
print_flag__row_end:
print_flag__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra
# ------------------------------------------------------------------------------
#                              Print Row Function
# ------------------------------------------------------------------------------
print_row:
print_row__prologue:
	# row = $t3
	# col = $t0
	# address calculation = $t1
	# flag[row][col] = $t2
	move	$t3, $a0
print_row__body:
print_row__col_init:
	li	$t0, 0
print_row__col_cond:
	bge	$t0, NUM_COLS, print_row__col_end
print_row__col_body:

	# address = base + sizeof(elem) * (i * NUM_COLS + j)
	# $t1 = i * NUM_COLS
	mul	$t1, $t3, NUM_COLS
	# $t1 += j
	add	$t1, $t0
	# sizeof(elem) is 1
	# mul	$t1, 1

	# $t2 = load from (base + (sizeof(elem) * (i * NUM_COLS + j)))
	lb	$t2, flag($t1)

	# Syscall 11 (putchar)
	move	$a0, $t2
	li	$v0, 11
	syscall

print_row__col_step:
	add	$t0, 1
	b	print_row__col_cond
print_row__col_end:
print_row__epilogue:
	# Syscall 11 (putchar)
	li	$a0, '\n'
	li	$v0, 11
	syscall

	jr	$ra
# ------------------------------------------------------------------------------
#                              Print Hill Function
# ------------------------------------------------------------------------------
print_hill:
	# $s0 = height
	# $t0 = i
print_hill__prologue:
	begin
	push	$ra
	push	$s0

	move	$s0, $a0
print_hill_body:

	# if (height <= 0) return;
	blez	$s0, print_hill__epilogue

	# $a0 = height - 1
	sub	$a0, $s0, 1
	# printHill(height - 1)
	jal	print_hill

print_hill__i_init:
	li	$t0, 0
print_hill__i_cond:
	bge	$t0, $s0, print_hill__i_end
print_hill__i_body:
	# syscall 11 (putchar)
	li	$v0, 11
	li	$a0, '*'
	syscall
print_hill__i_step:
	add	$t0, 1
	b	print_hill__i_cond
print_hill__i_end:
	# syscall 11 (putchar)
	li	$v0, 11
	li	$a0, '\n'
	syscall

print_hill__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra
