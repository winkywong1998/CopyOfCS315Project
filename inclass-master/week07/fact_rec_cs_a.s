    .global fact_rec_cs_a
    .func fact_rec_cs_a
    // Recursive factorial using callee-saved registers (r4 and lr)
    // r0 is n
fact_rec_cs_a:
    sub sp, sp, #8              // allocate 2 words on stack
    str lr, [sp]                // store lr on stack
    str r4, [sp, #4]            // store r4 (callee-saved) on stack

    /* base case */
    cmp r0, #0                  // r0(n) == 0 ?
    bne fact_recursive_step     // if false branch to recursive step
    mov r1, #1                  // r1(r) = #1
    b fact_end                  // branch to fact_end
    
    /* recursive step */
fact_recursive_step:    
    mov r4, r0                  // put r0(n) into r4, which will be
                                // preserved

    sub r0, r0, #1              // r0(n) = r0(n) - 1
    bl fact_rec_a               // call fact_rec_a (recursive call)
    mul r1, r0, r4              // r1(r) = r1(fact_rec_a(r1(n) - 1)) * r4(n)
    
fact_end:   
    mov r0, r1                  // r0(return value) = r1(r)
    ldr r4, [sp, #4]            // restore r4
    ldr lr, [sp]                // restore lr
    add sp, sp, #8              // deallocate 2 words from stack (sp is restored)
    bx lr                       // return to caller
    .endfunc