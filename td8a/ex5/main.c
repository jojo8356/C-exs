#include <stdio.h>

int compteurRec = 0;
int compteurRecRapide = 0;

unsigned long long puissanceIt(unsigned long long x, unsigned long long n) {
    unsigned long long resultat = 1;
    for (unsigned long long i = 0; i < n; i++) {
        resultat *= x;
    }
    return resultat;
}

unsigned long long puissanceRec(unsigned long long x, unsigned long long n) {
    compteurRec++;
    if (n == 0)
        return 1;
    return x * puissanceRec(x, n - 1);
}

unsigned long long puissanceRecRapide(unsigned long long x, unsigned long long n) {
    compteurRecRapide++;
    if (n == 0)
        return 1;

    unsigned long long p = puissanceRecRapide(x, n / 2);

    unsigned long long result = p * p;
    if (n % 2 != 0)
        result *= x;
    return result;
}

int main() {
    unsigned long long x = 2, n = 62;

    printf("puissanceIt(%llu, %llu) = %llu\n", x, n, puissanceIt(x, n));
    printf("puissanceRec(%llu, %llu) = %llu\n", x, n, puissanceRec(x, n));
    printf("puissanceRecRapide(%llu, %llu) = %llu\n", x, n, puissanceRecRapide(x, n));

    printf("\nNombre de multiplications (classique) : %d\n", compteurRec);
    printf("Nombre de multiplications (rapide)    : %d\n", compteurRecRapide);

    return 0;
}
