#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    int penultimo = 1;
    int ultimo = 2;
    int atual;

    if (n <= 2) {
        return n;
    }

    for (int i = 3; i <= n; i++) {
        atual = penultimo + ultimo;
        penultimo = ultimo;
        ultimo = atual;
    }

    return ultimo;
}

int main() {
    int n, number;

    printf("Quantos degraus tem a escada? ");
    scanf("%d", &n);
    number = climbStairs(n);
    
    printf("Existem %d maneira(s) de subir a escada.\n", number);
}