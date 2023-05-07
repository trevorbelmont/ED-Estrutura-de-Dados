#ifndef COMPILADOR
#define COMPILADOR

#include <iostream>
#include <string>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;

class Compilador {
 private:
  Pilha p_;
  Fila f_;

 public:
  // Carrega a expressão INFIXA e retorna a expressão carregada
  string loadInfix(string s);

  // Carrega a expressão PÓSFIXA em uma fila e retorna a expressão carregada
  string loaddPostfix(string s);

  //Converte a representação interna para notação pósfixa e retorna como string;
  string exp2postfix( Fila k);
};

#endif