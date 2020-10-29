    .global count_zeros_a
    .func count_zeros_a

    /* r0 - int *array */
    /* r1 - int len */
    /* r2 - int i */
    /* r3 - int count */
count_zeros_a:
    mov r2, #0
    mov r3, #0
loop:   
    cmp r2, r1
    beq endloop
    ldr r12, [r0]
    cmp r12, #0
    bne notzero
    add r3, r3, #1
notzero:    
    add r2, r2, #1
    add r0, r0, #4
    b loop
endloop:
    mov r0, r3
    bx lr
