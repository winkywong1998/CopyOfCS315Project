    .global quadratic_a
    .func quadratic_a

    /* r0 - int x */
    /* r1 - int a */
    /* r2 - int b */
    /* r3 - int c */

quadratic_a:
    mul r2, r0, r2
    //b * x
    mul r12, r0, r0
    //x * x
    mul r0, r12, r1
    //a * (x * x)
    add r0, r0, r2
    //(a * (x * x)) + (b * x)
    add r0, r0, r3
    //add c
    bx lr
