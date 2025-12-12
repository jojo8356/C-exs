#include <stdio.h>

int symmetriqueRecursif(int t[10], int taille, int n) {
    if (n >= taille / 2)
        return 1;
    if (t[n] != t[taille - n - 1])
        return 0;
    return symmetriqueRecursif(t, taille, n + 1);
}

int main() {
    int tab[10] = {1, 2, 3, 2, 1};
    int taille = 5;

    if (symmetriqueRecursif(tab, taille, 0))
        printf("Le tableau est symétrique\n");
    else
        printf("Le tableau n'est pas symétrique\n");

    return 0;
}
