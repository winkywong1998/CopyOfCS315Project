#include<stdio.h>

int main(int argc, char **argv)
{
  int a = 0;
  unsigned int b = a - 1;

  if (b < a) {
    printf("b is less than a\n");
  } else {
    printf("b is not less than a\n");
  }

  return 0;
}
