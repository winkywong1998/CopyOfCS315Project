    .global max3_a
    .func max3_a

    /* r0 = x, r1 = y, r2 = z */
max3_a:
    cmp r0, r1
    blt r1_max
    b endif
r1_max:
    mov r0, r1
endif:

    cmp r0, r2
    bgt endif2
r2_max:
    mov r0, r2
endif2: 
    bx lr
