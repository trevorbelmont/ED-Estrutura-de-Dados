#include <stdlib.h>
#include <stdint.h>

#define A_SIZE 26

int main() {
    char* alphabet = calloc(A_SIZE + 1, sizeof(char));

    for(uint8_t i = 0; i < A_SIZE; i++) {
        *(alphabet + i) = 'A' + i;
    }
    *(alphabet + A_SIZE) = '\0'; //null-terminate the string?

    free(alphabet);
    return 0;
}

