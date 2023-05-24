#ifndef SHELLSORT
#define SHELLSORT

#include <cmath>
#include <iomanip>
#include <iostream>

#include "heapSort.hpp"
using namespace std;

// Retorna um inteiro log na base 2 do inteiro tam - sempre arredondado para cima.
int haga(int tam) {
  if (tam > 1) {
    return ceil(log2(tam));
  } else {
    return 0;
  }
}
// ORDENA O VETOR *VET POR SHELLSORT COM ATUALIZAÇÃO DE HAGA DADA PELA FUNÇÃO HAGA
template <typename Tipo>
void shellSort(Tipo *array, int size) {
  int i, j;
  Tipo value;
  int h = haga(size);
  while (h > 0) {
    for (i = h; i < size; i++) {
      value = array[i];
      j = i;
      while (j > h - 1 && value <= array[j - h]) {
        array[j] = array[j - h];
        j = j - h;
      }
      array[j] = value;
    }
    // checa se precisa atualizar h (h = 1 é vetor ordenado)
    if (h > 1) {
      h = haga(h);
      //  cout << "h: " << h << " " << endl;
    } else {
      h = 0;
      return;
    }
  }
}

#endif