main:
    mov r0, #2
    mov r1, #6
    mov r2, #7
    mov r3, #9
    bl quadratic_a

end:
    b end

    /* r0 - int x */
    /* r1 - int a */
    /* r2 - int b */
    /* r3 - int c */

quadratic_a:
    mul r2, r0, r2
    mul r12, r0, r0
    mul r0, r12, r1
    add r0, r0, r2
    add r0, r0, r3
    bx lr
