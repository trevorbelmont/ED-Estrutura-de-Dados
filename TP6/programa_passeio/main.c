#include <stdio.h>

#include "passeio.h"

int main() {
    int i = 0;
    while (i < 3) {
        int x = 0, y = 0;
        printf("digite as coordenadas: ");
        scanf("%d %d", &x, &y);
        passeio(x,y);
        i++;
    }
    return 0;
}