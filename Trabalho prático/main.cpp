#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// carrega todas as bibliotecas necessárias
#include "utils.hpp"
using namespace std;

int testaCalculate() {
  while (1 > 0) {
    float a, b;

    cout << "enter a and b" << endl;
    cin >> a;
    cin >> b;
    cout << "enter operator" << endl;
    char op;
    cin >> op;
    try {
      cout << fixed << setprecision(6) << calculate(a, op, b) << endl;
    } catch (error e) {
      cout << e.message << endl;
    }
  }
  return 0;
}

int main() {
  cout << fixed << setprecision(6);  // Define precisão para o programa inteiro (até alteração)
  string expPostfix = "6.921287  9.364338  *  5.038233  -  2.223147  1.513019  *  /  8.621375  3.514391  1.044921  /  -  8.788044  /  6.018780  1.110416  /  *  *  4.004222  +  2.544881  /  0.672451  3.272697  +  0.108365  0.257409  -  +  /  7.300551  /  2.141078  4.770387  3.894807  2.296521  +  +  3.839127  +  /  - ";
  // RESOLVE # 0.729268

  try {
    Fila f = string2qeuee(expPostfix);
    cout << "Avaliação pósfixa " << solvePostfix(f) << endl;

    f.clear();
    expPostfix = "2.599367  9.647195  9.673411  9.050032  /  6.358308  -  8.651174  *  4.875167  2.911182  5.348410  2.736445  +  5.191413  *  -  -  *  *  1.915312  5.548351  2.050359  0.943320  +  *  +  +  5.181741  5.625093  *  *  8.694984  3.686034  /  9.440571  7.117509  /  +  -  9.446373  8.978700  /  3.580536  +  +  +  5.250495  1.305610  /  *  0.441742  6.502549  7.095268  4.133539  /  -  *  4.930346  2.550228  /  3.125103  *  4.950563  *  *  *  6.550852  6.671211  1.809183  +  /  3.824251  +  *  0.923045  4.509118  6.480367  /  0.074564  /  4.707001  -  +  4.743344  3.905694  2.327981  *  *  1.462779  -  *  +  ";
    // RESOLVE # -660219339.585214;
    
    f = string2qeuee(expPostfix);
    cout << "Avaliação pósfixa " << solvePostfix(f) << endl;

    f.clear();
    string expInfix = "( ( ( ( ( ( ( ( ( ( ( 6.430555 ) + ( ( 3.031694 ) / ( ( 6.240371 ) + ( ( ( 9.615488 ) + ( 0.391192 ) ) + ( 3.731624 ) ) ) ) ) + ( ( 3.146386 ) * ( 4.059826 ) ) ) / ( ( 9.476876 ) + ( ( ( 3.962499 ) / ( ( 5.579795 ) / ( 1.759955 ) ) ) - ( 1.688967 ) ) ) ) - ( 9.129420 ) ) + ( ( 9.326241 ) - ( ( 7.437738 ) * ( ( ( 4.704018 ) * ( 6.499125 ) ) * ( 6.389916 ) ) ) ) ) - ( 7.462131 ) ) + ( ( ( 9.911150 ) - ( 4.284252 ) ) * ( ( 4.203145 ) + ( ( ( 2.297352 ) / ( 9.094913 ) ) - ( 3.267839 ) ) ) ) ) - ( ( ( ( 7.096241 ) - ( 0.211192 ) ) + ( 4.551526 ) ) + ( 7.665444 ) ) ) + ( ( ( ( ( 1.765473 ) + ( 4.631388 ) ) / ( 1.236112 ) ) + ( ( 2.247799 ) - ( 3.926616 ) ) ) - ( ( ( 9.456899 ) - ( ( 7.511044 ) / ( ( 4.742804 ) * ( 8.997228 ) ) ) ) - ( 4.557919 ) ) ) ) - ( ( ( 7.674042 ) + ( ( 6.871605 ) + ( ( 1.445841 ) + ( 3.060410 ) ) ) ) - ( ( ( 6.362677 ) - ( ( 3.665044 ) / ( 6.127738 ) ) ) - ( 2.722264 ) ) ) )";
    // RESOLVE # -1487.758778
    f = infix2Postfix(expInfix);

    cout << "Avaliação Infixa " << fixed << setprecision(6) << solvePostfix(f) << endl;
  } catch (error e) {
    cout << e.message << endl;
  }
  return 0;
}

// 5 + ( ( 1 + 2 ) * 4 ) - 3