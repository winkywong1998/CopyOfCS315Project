/* -- first.s */
/* This is a comment */
.global main /* 'main' is our entry point and must be global */
.func main   /* 'main' is a function */
 
main:          /* This is main */
    mov r0, #1
    mov r1, #2
    add r0, r0, r1
    bx lr      /* Return from main */
