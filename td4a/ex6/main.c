#include <stdio.h>
#include <stdlib.h>

int main() {
  int len;
  int tmp;
  printf("Combien d'éléments? ");
  scanf("%d", &len);
  printf("\n");
  int *tab = malloc(len * sizeof(int));
  if (tab == NULL) return 1;
  for (int i = 0; i < len; i++) {
    printf("Entrer tab[%d]: ", i);
    scanf("%d", &tmp);
    tab[i] = tmp;
  }
  printf("\n");
  for (int i = 0; i < len; i++) printf("%d ", tab[i]);
  printf("\n");
  return 0;
}