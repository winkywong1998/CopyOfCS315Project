#include<stdio.h>

int quadratic_c(int x, int a, int b, int c);
int quadratic_a(int x, int a, int b, int c);
int sum_array_c(int *array, int n);
int sum_array_a(int *array, int n);
int find_max_c(int *array, int n);
int find_max_a(int *array, int n);
int fib_iter_c(int n);
int fib_iter_a(int n);
int fib_rec_c(int n);
int fib_rec_a(int n);
int strlen_c(char *s);
int strlen_a(char *s);

int main(int argc, char **argv)
{
    int arr[1001];
    for(int i=0;i<1000;i++)
	{
		arr[i] = i;
	}

    printf("Test Start:\n");
    printf("==========================================================\n");
    printf("Problem 1: quadratic (equation)\n");
    printf("Test 1: \n"); 
    printf("Input: 1, 2, 3, 4\n");
    printf("Result of C version: %d\n",quadratic_c(1, 2, 3, 4));
    printf("Result of assembly  version: %d\n",quadratic_a(1, 2, 3, 4));
    printf("Test 2: \n");
    printf("Input: 0, 7, 5, 6\n");
    printf("Result of C version: %d\n",quadratic_c(0, 7, 5, 6));
    printf("Result of assembly  version: %d\n",quadratic_a(0, 7, 5, 6));
    printf("Test 3: \n");
    printf("Input: -2, -1, 2, 6\n");
    printf("Result of C version: %d\n",quadratic_c(-2, -1, 2, 6));
    printf("Result of assembly  version: %d\n",quadratic_a(-2, -1, 2, 6));
    printf("Test 4: \n");
    printf("Input: 0, -1, -2, -6\n");
    printf("Result of C version: %d\n",quadratic_c(0, -1, -2, -6));
    printf("Result of assembly  version: %d\n",quadratic_a(0, -1, -2, -6));
    printf("==========================================================\n");
    printf("Problem 2: sum_array\n");
    printf("Test 1: \n"); 
    printf("Input: 1, 2, 3, 4, 5\n");
    printf("Result of C version: %d\n",sum_array_c((int[]){1 ,2, 3, 4, 5}, 5));
    printf("Result of assembly  version: %d\n",sum_array_a((int[]){1, 2, 3, 4,5}, 5));
    printf("Test 2: \n");
    printf("Input: An array from 0 to 999\n");
    printf("Result of C version: %d\n",sum_array_c(arr, 1000));
    printf("Result of assembly  version: %d\n",sum_array_a(arr, 1000));
    printf("Test 3: \n");
    printf("Input: -2, -1, 2, 6\n");
    printf("Result of C version: %d\n",sum_array_c((int[]){-2, -1, 2, 6}, 4));
    printf("Result of assembly  version: %d\n",sum_array_a((int[]){-2, -1, 2, 6}, 4));
    printf("Test 4: \n");
    printf("Input: 0, -1, -2, -6\n");
    printf("Result of C version: %d\n",sum_array_c((int[]){0, -1, -2, -6}, 4));
    printf("Result of assembly  version: %d\n",sum_array_a((int[]){0, -1, -2, -6}, 4));
    printf("==========================================================\n");
    printf("Problem 3: find_max\n");
    printf("Test 1: \n"); 
    printf("Input: 1, 2, 3, 4, 5\n");
    printf("Result of C version: %d\n",find_max_c((int[]){1 ,2, 3, 4, 5}, 5));
    printf("Result of assembly  version: %d\n",find_max_a((int[]){1, 2, 3, 4,5}, 5));
    printf("Test 2: \n");
    printf("Input: An array from 0 to 999\n");
    printf("Result of C version: %d\n",find_max_c(arr, 1000));
    printf("Result of assembly  version: %d\n",find_max_a(arr, 1000));
    printf("Test 3: \n");
    printf("Input: -2, -1, 2, 6\n");
    printf("Result of C version: %d\n",find_max_c((int[]){-2, -1, 2, 6}, 4));
    printf("Result of assembly  version: %d\n",find_max_a((int[]){-2, -1, 2, 6},4));
    printf("Test 4: \n");
    printf("Input: 0, -1, -2, -6\n");
    printf("Result of C version: %d\n",find_max_c((int[]){0, -1, -2, -6}, 4));
    printf("Result of assembly  version: %d\n",find_max_a((int[]){0, -1, -2, -6}, 4));
    printf("==========================================================\n");
    printf("Problem 4: fib_iter\n");
    printf("Test : \n"); 
    printf("Input: 20\n");
    printf("fib_iter: Result of C version: \n");
    for(int i=0;i<20;i++)
	{	
		printf("%d ", fib_iter_c(i));
    	
	}
	printf("\n");
	printf("fib_iter: Result of assembly version: \n");
	    for(int i=0;i<20;i++)
	{	
		printf("%d ", fib_iter_a(i));
    	
	}
	printf("\n");
	printf("==========================================================\n");
    printf("Problem 5: fib_rec\n");
    printf("Test : \n"); 
    printf("Input: 20\n");
    printf("fib_rec: Result of C version: \n");
    for(int i=0;i<20;i++)
	{	
		printf("%d ", fib_rec_c(i));
	}
	printf("\n");
	printf("fib_rec: Result of assembly version: \n");
	for(int j=0;j<20;j++)
	{	
		printf("%d ", fib_rec_a(j));
	}
	printf("\n");
	printf("==========================================================\n");
    printf("Problem 6: strlen\n");
    printf("Test 1: \n"); 
    printf("Input: I\n");
    printf("Result of C version: %d\n",strlen_c("I"));
    printf("Result of assembly  version: %d\n",strlen_a("I"));
    printf("Test 2: \n");
    printf("Input: love\n");
    printf("Result of C version: %d\n",strlen_c("love"));
    printf("Result of assembly  version: %d\n",strlen_a("love"));
    printf("Test 3: \n");
    printf("Input: CS\n");
    printf("Result of C version: %d\n",strlen_c("CS"));
    printf("Result of assembly  version: %d\n",strlen_a("CS"));
    printf("Test 4: \n");
    printf("Input: very\n");
    printf("Result of C version: %d\n",strlen_c("very"));
    printf("Result of assembly  version: %d\n",strlen_a("very"));
    printf("Test 5: \n");
    printf("Input: much\n");
    printf("Result of C version: %d\n",strlen_c("much"));
    printf("Result of assembly  version: %d\n",strlen_a("much"));

}
