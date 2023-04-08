#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b) {
  int c;
  c = a / b;
  return c;
}

int calc() {
  int a;
  int b;
  a = 13;
  b = rand() %13 + 1; // +1 pra impedir divisão por zero e o módulo alcançar o próprio 13
  return actual_calc(a, b);
}

int main(int argc, char **argv) {
  int x = atoi(argv[argc - 2]);
  int y = atoi(argv[argc - 1]);

  printf(" a razão inteira dá: %d\n", actual_calc(x, y));
  return 0;
}
