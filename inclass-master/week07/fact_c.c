int fact_iter_c(int n)
{
    int r = 1;

    while (n > 0) {
        r = r * n;
        n = n - 1;
    }

    return r;
}

int fact_rec_c(int n)
{
    int r;

    if (n == 0) {
        r = 1;
    } else {
        r = fact_rec_c(n-1) * n;
    }

    return r;
}
