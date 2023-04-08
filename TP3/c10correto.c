#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  p = malloc(10 * sizeof(long int));

  int it = 10;
  while (it > 1) {
    printf("%ld\n", (long)p);
      it--;
  }

  free(p);
  return (0);
}
