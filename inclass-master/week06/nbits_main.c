#include<stdio.h>

int pow_c(int n, int exp);
int pow_a(int n, int exp);
int nbits_c(int n);
int nbits_a(int n);

int main(int argc, char **argv)
{
    int r;

    r = pow_c(2,0);
    printf("pow_c(2,1) = %d\n", r);
    r = pow_a(2,0);
    printf("pow_a(2,1) = %d\n", r);
    
    r = pow_c(2,1);
    printf("pow_c(2,1) = %d\n", r);
    r = pow_a(2,1);
    printf("pow_a(2,1) = %d\n", r);        

    r = pow_c(2,2);
    printf("pow_c(2,2) = %d\n", r);
    r = pow_a(2,2);
    printf("pow_a(2,2) = %d\n", r);    
    
    r = nbits_c(4);
    printf("nbits_c(4) = %d\n", r);
    r = nbits_a(4);
    printf("nbits_a(4) = %d\n", r);    
    

    return 0;
}
