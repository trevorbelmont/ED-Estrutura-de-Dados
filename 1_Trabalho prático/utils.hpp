#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;

struct error {
  string message;
};

class Expression {
 private:
  Fila f_;
  bool isPostfix_;
  bool valid_;
  string original_;
  string infix_;
  double result_ = 0.0;

  //  Cria uma expressão sem iniciar
  Expression();

  // carrega a representação interna com a string exp.
  Expression(string exp);

    // Calcula a operação binária definida pelo char "operador".
  // Lança exceções se houver divisão por zero ou operador não previsto.
  double calculate(double a, char operador, double b);

  // Retorna o resulado da expressão pósfixa carregada na fila sem desinfileirar ela.
  // Lança exceções caso a expressão seja inválida.
  double solvePostfix(Fila postFix);

  // Método que recebe uma string contendo uma expressão INFIXA e retorna uma fila carregada com uma expressão PÓSFIXA.
  // Esse método também checa a validade dos operandos e dos operadores previstos, bem como se o disposição de parênteses é válido.
  // Baseado no Shunting Yard Algorithm de Dijkstra.
  Fila infix2Postfix(string infix);

 public:
};

// Separa uma string monolítica, "mono", em múltiplas substrings delimitadas pelo character 'delim' e às armazena no vetor "splitted".
// Ignora espaços em branco. Retorna o número de strings carregadas.
int split(string monolitica, char delim, string *splitted);

// Retorna uma fila carregada com as subsrings de "exp"
Fila string2qeuee(string exp);

// Checa se todos os caracteres da string de números, s, são dígitos ou pontos e se há no máximo um ponto na string.
bool checkDigits(string s);

// Retorna a prioridade do operador (retorna 0 se não for um operador previsto).
int priority(string s);

// Verifica se a string s carrega um operador previsto (x*/+-).
bool checkOperator(string s);

#endif