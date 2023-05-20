#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int *pointer;

  cout << "pointer[3] é null : 0º" << endl;
  cout << pointer[3] << endl;  // imprime lixo - espaço nem alocado ainda

  pointer = new int[5];  // aloca e atribui 0s a todos automaticamente

  cout << "pointer[3] é null : 1º" << endl;
  cout << pointer[3] << endl;  // vetor está zerado

  for (int i = 0; i < 5; i++) {
    pointer[i] = i * 2;
  }

  cout << " pointer[3] é null : 2º" << endl;
  cout << pointer[3] << endl;  //  valores foram atribuídos no for

  // teste de resize realocamento de memória - sem perda de dados
  int *tempPointer = new int[10];
  tempPointer = pointer;  // o vetor do tamanho querido é atribuído ao vetor que quero realocar
  pointer = new int[10];  // realoco o vetor que quero no resize
  pointer = tempPointer;  // reatribuou o vetor original a variável temporária (que guardou seu endereço)
  tempPointer = NULL;     // DESASSOCIO O PONTEIRO TEMPORÁRIO DO MEU PONTEIRO (para desalocar ambos)

  delete[] tempPointer;  // Desaloco o temporário.

  *(pointer + 6) = -24;

  if (tempPointer != NULL) {
    cout << " tempPointer = ";

    // imprime com tempPointer
    for (int i = 0; i < 10; i++) {
      cout << tempPointer[i] << " ";
    }
    cout << endl;
  } else if (tempPointer == NULL) {
    cout << "tempPointer == NULL :::::" << endl
         << endl;
  }

  // pointer = new int + 2; // também zera o pontero (array, por assim dizer)
  // pointer[9] = 100;
  // pointer[11] += pointer[10] += pointer[9];
  cout << " Pointer = ";
  // imprime com pointer (depois de readimensioando no "re" new)
  for (int i = 0; i < 12; i++) {
    cout << pointer[i] << " ";
  }
  cout << endl;

  delete[] pointer;  // desaloca

  if (pointer == NULL) {  // não passa nesta condicional :-(
    cout << " pointer é null : 3º" << endl;
    cout << pointer[3] << endl;
  } else {
    cout << " pointer[3] desalocado NÂO PASSA no teste de NULL" << endl
         << "seu valor é: " << pointer << ". últimoº" << endl;
    cout << "pointer[3], por exemplo é:" << pointer[3] << endl << endl;
  }
  if (tempPointer == NULL) {  // não passa nesta condicional :-(
    cout << " Porém, tempPointer SIM PASSA em teste de NULL, pois NULL lhe foi atribuído" << endl;
    cout << pointer[3] << endl;
  }

  return 0;
}