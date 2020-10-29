#include<stdio.h>

int count_zeros_c(int *array, int len);
int count_zeros_a(int *array, int len);

int main(int argc, char **argv)
{
    int arr1[] = {1, 0, 2, 0, 3};
    int r;

    r = count_zeros_c(arr1, 5);
    printf("count_zeros_c({1,0,2,0,3},5) = %d\n", r);

    r = count_zeros_a(arr1, 5);
    printf("count_zeros_a({1,0,2,0,3},5) = %d\n", r);

    return 0;
}
