    .global sum_array_a
    .func sum_array_a

    /* r0 - int *array */
    /* r1 - int len */
    /* r2 - int i */
    /* r3 - int sum */
sum_array_a:
    mov r2, #0
    //init i for the loop
    mov r3, #0
    //initsun as 0
loop:
    # loop check
    cmp r2, r1
    //check if reach the end of thge array
    beq endloop

    # loop body
    ldr r12, [r0]
    //set r12 to the current index of array
    add r3, r3, r12
    //add current index to sum

    # loop increment
    add r2, r2, #1
    //i++
    add r0, r0, #4
    //to the next index
    b loop
endloop:
    mov r0, r3
    bx lr
