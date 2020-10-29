    .global smult2_a

    .func mult_a
mult_a:
    mul r0, r1, r0
    bx lr
    .endfunc
    
    .func smult2_a

    /* r0 - int *array */
    /* r1 - int len */
    /* r2 - int s */
    /* r3 - int i */
smult2_a:
    sub sp, sp, #24
    
    mov r3, #0
loop:
    # loop check
    cmp r3, r1
    beq endloop

    # loop body
    ldr r12, [r0]

    str r0, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #12]
    str lr, [sp, #16]

    mov r0, r12
    mov r1, r2
    
    bl mult_a

    mov r12, r0
    
    ldr lr, [sp, #16]
    ldr r3, [sp, #12]
    ldr r2, [sp, #8]
    ldr r1, [sp, #4]
    ldr r0, [sp]
       
    str r12, [r0]

    # loop increment
    add r3, r3, #1
    add r0, r0, #4
    b loop
endloop:
    mov r0, r3
    bx lr
    .endfunc
    
