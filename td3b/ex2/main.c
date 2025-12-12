#include <stdio.h>

int main() {
  int a = 10;
  int *ptrA = &a;
  printf("Valeur pointée par ptrA: %d\n", *ptrA);
  float b = 3.14;
  float *ptrB = &b;
  printf("Adresse de b: %p\n", (void *)ptrB);
  printf("Valeur pointée par ptrB: %.2f\n", *ptrB);
  *ptrA = 20;
  printf("Nouvelle valeur de a: %d\n", a);
  *ptrB = 2.71;
  printf("Nouvelle valeur de b: %.2f\n", b);
  int *ptrC = NULL;
  printf("Valeur de ptrC: %p\n", (void *)ptrC);
  ptrC = ptrA;
  printf("Valeur de ptrC: %d\n", *ptrC);

  return 0;
}
