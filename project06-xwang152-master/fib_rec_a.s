main:
    mov sp, #512
    mov r0, #10
    bl fib_rec_a

end:
    b end

    /* r0 - n */
    /* r1: fib_rec_a(n-1) */
    /* r2: fib_rec_a(n-2) */

fib_rec_a:
    
    /* base case */
    cmp r0, #0             
    beq fib_end
    cmp r0, #1 
    beq set_one
           
    /* recursive step */
fib_recursive_step:    
    sub sp, sp, #8
    str lr, [sp]      
    str r0, [sp, #4]   
    //allocate
    sub r0, r0, #1      
    bl fib_rec_a        
    mov r1, r0            
    //get the result of fib_rec_a(n-1) 
    ldr r0, [sp, #4]
    str r1, [sp, #4]
    
    sub r0, r0, #2
    bl fib_rec_a
    mov r2, r0
    //get the result of fib_rec_a(n-2) 
    ldr r1, [sp, #4]
    
    add r0, r2, r1
    // final result       
    ldr lr, [sp]            
    add sp, sp, #8
    b fib_end

set_one:
    mov r0, #1
    
fib_end:   
    bx lr
