#ifndef HEAPSORT
#define HEAPSORT

#include <iomanip>
#include <iostream>
using namespace std;

// Ordenador via heapSort
void printHeapedSort(int *array, int count);

// retorna um vetor de tamanho tam, randomizado no intervalo [0,max]
template <typename Tipo>
void randomArray(Tipo arrray[], int tam, int max);

// ------------ Definições --------------//
template <typename Tipo>
void randomArray(Tipo array[], int tam, int max) {
  srand(unsigned(time(NULL)));
  for (int i = 0; i < tam; i++) {
    array[i] = Tipo(rand() % (max + 1));
  }
}
template <typename Tipo>
void list(Tipo array[], int tam) {
  for (int i = 0; i < tam; i++) {
    cout << fixed << setprecision(2) << array[i] << " ";
  }
  cout << endl;
}

#endif