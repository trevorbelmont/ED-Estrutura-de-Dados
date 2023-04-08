#include <stdio.h>
#include <stdlib.h>

int inc(int a) {
  return a+1;
}

int main(int argc, char** argv) {
  int a, n;
  n =  a = atoi( argv[argc - 1] ); // transforma o último arguemnto em int (supões-se que seja um inteiro)


  for(int i=1; i <= n; i++) {
     a = inc(a);
  }

  printf ("%d incrementado de 1 %d vezes (ou seja: o dobro) é  %d \n",n, n,a );
  return a;
}
