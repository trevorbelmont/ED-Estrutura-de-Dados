#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double Expression::solvePostfix(Fila postFix) {
  Pilha<double> pNumbers;

  // Desinfileira fila com expressão pósfixa.
  // Fila.at(i) poderia ser usado para evitar desinfileirar a lista, caso a avaliação não fosse a última chamada no trabalho.
  for (int i = 0; i < postFix.size(); i++) {
    string s = postFix.at(i);

    // Se a entrada for um número, empilha na pilha de floats
    if (checkDigits(s)) {
      pNumbers.push(stod(s));
    }
    // Se não for um número e for um operador previsto.
    else if (checkOperator(s)) {
      // Lança exceção se não houverem operandos suficientes na pilha para calcular.
      if (pNumbers.size() < 2) {
        error e;
        e.message = "Erro!!! A expressão pósfixa armazenada não é válida!";
        throw e;
      }
      // desempilha e armazena os dois números no topo da pilha de floats
      float b = pNumbers.pop();
      float a = pNumbers.pop();
      // Calcula a operação indicada pelo operador e empilha o resultado na pilha de floats
      pNumbers.push(calculate(a, s[0], b));
    }
    // Se a entrada não for um operador previsto ou operando, lança exceção.
    else {
      error e;
      e.message = "Erro!!! A expressão pósfixa armazenada contem operador inválido ou não previsto!";
      throw e;
    }
  }  // Recha o loop para prosseguir com os retornos da função.

  // Lança exceção se não houver apenas um float (o resultado) na pilha de floats.
  if (pNumbers.size() != 1) {
    error e;
    e.message = "Erro!!! A expressão pósfixa armazenada é inválida!";
    throw e;
  }
  // Retorna o único float da pilha de floats: o resultado da expressão.
  return pNumbers.pop();
}

double Expression::calculate(double a, char op, double b) {
  switch (op) {
    case 'x':
      return a * b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      if (b == 0.0) {
        error e;
        e.message = "Erro!!! Tentativa de divisão por zero:  " + to_string(a) + op + to_string(b);
        throw(e);
      }

      return a / b;
      break;
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;

    default:
      error e;

      e.message = "Erro!!! O operador ";
      e.message += op;
      e.message += " é inválido ou não previsto.";
      throw e;
      break;
  }
}

Fila Expression::infix2Postfix(string infix) {
  Pilha<string> pOp;  // pilha que armazena operadores temporáriamente
  Fila fPostfix;      // Fila que comporta a expressão PÓSFIXA resultante

  Fila exp = string2qeuee(infix);
  // guarda o número de parênteses. Será incrementado a cada "(" e decrementado a cada ")". Deve resultar zero ao fim do carregamento..
  int par = 0;

  while (!exp.empty()) {
    string s = exp.pop();  // lê o próximo elemento da fila de string contendo a expressão

    if (checkDigits(s)) {  // Se for um número INTEIRAMENTE válido, adiciona na fila
      fPostfix.push(s);
    } else if (checkOperator(s)) {  // Se for um operador, empilha ou adiciona na fila

      // Dá flush na pilha de operadores enquanto eles tiverem maior prioridade que o próximo operador lido da expressão.
      while (!pOp.empty() && priority(pOp.top()) >= priority(s)) {
        fPostfix.push(pOp.pop());
      }
      pOp.push(s);
    } else if (s == "(") {  // Incrementa par e empilha o "(" na fila de operadores
      par++;
      pOp.push(s);
    } else if (s == ")") {  // Decrementa par e enfileira os operadores da fila de oP* até achar um "("
      par--;
      // Adiciona os operadores na fila pósfixa até que este operador seja um "("
      while (!pOp.empty() && pOp.top() != "(") {
        fPostfix.push(pOp.pop());
      }
      if (!pOp.empty()) pOp.pop();  // Se a pilha de operadores não estiver vazia, desempilha o abre parênteses.
    }
    // Se for um caso não previsto a expressão não é válida
    else {
      Fila e;
      e.push("NAO VALIDA");  // ¬ resolver exceção
      return e;
    }
  }

  // Aqui todas as entradas da fila contendo a expressão já foram lidas.
  // Caso o número de "(" seja diferente do número de ")", retorna NÂO VALIDO
  if (par != 0) {
    Fila e;
    e.push("NAO VALIDA");  // ¬ resolver exceção
    return e;
  }

  // Adiciona operadores restantes na pilha na fila
  while (!pOp.empty()) {
    fPostfix.push(pOp.pop());
  }
  return fPostfix;
}

Fila string2qeuee(string exp) {
  string *tempSplitted = new string[500];
  int tam = split(exp, ' ', tempSplitted);
  Fila aux(tam);
  aux = aux.loadQueue(tempSplitted, tam);
  delete[] tempSplitted;
  return aux;
}

int split(string mono, char delim, string *splitted) {
  stringstream ss(mono);
  string s;
  int i = 0;
  while (getline(ss, s, delim)) {
    // Ignora strings vazias ou espaços em branco. Útil, uma vez que a entrada contém espaços duplos.
    if (s != " " && s != "") {
      splitted[i] = s;
      i++;
    }
  }
  return i;
}

bool checkDigits(string s) {
  int pointCount = 0;  // contador do número de pontos numa string

  // Passa por todas os caractere da string
  for (char c : s) {
    int cint = int(c);  // cast c para int

    // Se c algum carectere de s NÃO está entre '0' (48) e '9' (57) E tb não é '.' (46),
    // retorna falso - pois s não está no formato numérico esparado
    if (!(cint >= 48 && cint <= 57) && !(cint == 46)) {
      return false;
    }
    if (cint == 46) pointCount++;
  }
  // se todos caracteres da string são dígitos ou pontos (e há no máximo um ponto) retorna true
  return (pointCount <= 1);
}

int priority(string s) {
  if (s == "x" || s == "*" || s == "/")
    return 2;
  else if (s == "+" || s == "-")
    return 1;
  else
    return 0;
}

bool checkOperator(string s) {
  return (s == "x" || s == "*" || s == "/" || s == "+" || s == "-");
}
