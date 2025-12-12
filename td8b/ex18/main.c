#include <stdio.h>

void sautsPuces(int nb, int *A, int *B, int nbA, int nbB) {
    if (nb == 0)
        return;

    *A = (*A + nbA) % 17;
    *B = (*B - nbB + 17) % 17;

    sautsPuces(nb - 1, A, B, nbA, nbB);
}

int main() {
    int A = 0, B = 0;
    int nbSauts = 5;
    int nbA = 3, nbB = 2;

    sautsPuces(nbSauts, &A, &B, nbA, nbB);

    printf("Position finale : A = %d, B = %d\n", A, B);

    return 0;
}
