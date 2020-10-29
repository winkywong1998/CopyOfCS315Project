main:
    mov r0, #19
    bl fib_iter_a_19

end:
    b end

    /* r0 - int n */
    /* r1 - int prev_prev_num */
    /* r2 - int prev_num */
    /* r3 - int cur_num */
fib_iter_a_19:
    mov r1, #0
    mov r2, #0
    mov r3, #1
    mov r12, #1
    //intiallize
    cmp r0, #0
    beq set_zero
    //check if 0, return 0
loop: 
    # loop check
    cmp r12, r0
    beq endloop
    //see if it have to return
    
    # loop body
    mov r1, r2
    mov r2, r3
    add r3, r1, r2

    # loop increment
    add r12, r12, #1
    b loop
set_zero:
    mov r3, #0
endloop:
    mov r0, r3
    bx lr
