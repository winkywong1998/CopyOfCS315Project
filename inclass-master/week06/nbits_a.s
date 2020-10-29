    .global pow_a
    .global nbits_a
@ comment here
    .func pow_a
    /* r0 - n, r1 - exp */
    /* r2 - i, r3 - r */
pow_a: 
    mov r2, #0
    mov r3, #1
loop:                
    cmp r2, r1
    beq endloop
    mul r3, r0, r3
    add r2, r2, #1
    b loop
endloop:    
    mov r0, r3
    bx lr
    .endfunc

    .func nbits_a
nbits_a:
    /* make room on the stack */
    sub sp, sp, #8

    /* save lr on the stack, because it will be modify by call to pow_a */
    str lr, [sp]
    /* save r0 on the stack */
    str r0, [sp, #4]

    /* setup arguments for call to pow_a */
    mov r1, r0
    mov r0, #2

    bl pow_a

    /* put return value of pow_a into r1 */
    mov r1, r0

    /* load previous value of r0 from stack */
    ldr r0, [sp, #4]

    sub r0, r1, r0

    /* restore lr so we return to the caller */
    ldr lr, [sp]
    
    /* restore stack pointer and deallocate stack space */
    add sp, sp, #8
    bx lr
    .endfunc
