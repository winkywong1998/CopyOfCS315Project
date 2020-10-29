#include<stdio.h>

int reverse_c(char *s, int len);
int reverse_a(char *s, int len);

int main(int argc, char **argv)
{
    char s1[] = "Foo Bar";

    reverse_c(s1, 7);
    printf("reverse_c(\"Foo Bar\") = %s\n", s1);

    reverse_a(s1, 7);
    printf("reverse_a(\"raB ooF\") = %s\n", s1);

    return 0;
}
