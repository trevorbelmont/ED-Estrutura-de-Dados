#include "fila_pilhada.hpp"

#include <iostream>

using namespace std;

// cria rQeuee com maxSize padrão.
rQeuee::rQeuee() {
  size = 0;
  first = last = size = 0;
  maxSize = 10;
  margin = (maxSize / 2) + 1;
  qeuee = new int[size];  // for safety
}

// cria rQeuee com maxSize especificado em n.
rQeuee::rQeuee(int n) : rQeuee() {
  qeuee = new int[n];
  maxSize = n;
  margin = (n / 2) + 1;
}

rQeuee::~rQeuee() {
  delete[] qeuee;
  // delete[] temp;
}

bool rQeuee::empty() {
  if (size == 0) {     // se está vazia
    last = first = 0;  // reseta a lista
    return true;
  }  // colateralmente teremos last == fist.
  else {
    return false;
  }
}

int rQeuee::get(int i) {
  return qeuee[first];
}

int rQeuee::getSize() {
  return size;
}

int rQeuee::getMaxSize() {
  return maxSize;
}

int rQeuee::front() {
  return qeuee[first];
}
int rQeuee::pos() {
  if (empty()) {
    return last % maxSize;  // poderia retornar apeans last pois empty()== true reseta lista
  } else {
    return last % maxSize;
  }
}

// tentar fazer o resize. se nenhuma excessão for lançada pula os catches e salta para return true
bool rQeuee::reallocate(int newSize) {  // poderia ser feita retornando o ponteiro *qeuee tb (automatiamente NULL se falhase)
  try {
    // temp é o ponteiro temporário padrão
    int *temp = new int[newSize];  // a bad_alloc exception is automatically thrown in case it fails
    temp = qeuee;
    qeuee = new int[newSize];  // no exception thrown; the pointer is converted to NULL

    qeuee = temp;
    temp = NULL;

    delete[] temp;
    cout << qeuee[0] << " " << qeuee[1];

    maxSize = newSize - 1;
  } catch (bad_alloc b) {
    cout << "Realocation tried and failed!" << endl;
  }
  //  se não houveram excessões de bad_alloc lançadas em nenhum dos new
  return true;
}

int rQeuee::push(int x) {
  if (size <= 0) {
    size = 1;
    qeuee[last % size] = x;
    last++;
    return last;
  } else if (size < maxSize) {
    // cout << "last é :" << last << endl;
    size++;
    qeuee[last % size] = x;

  } else if (reallocate((maxSize * 1.6) + 1)) {  // realoca timidamente: margin = o tamanho atual + metade do tamanho inicial (do construtor) + 1
    cout << "Qeuee has been reallocated and now comports  " << maxSize << " entries" << endl;
    size++;
    qeuee[last % size] = x;
  } else {
    return last;
  }
  return last++;
}

int rQeuee::pop() {
  try {
    if (empty()) {
      bad_alloc b;
      throw b;
    }
    if (size >= 1) {
      size--;
      int popped = front();
      qeuee[first] = 0;
      first++;
      return popped;
      // incrementa first e e retorna incrementado
    }

  } catch (bad_alloc b) {
    cout << "Can't pop from empty qeuee!" << endl;
    return 0;
  }
  return -404;
}

// output list horizontally (better for short lists)
void rQeuee::list() {
  for (int i = first; i < (first + size); i++) {
    cout << get(i % maxSize) << " ";
  }
  cout << endl;
  /* for (int i = 0; i < maxSize; i++) {
     if (first == i && !last == i) {
       cout << "^i";
     } else if (last == i && !first == i) {
       cout << "^l";
     } else if (first == i == last) {
       cout << "!";
     } else {
       cout << "  ";
     }
   }
   cout << endl;
   */
}

void rQeuee::Fifo2Lifo() {
  int tam = this->size;  // número real de entradas da fila.
  int temp[tam];
  for (int i = 1; i <= tam; i++) {
    temp[tam - i] = this->pop();
  }
  if (this->empty()) {
    // cout << "Desenfilerou completamente" << endl;
  }

  for (int i = 0; i < tam; i++) {
    (*this).push(temp[i]);
    // cout << temp[i] << " " << endl;
  }
}

// push dinâmico
// int rQeuee::push(int x) {
//   // Lista não vazia
//   if (!empty() && last == maxSize) {
//     // Se os índices iniciais já foram liberados:
//     if (last == maxSize && size < maxSize && qeuee[last % size] == -1) {  // ! convencionando -1 = nulo. Mas melhor seria: " !(size <= maxsize) "      qeuee[last % size] = x;
//       last = (last % size) + 1;
//       qeuee[last] = x;
//       last++;
//       size++;
//       return last;
//     }
//     // Assumindo que está cheia
//     else if (last == maxSize && size == maxSize) {  // em tese a fila circular está lotada e size == maxSize
//       reallocate(margin);
//       qeuee[last] = x;
//       last++;
//       size++;
//       return last;
//     }
//     // melhor caso, lista não vazia mas há espaço no próximo índice
//     else {
//       qeuee[last] = x;
//       last++;
//       size++;
//       return last;
//     }

//   }  // Ou está vazia ou há espaço vago no próximo espaço do vetor (stricto sensus)
//   else if (empty() || size < maxSize) {
//     qeuee[last] = x;
//     last++;
//     size++;
//     return last;
//   }

//   else {  // temporário !!!
//     cout << "erro no push" << endl;
//     exit(1);
//   }
//   return false;
// }
