int max3_c(int x, int y, int z)
{
    int r;

    if (x > y) {
        r = x;
    } else {
        r = y;
    }

    if (z > r) {
        r = z;
    }
    
    return r;
}
