#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a;

 a = malloc(sizeof(int) * 10);

  for (i=0; i < 10; i++){
    *(a+i) = i;
   }
  free(a);
  return 0;
}

