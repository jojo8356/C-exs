#include <stdio.h>

/* 6.
int main() {
  int a = 42;
  char b = 'A';
  double c = 3.14;
  printf("Entier : %d, Caractère : %c, Réel : %lf\n", a, b, c);
}
*/

/* 7.
// déclaration de la variable ch1 de type char
char ch1;
// affectation de la valeur 'A' à la variable ch1
ch1 = 'A';
// définition de la variable ch2 de type char
char ch2 = 'B';
*/

int main() {
  int a;
  int b;
  printf("Entrez deux entiers: ");
  scanf("%d", &a);
  scanf("%d", &b);
  printf("Somme : %d, Produit : %d\n", a + b, a * b);

  return 0;
}