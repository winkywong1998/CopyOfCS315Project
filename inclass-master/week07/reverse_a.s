    .global reverse_a
    .func reverse_a
    /* r0 = char *s, r1 = int len */
    /* r2 = int i, r3 = m */
reverse_a:
    sub sp, sp, #8
    str r4, [sp]
    str r5, [sp, #4]
    /* round up to a multiple of 8 */
    and r5, r1, #7
    mov r2, #8
    sub r5, r2, r5
    add r5, r5, r1

    sub sp, sp, r5
    sub r3, r1, #1
    mov r2, #0
loop1:
    cmp r2, r1
    beq loop1end
    ldrb r12, [r0, r2]
    sub r4, r3, r2
    strb r12, [sp, r4]
    add r2, r2, #1
    b loop1
loop1end:

    mov r2, #0
loop2:
    cmp r2, r1
    beq loop2end
    ldrb r12, [sp, r2]
    strb r12, [r0, r2]
    add r2, r2, #1
    b loop2
loop2end:   
    add sp, sp, r5
    ldr r5, [sp, #4]
    ldr r4, [sp]
    add sp, sp, #8
    bx lr
