#include<stdio.h>

int fact_iter_c(int n);
int fact_iter_a(int n);

int fact_rec_c(int n);
int fact_rec_a(int n);
int fact_rec_cs_a(int n);

int main(int argc, char **argv)
{
    int r;

    r = fact_iter_c(5);
    printf("fact_iter_c(5) = %d\n", r);
    r = fact_iter_a(5);
    printf("fact_iter_a(5) = %d\n", r);
    
    r = fact_rec_c(5);
    printf("fact_rec_c(5) = %d\n", r);   
    r = fact_rec_a(5);
    printf("fact_rec_a(5) = %d\n", r);
    r = fact_rec_cs_a(5);
    printf("fact_rec_cs_a(5) = %d\n", r);       

    return 0;
}
