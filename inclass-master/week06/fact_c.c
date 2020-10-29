int fact_rec_c(int n)
{
    int r;

    if (n == 0) {
        r = 0;
    } else {
        r = n * fact_rec(n - 1);
    }

    return r;
}

            
