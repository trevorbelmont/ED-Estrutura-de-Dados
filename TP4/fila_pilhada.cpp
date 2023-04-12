#include "fila_pilhada.hpp"

#include <iostream>

using namespace std;

// cria rQeuee com maxSize padrão.
rQeuee::rQeuee() {
  size = 0;
  first = last = size = 0;
  maxSize = 10;
  margin = size/5;
  qeuee = new int[size];  // for safety
}

// cria rQeuee com maxSize especificado em n.
rQeuee::rQeuee(int n) : rQeuee() {
  qeuee = new int[n];
  maxSize = n;
}

rQeuee::~rQeuee() {
  delete[] qeuee;
}

bool rQeuee::empty() {
  return size == 0;  // colateralmente teremos last == fist.
}

int rQeuee::getSize() {
  return size;
}

int rQeuee::getMaxSize() {
  return maxSize;
}

int rQeuee::get(int i) {
  return qeuee[i];
}

// tentar fazer o resize. se nenhuma excessão for lançada pula os catches e salta para return true
bool rQeuee::reallocate(int newSize) {  // poderia ser feita retornando o ponteiro *qeuee tb (automatiamente NULL se falhase)
  try {
    int *temp = new int[newSize];  // a bad_alloc exception is automatically thrown in case it fails
    temp = qeuee;
    qeuee = new (nothrow) int[newSize];  // no exception thrown; the pointer is converted to NULL
    if (qeuee == NULL) {
      bad_alloc exception;
      throw exception;
    }
    qeuee = temp;
    temp = NULL;
  } catch (bad_alloc &exception) {  // pega a exceção bad_alloc lançada em qualquer dos dois resizes
    cout << exception.what() << endl;
    return false;
  }

  maxSize = newSize;
  // se não houveram excessões de bad_alloc lançadas em nenhum dos new
  return true;
}

int rQeuee::push(int x) {
  // Lista não vazia
  if (!empty() && last == maxSize) {
    // Se os índices iniciais já foram liberados:
    if (last == maxSize && size < maxSize && qeuee[last % size] == -1) {  // ! convencionando -1 = nulo. Mas melhor seria: " !(size <= maxsize) "      qeuee[last % size] = x;
      last = (last % size) + 1;
      qeuee[last] = x;
      last++;
      size++;
      return last;
    }
    // Assumindo que está cheia
    else if (last == maxSize && size == maxSize) {  // em tese a fila circular está lotada e size == maxSize
      reallocate(margin);
      qeuee[last] = x;
      last++;
      size++;
      return last;
    }
    // melhor caso, lista não vazia mas há espaço no próximo índice
    else {
      qeuee[last] = x;
      last++;
      size++;
      return last;
    }

  }  // Ou está vazia ou há espaço vago no próximo espaço do vetor (stricto sensus)
  else if (empty() || size < maxSize) {
    qeuee[last] = x;
    last++;
    size++;
    return last;
  }

  else {  // temporário !!!
    cout << "erro no push" << endl;
    exit(1);
  }
  return false;
}
