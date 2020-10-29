#include<stdio.h>

int max3_c(int x, int y, int z);
int max3_a(int x, int y, int z);

int main(int argc, char **argv)
{
    int r;

    r = max3_c(30,50,20);
    printf("max3_c(30,50,20) = %d\n", r);
    r = max3_a(30,50,20);
    printf("max3_a(30,50,20) = %d\n", r);
    
    r = max3_c(99,1,0);
    printf("max3_c(99,1,0) = %d\n", r);
    r = max3_a(99,1,0);
    printf("max3_a(99,1,0) = %d\n", r);
    
    r = max3_c(0,-1,-3);
    printf("max3_c(0,-1,-3) = %d\n", r);
    r = max3_a(0,-1,-3);
    printf("max3_a(0,-1,-3) = %d\n", r);    

    return 0;
}
