    .global main

    .data   
string:
    .asciz "Hello World\n"

    .text

    .func main
main:
    sub sp, sp, #8
    str lr, [sp]

    ldr r0, =string
    bl printf

    ldr lr, [sp]
    add sp, sp, #8
    bx lr
    .endfunc    
