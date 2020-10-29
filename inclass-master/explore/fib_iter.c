#include<stdio.h>

int fib_iter_c(int n) {
    int prev_prev_num = 0, prev_num = 0, cur_num = 1;

    if (n == 0) {
        return 0;
    }
    for (int i = 1; i < n ; i++) {
        prev_prev_num = prev_num;
        prev_num = cur_num;
        cur_num = prev_prev_num + prev_num;
    }
    return cur_num;
}

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i <= 20; i++) {
        printf("fib_iter_c(%d) = %d\n", i, fib_iter_c(i));
    }
}
