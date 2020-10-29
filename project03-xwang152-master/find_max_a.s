    .global find_max_a
    .func find_max_a

    /* r0 - int *array */
    /* r1 - int len */
    /* r2 - int i */
    /* r3 - int max */
find_max_a:
    mov r2, #0
    //init i as 0 for the 
    loop
    ldr r3, [r0]
    //set max to 0
loop: 
    # loop check
    cmp r2, r1
    //check if it reach 
    the end of the array
    beq endloop
    
    # loop body
    ldr r12, [r0]
    //set r12 to 
    current index
    cmp r3, r12
    blt update_max
    //update if r3 < r12

    # loop increment
    add r2, r2, #1
    // update i
    add r0, r0, #4
    //set the pointer to 
    the next index
    b loop
update_max:
    mov r3, r12
    add r2, r2, #1
    add r0, r0, #4
    b loop
endloop:
    mov r0, r3
    bx lr
