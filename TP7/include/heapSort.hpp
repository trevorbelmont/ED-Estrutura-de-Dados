#ifndef HEAPSORT
#define HEAPSORT

#include <iomanip>
#include <iostream>
using namespace std;

// Ordenador via heapSort
void printHeapedSort(int* array, int count);

// retorna um vetor de tamanho tam, randomizado no intervalo [0,max]
template <typename Tipo>
void randomize(Tipo arrray[], int tam, int max);

// ------------ Definições --------------//
template <typename Tipo>
void randomize(Tipo array[], int tam, int max) {
  srand(unsigned(time(NULL)));
  for (int i = 0; i < tam; i++) {
    if (rand() % 2 == 0.0f) {
      array[i] = -(Tipo(rand() % (max + 1)));
      continue;
      // se o rand naquele momento for par o núemro gerado é negativo.
    }
    array[i] = Tipo(rand() % (max + 1));
    // se chegou aqui o número será par.
  }
}

// Gerador de ints aleatórios (maiores e menores)
int* randomArray(int tam, int max) {
  srand(unsigned(time(NULL)));
  int* array = new int[tam];
  for (int i = 0; i < tam; i++) {
    if (rand() % 2 == 0.0) {
      array[i] = -(int(rand() % (max + 1)));
      continue;
      // se rand naquele momento for par, o número gerado é negativo
    }
    array[i] = int(rand() % (max + 1));
    // se chegou aqui a semente não era par. (random number é positivo)
  }
  return array;
}

template <typename Tipo>
void list(Tipo array[], int tam) {
  for (int i = 0; i < tam; i++) {
    cout << fixed << setprecision(2) << array[i] << " ";
  }
  cout << endl;
}

#endif