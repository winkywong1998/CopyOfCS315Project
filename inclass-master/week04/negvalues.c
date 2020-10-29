#include<stdio.h>


int main(int argc, char **argv)
{
    unsigned int u = 50000;
    int v;

    v = ((int) u) * -1;

    u = (unsigned) v;

    printf("v = %d\n", v);
    printf("u = %X\n", u);

    return 0;
}
