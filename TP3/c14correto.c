#include <stdio.h>

int main(void) {
  int n, i;

  n = -1;
  do {
    printf("Positive integer:");
    scanf("%d", &n);

    if (n < 0) {
      printf("Factorial de %lld = não é definida nos naturais\n", n);
    }
  } while (n < 0);

  long long int fact;

  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == 1) {
      fact = 1;
    } else {
      fact *= i;
    }
  }

  printf("Factorial %lld = %lld\n", n, fact);
}
