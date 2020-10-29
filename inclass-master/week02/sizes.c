#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("sizeof(char)      = %lu\n", sizeof(char));
    printf("sizeof(int)       = %lu\n", sizeof(int));
    printf("sizeof(long)      = %lu\n", sizeof(long));
    printf("sizeof(long long) = %lu\n", sizeof(long long));
    printf("sizeof(float)     = %lu\n", sizeof(float));
    printf("sizeof(double)    = %lu\n", sizeof(double));
    printf("sizeof(int *)     = %lu\n", sizeof(int *));
    printf("sizeof(uint8_t)   = %lu\n", sizeof(uint8_t));
    printf("sizeof(size_t)    = %lu\n", sizeof(size_t));

    return 0;
}
