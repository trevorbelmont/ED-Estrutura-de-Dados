#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    x = rand() % 10;
    if(x == 0) {
        printf("X is zero"); 
    }
    return 0;
}

