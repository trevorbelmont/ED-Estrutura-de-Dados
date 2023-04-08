 #include <stdlib.h>

int tam;

void f(void) {

int* x = malloc(tam * sizeof(int));
x[tam-1] = 0; 

free (x); // liberando aqui já que foi essa função que allocou (e ela não faz nada)
}

int main(void) {
tam = 10;
f();

return 0;
}


