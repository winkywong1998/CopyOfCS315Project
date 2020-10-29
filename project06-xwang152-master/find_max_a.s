main:
    mov sp, #256
    sub sp, sp, #24
    mov r0, #2
    str r0, [sp]
    mov r0, #4
    str r0, [sp, #4]
    mov r0, #6
    str r0, [sp, #8]
    mov r0, #7
    str r0, [sp, #12]
    mov r0, #9
    str r0, [sp, #16]
    mov r0, sp
    mov r1, #5
    bl find_max_a
end:
    b end

/* r0: int *array */
/* r1: len */
/* r2: i */
/* r3: max */
find_max_a:
    //i = 0
    mov r2, #0
    //total = 0
    ldr r3, [r0]
loop:
    cmp r2, r1
    beq endloop

    ldr r12, [r0]
    cmp r12, r3
    bgt update
increment:
    add r2, r2, #1
    add r0, r0, #4
    b loop
update:
    mov r3, r12
    b increment
endloop:

    mov r0, r3
    bx lr
    