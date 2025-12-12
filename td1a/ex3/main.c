#include <stdio.h>

/* 4.
int main() {
  int a;
  printf("Entrer un nombre:\n");
  scanf("%d", &a);
  printf("Vous avez entré le nombre %d\n", a);

  return 0;
}
*/

int main() {
  int a;
  int b;
  printf("Entrez deux nombres:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  printf("Vous avez entré a=%d et b=%d\n", a, b);

  return 0;
}