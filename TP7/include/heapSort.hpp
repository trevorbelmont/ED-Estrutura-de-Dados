#ifndef HEAPSORT
#define HEAPSORT

#include <iostream>
using namespace std;

// Ordenador via heapSort
void printHeapedSort(int *array, int count);

// retorna um vetor de tamanho tam, randomizado no intervalo [0,max]
void randomArray(int arrray[], int tam, int max);

// ------------ Definições --------------//

void randomArray(int array[], int tam, int max) {
  srand(unsigned(time(NULL)));
  for (int i = 0; i < tam; i++) {
    array[i] = rand() % (max + 1);
  }
}
void list(int array[], int tam) {
  srand(unsigned(time(NULL)));
  for (int i = 0; i < tam; i++) {
    cout << array[i] << " ";
  }
}

#endif