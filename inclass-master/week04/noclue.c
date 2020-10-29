#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc < 1)
    {
        return -1;
    }
    
    unsigned int a = (int) atoi(argv[argc - 1]);
    a = (a >= 0 ? a:-a);
    printf("Number: %d\n",a);
    int b = (int) a;
    printf("Number 2 : %d\n", b);
    return 0;
}
