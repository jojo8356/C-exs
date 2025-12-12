#include <stdio.h>

int sommeTableau(int t[20], int N) {
    if (N == 0)
        return 0;
    return t[N-1] + sommeTableau(t, N-1);
}

int main() {
    int tab[20] = {1, 2, 3, 4, 5};
    int N = 5;

    int somme = sommeTableau(tab, N);
    printf("Somme = %d\n", somme);

    return 0;
}
