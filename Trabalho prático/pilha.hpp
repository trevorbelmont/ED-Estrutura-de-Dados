#ifndef PILHA_HPP
#define PILha_HPP

#include <string>
using namespace std;

template <typename Tipo>  // O tipo "Tipo" para a classe genérica
class Pilha {
 private:
  Tipo t_[1000];  // vetor que comporta pilha de de Tipos;
  // ¬ Sobrecarregar operador > e < e =

  int size_;      // o tamanho utilizado da pilha.
  int max_size_;  // o tamanho máximo da pilha.

 public:
  // Cria pilha padrão (máximo 1000 caracteres).
  Pilha();

  // Cria pilha com máximo de tam caracteres.
  Pilha(int tam);

  // Desempilha retornando o caractere desempilhado.
  Tipo pop();

  // Insere caracter no topo da pilha. Retorna true se inseriu com sucesso.
  bool push(Tipo t);

  // Retorna o elemento no topo da pilha sem desempilhar.
  Tipo top();

  // Retorna true se a pilha estiver vazia.
  bool empty();

  // Retorna true se a pilha estiver no tamanho máximo
  bool full();

  // Retorna o tamanho atual da lista
  int size();

  // Desaloca memória e Destrói a pilha.
  ~Pilha();
};

template <typename Tipo>
Pilha<Tipo>::Pilha() {
  size_ = 0;
  max_size_ = 1000;
}

template <typename Tipo>
Pilha<Tipo>::Pilha(int tam) {
  max_size_ = tam;
  size_ = 0;
}

template <typename Tipo>
Tipo Pilha<Tipo>::pop() {
  if (empty()) {
    return NULL;  // Tratar a Exceção ¬
  }
  size_--;
  return t_[size_];
}
template <typename Tipo>
bool Pilha<Tipo>::push(Tipo t) {
  if (full()) {
    return false;
  }
  t_[size_] = t;
  size_++;
  return true;
}

template <typename Tipo>
bool Pilha<Tipo>::empty() {
  return size_ == 0;
}
template <typename Tipo>
bool Pilha<Tipo>::full() {
  return size_ == max_size_;
}

template <typename Tipo>
int Pilha<Tipo>::size() {
  return size_;
}

template <typename Tipo>
Tipo Pilha<Tipo>::top() {
  if (empty()) {
    return NULL;  // Tratar exceção. ¬
  }
  return t_[size_ - 1];
}

template <typename Tipo>
Pilha<Tipo>::~Pilha() {
  // delete[] c_;
}

#endif