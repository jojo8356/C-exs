#include <stdio.h>
#include <stdlib.h>

#include "tools/tools.h"

/*
int main() {
  int a = 49;
  int b = 51;

  // Affichage des incrémentations/décrémentations
  printf("%d + 1 = %d\n", a, increase(a));
  printf("%d - 1 = %d\n", b, decrease(b));

  // Affichage des comparaisons
  printf("%d est strictement supérieur à %d : %s\n", a, b,
         greaterThan(a, b) ? "vrai" : "faux");
  printf("%d est strictement inférieur à %d : %s\n", a, b,
         lowerThan(a, b) ? "vrai" : "faux");
  printf("%d est égal à %d : %s\n", a, b, equalTo(a, b) ? "vrai" : "faux");
  return 0;
}
*/

/*
int main() {
  int a = -21;
  int b = 7;
  printf("%d est multiple de %d : %s\n", a, b,
         isMultiple(a, b) ? "vrai" : "faux");
  b = 6;
  printf("%d est multiple de %d : %s\n", a, b,
         isMultiple(a, b) ? "vrai" : "faux");
  printf("La valeur absolue de %d est %d\n", a, absValue(a));
  printf("La valeur absolue de %d est %d\n", b, absValue(b));
  return 0;
}
*/

int main() {
  int a = 1, b = 1;
  while (1) {
    printf("Entrez deux entiers (0 0 pour arrêter) :\n");
    if (scanf("%d %d", &a, &b) != 2) {
      printf("Entrée invalide.\n");
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
      continue;
    }
    if (a == 0 && b == 0) break;
    printf("%d est strictement supérieur à %d : %s\n", a, b,
           greaterThan(a, b) ? "vrai" : "faux");
    printf("%d est strictement supérieur à %d : %s\n", b, a,
           greaterThan(b, a) ? "vrai" : "faux");
    printf("%d est égal à %d : %s\n", a, b, equalTo(a, b) ? "vrai" : "faux");
    printf("%d est multiple de %d : %s\n", a, b,
           isMultiple(a, b) ? "vrai" : "faux");
    printf("%d est multiple de %d : %s\n", b, a,
           isMultiple(b, a) ? "vrai" : "faux");
    printf("La valeur absolue de %d est %d\n", a, absValue(a));
    printf("La valeur absolue de %d est %d\n", b, absValue(b));
    printf("%d + 1 = %d\n", a, increase(a));
    printf("%d - 1 = %d\n\n", b, decrease(b));
  }
}