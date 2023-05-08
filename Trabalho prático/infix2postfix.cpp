
#include <iostream>
#include <string>

#include "utils.hpp"

using namespace std;

// Função que recebe uma fila carregado com uma expressão INFIXA e retorna uma fila carregada com uma expressão PÓSFIXA.
// Baseada no Shunting Yard Algorithm de Dijkstra.
Fila infix2Postfix(string infix) {
  Pilha pOp;      // pilha que armazena operadores temporáriamente
  Fila fPostfix;  // Fila que comporta a expressão PÓSFIXA resultante

  Fila exp = string2qeuee(infix);

  while (!exp.empty()) {
    string s = exp.pop();  // lê o próximo elemento da fila de string contendo a expressão

    if (checkDigits(s)) {  // Se for um número INTEIRAMENTE válido, adiciona na fila
      fPostfix.push(s);
    } else if (checkOperator(s)) {  // Se for um operador, empilha ou adiciona na fila

      // Dá flush na pilha de operadores enquanto eles tiverem maior prioridade que o próximo operador lido da expressão.
      while (!pOp.empty() && priority(pOp.get()) >= priority(s)) {
        fPostfix.push(pOp.pop());
      }
      pOp.insert(s);
    } else if (s == "(") {  // Abre parênteses, empilha
      pOp.insert(s);
    } else if (s == ")") {  // Fecha parênteses, adiciona operadores na fila até encontrar o abre parênteses
      while (!pOp.empty() && pOp.get() != "(") {
        fPostfix.push(pOp.pop());
      }
      pOp.pop();  // Remove o abre parênteses
    } else {
      Fila e;
      e.push("NAO VALIDA");
      return e;
    }
  }

  // Adiciona operadores restantes na pilha na fila
  while (!pOp.empty()) {
    fPostfix.push(pOp.pop());
  }
  return fPostfix;
}
//  5 / ( ( 1 + 2 ) * 4 ) - 3
//  5 + ( ( 1 + 2 ) x 4 ) - 3
// Função principal
int main() {
  string exp;
  cout << "Digite a expressao em notacao infixa: ";
  getline(cin, exp);

  Fila postfix = infix2Postfix(exp);

  cout << "Expressao em notacao posfixa: " << postfix.toString("  ") << endl;

  return 0;
}
