#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;

struct error {
  string message;
};

// Separa uma string monolítica, "mono", em múltiplas substrings delimitadas pelo character "delim" e as armazena no vetor "splitted".
// Ignora espaços em branco. Retorna o número de strings carregada.
int split(string monolitica, char delim, string *splitted);

// Retorna uma fila carregada com as subsrings de "exp"
Fila string2qeuee(string exp);

// Checa se todos os caracteres da string de números, s, são dígitos ou pontos e se há no máximo um ponto na string.
bool checkDigits(string s);

// Retorna a prioridade do operador (retorna 0 se não for um operador previsto).
int priority(string s);

// Verifica se a string s carrega um operador previsto (x*/+-).
bool checkOperator(string s);

// Calcula a operação binária definida pelo char "operador".
// Lança exceções se houver divisão por zero ou operador não previsto.
double calculate(double a, char operador, double b);

// Retorna o resulado da expressão pósfixa carregada na fila sem desinfileirar ela.
// Lança exceções caso a expressão seja inválida.
double solvePostfix(Fila postFix);

Fila infix2Postfix(string infix);

#endif