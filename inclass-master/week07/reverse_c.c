int reverse_c(char *s, int len)
{
    int i;
    int m = len - 1;
    char r[len];

    for (i = 0; i < len; i++) {
        r[m-i] = s[i];
    }

    for (i = 0; i < len; i++) {
        s[i] = r[i];
    }   

    return 0;
}
