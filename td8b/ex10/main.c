#include <stdio.h>

void inverserTableau(int t[10], int taille, int n) {
    if (n >= taille / 2)
        return;

    int temp = t[n];
    t[n] = t[taille - n - 1];
    t[taille - n - 1] = temp;

    inverserTableau(t, taille, n + 1);
}

int main() {
    int tab[10] = {1,2,3,4,5};
    int taille = 5;

    inverserTableau(tab, taille, 0);

    printf("Tableau inversé : ");
    for (int i = 0; i < taille; i++)
        printf("%d ", tab[i]);
    printf("\n");

    return 0;
}
