#include <stdio.h>

void afficherTableau(int *tab, int len) {
  for (int i = 0; i < len; i++) printf("%d ", tab[i]);
  printf("\n");
}

int main() {
  int tab[] = {1, 2, 3, 4, 5};
  int len = sizeof(tab) / sizeof(tab[0]);
  afficherTableau(tab, len);
}