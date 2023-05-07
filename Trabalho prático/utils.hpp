#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#include "fila.hpp"
#include "pilha.hpp"

//(=(40)   0=(48)   9=(57)   +=(43)   -=(45)   *=(42)   /=(47)   )=(41)
using namespace std;

int split(string str, char delim, string *splitted);

Fila string2qeuee(string exp);
#endif