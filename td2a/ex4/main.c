#include <stdio.h>

/*
int main(void) {
  int n, som = 0;

  for (int i = 0; i <= 3; i++){
    printf("donnez un entier \n");
    scanf("%d", &n);
    som += n;
  }
  printf("Somme: %d\n", som);
  return 0;
}
*/

int main(void) {
  int n, som = 0;
  do {
    printf("donnez un entier \n");
    scanf("%d", &n);
    som += n;
  } while (n != 0);
  printf("Somme: %d\n", som);
  return 0;
}