#include <stdio.h>

/*
int main() {
  double nb;
  printf("Entrer un nombre décimal:\n");
  scanf("%lf", &nb);
  printf("La partie fractionnaire de %lf est %lf\n", nb, (nb - (int)nb));
}
*/

double decimale(double nb) { return nb - (int)nb; }

int main() {
  double nb = 1;
  while ((int)nb != 0) {
    printf("Entrer un nombre décimal (0 pour arrêter) : ");
    scanf("%lf", &nb);
    if (nb != 0)
      printf("La partie fractionnaire de %lf est %lf\n", nb, decimale(nb));
  }
}
