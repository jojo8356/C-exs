#include <stdio.h>

void afficherTableau(int leny, int lenx, int tab[leny][lenx]) {
  for (int i = 0; i < leny; i++) {
    for (int j = 0; j < lenx; j++) printf("%d ", tab[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int tab[2][3] = {{1, 2, 3}, {4, 5, 6}};
  afficherTableau(2, 3, tab);
}