#include <stdio.h>

/*
int main(){
    int n, somme = 0;
    printf("Entrer n:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        somme += i;
    printf("somme des %d premiers entiers = %d\n", n, somme);
}
*/

int main(){
    int n, somme = 1;
    printf("Entrez un entier positif : ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        somme *= i;
    printf("Factorielle de %d est %d\n", n, somme);
}