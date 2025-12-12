#include <stdio.h>

int main() {
  int a;
  printf("Entrez un entier : ");
  scanf("%d", &a);
  printf("%d est ", a);

  if (a % 2 == 0)
    printf("pair");
  else
    printf("impair");

  printf(".\n");
  return 0;
}