int mult_c(int n1, int n2)
{
    int r;

    r = n1 * n2;

    return r;
}

int smult2_c(int *array, int len, int s)
{
    int i;

    for (i = 0; i < len; i++) {
        array[i] = mult_c(array[i], s);
    }

    return 0;
}
    
