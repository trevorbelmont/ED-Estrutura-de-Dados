#ifndef HEAPSORT
#define HEAPSORT

#include <iomanip>
#include <iostream>
using namespace std;

// Heapfica a subárvore enraizada no nó "root".
void heapfy(int* heaping, int tam, int root);

// retorna uma heap construída a partir do array de origem (source) de tamanho tam.
int* buildHeap(int source[], int tam);

//--------------------------- Aleatórios ---------------------------//

// Ordenador via heapSort
void printHeapedSort(int* array, int count);
// Randomiza o array<Tipo> no intervalo [-max,max], i.e: positivos e negativos
template <typename Tipo>
void randomize(Tipo arrray[], int tam, int max);

// retorna um array de ints aleatórios (maiores e menores) no intervalo [-max,max]
int* randomArray(int tam, int max);

// ------------------------ Definições --------------------------//
// ------------------------ Definições --------------------------//

int* buildHeap(int source[], int tam) {
  int pe = (tam / 2) - 1;  // último "nó" que não é uma folha

  // vai heapificando as subárvores desde o pé (último nó não folha) até a raíz (i = 0)
  for (int i = pe; i >= 0; i--) {
    heapfy(source, tam, i);  // heapifica o nodo e parte para heapifica o nodo superior.
  }

  return source;
}

void heapfy(int* heaping, int tam, int root) {
  int smallest = root;
  int l = root * 2 + 1;  // índice do nodo da esquerda
  int r = root * 2 + 2;  // indice do nodo da diretia

  if (l < tam && heaping[l] < heaping[root]) {
    smallest = l;
  }
  if (r < tam && heaping[r] < heaping[root])
    smallest = r;

  // Se o menor não é mais o root (checado ascondicionais acima);
  if (smallest != root) {
    int swaper = heaping[root];  // swaper é um aux
    heaping[root] = heaping[smallest];
    heaping[smallest] = swaper;

    // Faz chamada recursiva para heapificar dali em diante
    heapfy(heaping, tam, smallest);
  }
}

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