#ifndef HEAPSORT
#define HEAPSORT

#include <iomanip>
#include <iostream>
using namespace std;

// Heapfica (maior pro menor) a subárvore enraizada no "nó root". Heap pode ser visto como  uma fila de prioridades.
template <typename Tipo>
void heapfy(Tipo heaping[], int tam, int root);

// retorna uma heap (maior pro menor) construída a partir do array de origem (source) de tamanho tam.
template <typename Tipo>
Tipo* buildHeap(Tipo source[], int tam);

// Constrói uma heap a partir do array source[] - na implementação da disciplina -  com ordenação maior pro menor.
template <typename Tipo>
Tipo* ConstroiHeap(Tipo source[], int tam);

// garante a condição heap da subárvore (ou subrelação?) indexada na subraíz root
template <typename Tipo>
void reHeapfica(Tipo source[], int root, int tam);

// Ordena o array via heapsort: constrói heap, re-heapfica e ordena o array.
void heapSort(int* array, int tam);

//--------------------------- Aleatórios ---------------------------//

// Randomiza o array<Tipo> no intervalo [-max,max], i.e: positivos e negativos
// Seed padrão (caso não especificada) é o tempo na hora do sorteio: unsigned ( Time(NULL))
template <typename Tipo>
void randomize(Tipo arrray[], int tam, int max, int seed);

// Aloca e retorna um array de ints aleatórios (maiores e menores) no intervalo [-max,max]
// Seed padrão é o tempo na hora do sorteio: unsigned ( Time(NULL))
int* randomArray(int tam, int max, int seed);

// ---- Definições de Aleatórios e lista ------//

template <typename Tipo>
void randomize(Tipo array[], int tam, int max, int seed) {
  srand(seed);
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

int* randomArray(int tam, int max, int seed) {
  srand(seed);
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

// Lista um array de Tipos de tamanho tam;
template <typename Tipo>
void list(Tipo array[], int tam) {
  for (int i = 0; i < tam; i++) {
    cout << fixed << setprecision(2) << array[i] << " ";
  }
  cout << endl;
}

// ------------------------ Definições --------------------------//
// ------------------------ Definições --------------------------//
template <typename Tipo>
Tipo* buildHeap(Tipo source[], int tam) {
  int pe = (tam / 2) - 1;  // último "nó" que não é uma folha

  // vai heapificando as subárvores desde o pé (último nó não folha) até a raíz (i = 0)
  for (int i = pe; i >= 0; i--) {
    heapfy(source, tam, i);  // heapifica o nodo e parte para heapifica o nodo superior.
  }

  return source;
}
// Refaz do Slide
template <typename Tipo>
void Refaz(int Esq, int Dir, Tipo* A) {
  int i, j;
  Tipo x;
  i = Esq;
  j = i * 2;
  x = A[i];
  while (j <= Dir) {
    if (j < Dir)
      if (A[j] < A[j + 1]) j++;
    if (x >= A[j]) break;
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  A[i] = x;
}
template <typename Tipo>
Tipo* ConstroiHeap(Tipo source[], int tam) {
  int lastHeapIndex = (tam / 2) + 1;

  while (lastHeapIndex > 1) {
    lastHeapIndex--;
    if (lastHeapIndex == 1) {
      cout << "come here" << endl;
    }
    // reHeapfica(source, lastHeapIndex, tam);
    Refaz(lastHeapIndex, tam, source);
  }
  return source;
}
template <typename Tipo>
void reHeapfica(Tipo source[], int root, int tam) {
  int i = root;        // Raiz da sub-árvore
  Tipo x = source[i];  // x = chave da raíz considerada
  int j = i * 2;       // o filho a esquerda de esq ( o filho da direita é i*2 + 1)

  while (j <= tam) {  // Enquanto j ainda for um filho

    if (j < tam) {  // Se Houver um filho a direita
      // verifica qual filho é maior e faz j indereçar ele
      j += ((source[j] < source[j + 1])) ? 1 : 0;
    }
    if (x >= source[j]) {  // checa se o pai é maior que o maior dos filhos
      break;               // Se a condição heap estiver garantida, sai do while
    }
    // Se não estiver na condição heap,
    else {
      //  heapfica a relação destes 3 nodos.
      source[i] = source[j];
      i = j;
      j = i * 2;
    }
  }

  source[i] = x;  // Pode ou não colocar a chave pai na posição do descendente
}
template <typename Tipo>

void heapfy(Tipo heaping[], int tam, int root) {
  int biggest = root;
  int l = root * 2 + 1;  // índice do nodo da esquerda
  int r = root * 2 + 2;  // indice do nodo da diretia

  if (l < tam && heaping[l] > heaping[root]) {
    biggest = l;
  }
  if (r < tam && heaping[r] > heaping[root])
    biggest = r;

  // Se o menor não é mais o root (checado ascondicionais acima);
  if (biggest != root) {
    Tipo swaper = heaping[root];  // swaper é um aux
    heaping[root] = heaping[biggest];
    heaping[biggest] = swaper;

    // Faz chamada recursiva para heapificar dali em diante
    heapfy(heaping, tam, biggest);
  }
}

void heapSort(int* array, int tam) {
  array = buildHeap(array, tam);
}

#endif