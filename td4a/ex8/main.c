#include <stdio.h>

/*
int main() {
  int tab[5] = {1, 2, 3, 4, 5};

  printf("Accès par indice\n");
  for (int i = 0; i < 5; i++) {
    printf("tab[%d] = %d, adresse -> %p\n", i, tab[i], (void *)&tab[i]);
  }

  printf("\nAccès par ptr\n");
  int *ptr = tab;
  for (int i = 0; i < 5; i++) {
    printf("*ptr = %d, ptr -> %p\n", *ptr, (void *)ptr);
    ptr++;
  }

  return 0;
}
*/

int main() {
  int tab[2][3] = {{1, 2, 3}, {4, 5, 6}};

  printf("Accès par indice\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("tab[%d][%d] = %d, adresse -> %p\n", i, j, tab[i][j],
             (void *)&tab[i][j]);
    }
  }

  printf("\nAccès par ptr (lineaire sur le tableau 2D)\n");
  int *ptrCol = &tab[0][0];
  for (int k = 0; k < 6; k++) {
    printf("*ptrCol = %d, ptrCol -> %p\n", *ptrCol, (void *)ptrCol);
    ptrCol++;
  }

  return 0;
}