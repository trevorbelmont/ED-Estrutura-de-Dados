#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * buf;

//realiza o somatório de 1 a "num" com incrementos simples (incremento de 1)
int sum_to_n(int num)
{
    int i,sum=0;
    for(i=1;i<=num;i++)
        sum+=i;
    return sum;
}

void printSum()
{
    char line[10];
  buf = malloc( sizeof(char) *10);


    printf("enter a number:\n");
    fgets(line, 10, stdin);
    if(line != NULL) 
        strtok(line, "\n"); 
    sprintf(buf,"sum=%d",sum_to_n(atoi(line)));
    printf("%s\n",buf);
    free(buf);
}

int main(void)
{
    printSum();
    return 0;
}
