

#include "pilha.hpp"

Pilha::Pilha() {
  // c_ = new char[1000];
  size_ = 0;
  max_size_ = 1000;
}

Pilha::Pilha(int tam) {
  // c_ = new char[tam];
  max_size_ = tam;
  size_ = 0;
}

char Pilha::pop() {
  if (empty()) {
    return '!';  // Tratar a Exceção ¬
  }
  size_--;
  return c_[size_];
}

bool Pilha::insert(char x) {
  if (full()) {
    return false;
  }
  c_[size_] = x;
  size_++;
  return true;
}

bool Pilha::empty() {
  return size_ == 0;
}

bool Pilha::full() {
  return size_ == max_size_;
}

int Pilha::size() {
  return size_;
}

char Pilha::get() {
  if (empty()) {
    return '!';  // Tratar exceção. ¬
  }
  return c_[size_ - 1];
}

Pilha::~Pilha() {
  // delete[] c_;
}
