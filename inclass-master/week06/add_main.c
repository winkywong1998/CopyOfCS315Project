#include<stdio.h>

int add_a(int n1, int n2);

int main(int argc, char **argv)
{
    int r;

    r = add_a(1,2);
    xcprintf("r = %d\n", r);

    return 0;
}
