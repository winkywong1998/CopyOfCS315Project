    .global max_a
    .func max_a

max_a:
    cmp r0, r1
    blt r1_max
    b continue
r1_max:
    mov r0, r1
continue:
    bx lr
