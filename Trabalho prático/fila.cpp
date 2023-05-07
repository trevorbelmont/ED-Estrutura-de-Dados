#ifndef FILA_HPP
#define FILA_HPP

#include "fila.hpp"

Fila::Fila() {
  // c_ = new char[1000];
  size_ = 0;
  max_size_ = 1000;
  cursor = 0;
}

Fila::Fila(int tam) {
  // c_ = new char[tam];
  max_size_ = tam;
  size_ = 0;
  cursor = 0;
}

bool Fila::push(char k) {
  if (full()) {
    return false;
  }
  c_[size_] = k;
  size_++;
  return true;
}

char Fila::pop() {
  if (empty()) {
    return '!';  // Tratar a Exceção ¬
  }
  size_--;
  return c_[cursor++];
}

bool Fila::empty() {
  return size_ == 0;
}

bool Fila::full() {
  return size_ == max_size_;
}

int Fila::size() {
  return size_;
}

char Fila::front() {
  if (empty()) {
    return '!';  // Tratar exceção. ¬
  }
  return c_[cursor];
}

Fila::~Fila() {
  // delete[] c_;
}

#endif