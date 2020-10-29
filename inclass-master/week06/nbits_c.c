int pow_c(int n, int exp)
{
    int r = 1;
    int i;

    for (i = 0; i < exp; i++) {
        r = r * n;
    }

    return r;
}

int nbits_c(int n)
{
    int r;

    r = pow_c(2,n) - 1;

    return r;
}
