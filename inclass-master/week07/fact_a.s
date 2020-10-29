    .global fact_iter_a
    .global fact_rec_a
    
    .func fact_iter_a
    // r0 is n
    // r1 is r (product)
fact_iter_a:
    mov r1, #1                  // r1(r) = 1 
while:
    cmp r0, #0                  // r0(n) == 0 ? 
    beq endwhile                // if true, branch to end
    mul r1, r0, r1              // r1(r) = r0(n) * r1(r)
    sub r0, r0, #1              // r1(n) = r(n) - 1
    b while                     // branch to top of while loop
endwhile:   
    mov r0, r1                  // r0(return value) = r1(r)
    bx lr                       // return to caller
    .endfunc
 

    .func fact_rec_a
    // r0 is n
fact_rec_a:
    sub sp, sp, #8              // allocate 2 words on stack
    
    /* base case */
    cmp r0, #0                  // r0(n) == 0 ?
    bne fact_recursive_step     // if false branch to recursive step
    mov r1, #1                  // r1(r) = #1
    b fact_end                  // branch to fact_end
    
    /* recursive step */
fact_recursive_step:    
    str lr, [sp]                // store lr on stack[0]
    str r0, [sp, #4]            // store r0 on stack[1]

    sub r0, r0, #1              // r0(n) = r0(n) - 1
    bl fact_rec_a               // call fact_rec_a (recursive call)
    mov r1, r0                  // r1(r) = r0(return value of fact_rec_a)
    
    ldr r0, [sp, #4]            // restore original r0 from stack[1]
    ldr lr, [sp]                // restore original lr from stack[0]

    mul r1, r0, r1              // r1(r) = r0(n) * r1(fact_rec_a(r1(n) - 1))
    
fact_end:   
    mov r0, r1                  // r0(return value) = r1(r)
    add sp, sp, #8              // deallocate 2 words from stack (sp is restored)
    bx lr                       // return to caller
    .endfunc
