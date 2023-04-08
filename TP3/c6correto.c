#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct _List {
  int32_t* data;
  int32_t length;
};
typedef struct _List List;

List* resizeArray(List* array) {
  int32_t* dPtr = array->data;

  int quantos = 15;

  //  dPtr = realloc(dPtr, quantos * sizeof(int32_t)); //doesn't update array->data
  // array->data = realloc(array->data, quantos * sizeof(int32_t));

  dPtr = calloc(quantos, sizeof(int32_t));  // doesn't update array->data
  array->data = realloc(array->data, sizeof(dPtr));
  
  //checa se realmente conseguiu reallocar o vetor.
  if (array->data == NULL ){
    exit(1);
  }
  free(dPtr);
  return array;
}

int main() {
  List* array = calloc(1, sizeof(List));
  array->data = calloc(10, sizeof(int32_t));
  array = resizeArray(array);

  free(array->data);
  free(array);
  return 0;
}
