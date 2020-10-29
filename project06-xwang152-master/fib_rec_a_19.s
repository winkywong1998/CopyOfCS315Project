main:
    mov r0, #19
    mov sp, #128
    bl fib_rec_a
end:
    b end
    
/* r0: n */
/* r1: fib_rec_a(n-1) */
/* r2: fib_rec_a(n-2) */
fib_rec_a:
	cmp r0, #0
	beq nzero
	cmp r0, #1
	beq none

	//recursion
	//allocate 8
	sub sp, sp, #8
	//store r0 and lr
	str lr, [sp]
	str r0, [sp, #4]
	//recurse n - 1
	sub r0, #1
	bl fib_rec_a
	//store result to r1
	mov r1, r0
	//load n back
	ldr r0, [sp, #4]
	//store r1 to sp
	str r1, [sp, #4]
	//n--
	sub r0, #2
	//recurse call
	bl fib_rec_a
	//store result to r2
	mov r2, r0
	//load r1 back
	ldr r1, [sp, #4]
	//r0 = r1 + r2
	add r0, r2, r1
	//load lr back
	ldr lr, [sp]
	add sp, sp, #8
	b return

nzero:
	mov r0, #0
	b return
none:
	mov r0, #1
return:
	bx lr
