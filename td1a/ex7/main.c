#include <stdio.h>

/* 12.
int main() {
  int a;
  int b;
  printf("Bonjour !\n\nVeuillez saisir le premier nombre: ");
  scanf("%d", &a);
  printf("Veuillez saisir le deuxième nombre: ");
  scanf("%d", &b);
  printf("\nCalculs:\n\n");
  printf("\t%d + %d = %d\n", a, b, a + b);
  printf("\t%d - %d = %d\n", a, b, a - b);
  printf("\t%d * %d = %d\n", a, b, a * b);
  float div = (float)a / (float)b;
  printf("\t%d / %d = %lf\n\nAu revoir :)\n", a, b, div);
}
*/

int main() {
  int a;
  int b;
  char ch;
  while (ch != 'N') {
    printf("Bonjour !\n\nVeuillez saisir le premier nombre: ");
    scanf("%d", &a);
    printf("Veuillez saisir le deuxième nombre: ");
    scanf("%d", &b);

    printf("\nCalculs:\n\n");
    printf("\t%d + %d = %d\n", a, b, a + b);
    printf("\t%d - %d = %d\n", a, b, a - b);
    printf("\t%d * %d = %d\n", a, b, a * b);
    double div = (double)a / (double)b;
    printf("\t%d / %d = %f\n\n", a, b, div);

    printf("Voulez-vous continuer ? (O/N) ");
    scanf(" %c", &ch);
    printf("Vous avez tapé: %c", ch);
  }
  printf("\nAu revoir :)\n");

  return 0;
}