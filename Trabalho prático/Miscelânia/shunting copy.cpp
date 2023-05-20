#include <iostream>
#include "pilha.hpp"
#include "fila.hpp"
#include <string>

using namespace std;

// Função que verifica se um caractere é um operador
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função que retorna a prioridade de um operador
int getPriority(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// Função que transforma uma expressão in-fixa para pós-fixa
string infixToPostfix(string expression) {
    stack<char> opStack;
    queue<char> outputQueue;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isdigit(c)) { // Se for um número, adiciona na fila
            outputQueue.push(c);
        }
        else if (isOperator(c)) { // Se for um operador, empilha ou adiciona na fila
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c)) {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.push(c);
        }
        else if (c == '(') { // Abre parênteses, empilha
            opStack.push(c);
        }
        else if (c == ')') { // Fecha parênteses, adiciona operadores na fila até encontrar o abre parênteses
            while (!opStack.empty() && opStack.top() != '(') {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.pop(); // Remove o abre parênteses
        }
    }

    // Adiciona operadores restantes na pilha na fila
    while (!opStack.empty()) {
        outputQueue.push(opStack.top());
        opStack.pop();
    }

    // Transforma a fila em string
    while (!outputQueue.empty()) {
        postfix += outputQueue.front();
        outputQueue.pop();
    }

    return postfix;
}
//  5 / ((1 + 2) * 4 ) - 3
//  5 + ((1 + 2) * 4 ) - 3
// Função principal
int main() {
    string expression;
    cout << "Digite a expressao em notacao infixa: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    cout << "Expressao em notacao posfixa: " << postfix << endl;

    return 0;
}
