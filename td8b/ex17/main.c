#include <stdio.h>

void rubanSicilien(int nb, int t[30], int N, int pos) {
    if (pos >= N)
        return;

    t[pos] = nb;

    if (pos + 1 < N) {
        int suivant;
        if (nb % 2 == 0)
            suivant = nb / 2;
        else
            suivant = 3 * nb + 1;

        rubanSicilien(suivant, t, N, pos + 1);
    }
}

int main() {
    int t[30];
    int N = 10;
    int nbDepart = 7;

    rubanSicilien(nbDepart, t, N, 0);

    printf("Ruban Sicilien : ");
    for (int i = 0; i < N; i++)
        printf("%d ", t[i]);
    printf("\nDernière valeur : %d\n", t[N - 1]);

    return 0;
}
