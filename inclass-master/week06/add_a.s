    .global add_a
    .func add_a

add_a:
    add r0, r0, r1
    mov lr, #0
    bx lr
    
