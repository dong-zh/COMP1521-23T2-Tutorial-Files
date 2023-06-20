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
	# printFlag()

	li	$s0, 42

	jal	print_flag

	# s0 must still be 42 at this point (because convention)

	# syscall 4 (print string)
	li	$v0, 4
	la	$a0, flag_pole
	syscall

	# printHill(8)
	li	$a0, 8
	jal	print_hill
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
print_flag__row_init:
	# $s0 = row
	li	$s0, 0
print_flag__row_cond:
	bge	$s0, NUM_ROWS, print_flag__row_end
print_flag__row_body:
	# printRow(row)
	move	$a0, $s0
	jal	print_row
	# Assume every $t and $a register is clobbered (reset)
	# Assume $s registers are completely untouched
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
	# $t0 = col
	# $t1 = address calclation
	# $t2 = flag[row][col]
	# $t3 = row

	move	$t3, $a0

print_row__body:
print_row__col_init:
	li	$t0, 0
print_row__col_cond:
	bge	$t0, NUM_COLS, print_row__col_end
print_row__col_body:

	# address = base + sizeof(element) * (i * NUM_COLS + j)
	# address = flag + 1 * (i * 12 + j )
	# $t1 = row * NUM_COLS
	mul	$t1, $t3, NUM_COLS
	# $t1 += col
	add	$t1, $t0
	# mul	$t1, 1
	# $t1 = flag[row][col]
	lb	$t2, flag($t1)

	# syscall 11 (putchar)
	# putchar(flag[row][col])
	li	$v0, 11
	move	$a0, $t2

	syscall

print_row__col_step:
	add	$t0, 1
	b	print_row__col_cond
print_row__col_end:
	# syscall 11 (putchar)
	# putchar('\n');
	li	$v0, 11
	li	$a0, '\n'
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
print_hill__body:
	# if (height <= 0) return;
	blez	$s0, print_hill__epilogue

	# height - 1
	sub	$a0, $s0, 1
	# printHill(height - 1)
	jal	print_hill

print_hill__i_init:
	li	$t0, 0
print_hill__i_cond:
	bge	$t0, $s0, print_hill__i_end
print_hill__i_body:
	# syscall 11 (putchar)
	# putchar('*');
	li	$v0, 11
	li	$a0, '*'
	syscall

print_hill__i_step:
	add	$t0, 1
	b	print_hill__i_cond
print_hill__i_end:
	# syscall 11 (putchar)
	# putchar('\n');
	li	$v0, 11
	li	$a0, '\n'
	syscall

print_hill__epilogue:

	pop	$s0
	pop	$ra
	end

	jr	$ra
