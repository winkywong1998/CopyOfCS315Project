#include<stdio.h>

int smult2_c(int *array, int len, int s);
int smult2_a(int *array, int len, int s);

void print_array(int *array, int len)
{
    int i;

    printf("{");
    for (i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < (len - 1)) {
            printf(",");
        }
    }
    printf("}\n");
}

int main(int argc, char **argv)
{
    int arr1[] = {1, 0, 2, 0, 3};
    int arr2[] = {1, 0, 2, 0, 3};    
    int r;

    r = smult2_c(arr1, 5, 2);
    printf("smult2_c({1,0,2,0,3},5,2) = ");
    print_array(arr1, 5);

    r = smult2_a(arr2, 5, 2);
    printf("smult2_a({1,0,2,0,3},5,2) = ");
    print_array(arr2, 5);

    return 0;
}
