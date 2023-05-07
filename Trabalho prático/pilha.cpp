#include "pilha.hpp"

#include <string>

using namespace std;

Pilha::Pilha() {
  size_ = 0;
  max_size_ = 1000;
}

Pilha::Pilha(int tam) {
  max_size_ = tam;
  size_ = 0;
}

string Pilha::pop() {
  if (empty()) {
    return "!";  // Tratar a Exceção ¬
  }
  size_--;
  return s_[size_];
}

bool Pilha::insert(char x) {
  if (full()) {
    return false;
  }
  s_[size_] = x;
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

string Pilha::get() {
  if (empty()) {
    return "!";  // Tratar exceção. ¬
  }
  return s_[size_ - 1];
}

Pilha::~Pilha() {
  // delete[] c_;
}
