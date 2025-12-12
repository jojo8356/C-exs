#include <stdio.h>

int main() {
  char initiale;
  int age;
  double taille;

  puts("Quel est votre initiale ?");
  scanf("%s", &initiale);

  puts("Quel est votre âge ?");
  scanf("%d", &age);

  puts("Quel est votre taille (en mètres) ?");
  scanf("%lf", &taille);

  printf("Bonjour %c, vous avez %d ans et mesurez %lf mètres.\n", initiale, age,
         taille);

  return 0;
}