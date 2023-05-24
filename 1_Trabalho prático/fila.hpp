#ifndef FILA_HPP
#define FILA_HPP
#include <string>

using namespace std;

class Fila {
 private:
  string s_[500];  // vetor que comporta a fila de strings;
                   // ¬ resolver questão do alocamento dinâmico

  int size_;      // o tamanho utilizado da fila. É também o próximo índice disponível - se a fila não estiver cheia.
  int max_size_;  // o tamanho máximo da fila.
  int first_;     // o índice para o primeiro elemento da fila;
  int last_;

 public:
  // Cria fila padrão (máximo 1000 strings).
  Fila();

  // Cria fila com máximo de tam strings.
  Fila(int tam);

  // Retorna e remove o primeiro string da fila.
  string pop();

  // Enfileira um elemento. Retorna true se enfileirou com êxito
  bool push(string x);

  // Retorna o próximo elemento sem removê-lo.
  string front();

  // Retorna a string na posição especificada sem destruí-la.
  // Anlálogo ao método deque.at(i) (método "at" da double ended queue) da stl.
  string at(int i);

  // Retorna true se a fila estiver vazia.
  bool empty();

  // Retorna true se a fila tiver alcançado o tamanho máximo.
  bool full();

  // Retorna o tamanho atual da fila.
  int size();

  // Lê um array de strings e os enfileira
  Fila loadQueue(string *s, int tam);

  // Retorna uma string contendo todas as entradas da fila interpoladas pelo "separator".
  // Caso nenhuma string separadora seja especificada, um espaço em branco será utilizado.
  string toString(string separator = " ");

  // Limpa e reinicia a fila.
  void clear();

  // Desaloca memória e Destrói a fila.
  ~Fila();
};
#endif