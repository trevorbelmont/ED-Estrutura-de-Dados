#include <stdlib.h>
#include <stdint.h>

#define TAM 27

int main() {
    char* destination = calloc(TAM, sizeof(char));
    char* source = malloc(TAM * sizeof(char));

    for(uint8_t i = 0; i < TAM; i++) {
        *(destination + i) = *(source + i); //Look at the last iteration.
    }

    free(destination);
    free(source);
    return 0;
}

