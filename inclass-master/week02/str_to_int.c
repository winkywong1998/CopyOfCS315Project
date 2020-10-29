#include<stdio.h>
#include<string.h>

int str_to_int(char *s)
{
    int d[32];
    int i;
    int len;
    int sum = 0;
    int factor = 10;

    len = strlen(s);

    for (i = 0; i < len; i++) {
        d[i] = (int) (s[i] - '0');
    }

    for (i = 0; i < len; i++) {
        sum = sum * factor;
        sum = sum + d[i];
    }
        
    return sum;
}

int main(int argc, char **argv)
{
    int v;
    char *s = "1234";

    v = str_to_int(s);

    printf("v = %d\n", v);

    return 0;
}
