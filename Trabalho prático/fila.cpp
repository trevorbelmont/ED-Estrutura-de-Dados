#include "fila.hpp"

#include <string>
#include <sstream>


using namespace std;

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

bool Fila::push(string k) {
  if (full()) {
    return false;
  }
  c_[size_] = k;
  size_++;
  return true;
}

string Fila::pop() {
  if (empty()) {
    return "!";  // Tratar a Exceção ¬
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

string Fila::front() {
  if (empty()) {
    return "!";  // Tratar exceção. ¬
  }
  return c_[cursor];
}

Fila Fila::exp2qeuee(string s) {
  Fila aux(s.length());

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ')
      continue;
    else {
      string c = s[i];
      aux.push(c);
    }
  }

  return aux;
}
 

  Fila::~Fila() {
    // delete[] c_;
  }
