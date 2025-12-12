#include <stdio.h>

int main() {
  int ch;
  while (ch != 3) {
    puts("Quelle opération voulez-vous effectuer?");
    puts(" 1. Somme");
    puts(" 2. Produit");
    puts(" 3. Quitter");
    scanf("%d", &ch);
    if (ch < 3) {
      int a;
      int b;
      printf("Entrez deux entiers : ");
      scanf("%d %d", &a, &b);
      if (ch == 1) printf("Somme: %d\n", a + b);
      if (ch == 2) printf("Produit: %d\n", a * b);
    }
  }
  return 0;
}