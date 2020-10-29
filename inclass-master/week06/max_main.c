#include<stdio.h>

int max_c(int x, int y);
int max_a(int x, int y);

int main(int argc, char **argv)
{
    int r;

    r = max_c(30,50);
    printf("max_c(30,50) = %d\n", r);
    r = max_a(30,50);
    printf("max_a(30,50) = %d\n", r);
    
    r = max_c(99,1);
    printf("max_c(99,1) = %d\n", r);
    r = max_a(99,1);
    printf("max_a(99,1) = %d\n", r);

    r = max_c(0,-1);
    printf("max_c(0,-1) = %d\n", r);
    r = max_a(0,-1);
    printf("max_a(0,-1) = %d\n", r);    

    return 0;
}
