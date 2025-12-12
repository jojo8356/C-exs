#include <stdio.h>

int nbOccurrencesRec(char t[21], int N, char C) {
    if (N == 0)
        return 0;
    int count = nbOccurrencesRec(t, N - 1, C);
    if (t[N - 1] == C)
        count++;
    return count;
}

int main() {
    char chaine[21] = "abracadabra";
    char C = 'a';
    int N = 11;

    int occ = nbOccurrencesRec(chaine, N, C);
    printf("Le caractère '%c' apparaît %d fois\n", C, occ);

    return 0;
}
