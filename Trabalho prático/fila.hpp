#ifndef FILA_HPP
#define FILA_HPP
#include <string>

using namespace std;

class Fila {
 private:
  string c_[1000];  // vetor que comporta a fila de caracteres;
                  // ¬ resolver questão do alocamento dinâmico

  int size_;      // o tamanho utilizado da fila.
  int max_size_;  // o tamanho máximo da fila.
  int cursor;     // o índice para o primeiro elemento da fila;

 public:
  // Cria fila padrão (máximo 1000 caracteres).
  Fila();

  // Cria fila com máximo de tam caracteres.
  Fila(int tam);

  // Retorna e remove o próximo caracter.
  string pop();

  // Enfileira um elemento. Retorna true se enfileirou com êxito
  bool push(string x);

  // Retorna o próximo elemento sem removê-lo.
  string front();

  // Retorna true se a fila estiver vazia.
  bool empty();

  // Retorna true se a fila tiver alcançado o tamanho máximo.
  bool full();

  // Retorna o tamanho atual da fila.
  int size();

  // Lẽ a expressão da s a carrega numa fila.
  Fila exp2qeuee(string s);

  // Desaloca memória e Destrói a fila.
  ~Fila();
};
#endif