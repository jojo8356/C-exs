#include <stdio.h>

typedef struct {
    int num;
    int den;
} Rationnel;

int pgcd(int a, int b) {
    if (b == 0)
        return (a < 0) ? -a : a; // abs value
    return pgcd(b, a % b);
}

void simplifier(Rationnel *r) {
    int d = pgcd(r->num, r->den);
    r->num /= d;
    r->den /= d;
    if (r->den < 0) {
        r->den = -r->den;
        r->num = -r->num;
    }
}

Rationnel lireRationnel() {
    Rationnel r;
    printf("    Entrez le numérateur (un entier): ");
    scanf("%d", &r.num);

    do {
        printf("    Entrez le dénominateur (un entier != 0): ");
        scanf("%d", &r.den);
        if (r.den == 0)
            printf("         <---- Le dénominateur ( = 0) n'est pas valide > \n");
    } while (r.den == 0);

    simplifier(&r);
    printf("%d/%d \n", r.num, r.den);
    return r;
}

Rationnel sommeRationnel(Rationnel r1, Rationnel r2) {
    Rationnel res;
    res.num = r1.num * r2.den + r2.num * r1.den;
    res.den = r1.den * r2.den;
    simplifier(&res);
    return res;
}

int main() {
    Rationnel r1, r2, somme;

    printf("Lire le premier rationnel:\n");
    r1 = lireRationnel();

    printf("Lire le deuxieme rationnel:\n");
    r2 = lireRationnel();

    somme = sommeRationnel(r1, r2);

    printf("La somme des deux rationnels est:\n");
    printf("        %d/%d + %d/%d = %d/%d\n",
           r1.num, r1.den, r2.num, r2.den, somme.num, somme.den);

    return 0;
}
