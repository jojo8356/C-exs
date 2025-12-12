#include <stdio.h>
#include <stdlib.h>

int* tableauScanfTaille(int len) {
  while (len <= 0) {
    printf("Entrez la taille du tableau : ");
    scanf("%d", &len);
    printf("\nla taille doit être un entier positif.\n");
  }
  printf("Entrez les éléments:\n");
  int* tab = (int*)malloc(len * sizeof(int));

  if (tab == NULL) {
    fprintf(stderr, "L'allocation mémoire n'a pas réussi\n");
    exit(1);
  }

  // get tab values
  for (int i = 0; i < len; i++) {
    printf("Entrez la valeur pour l'élément %d: ", i);
    scanf("%d", &tab[i]);
  }

  return tab;
}

void print_tab(int* tab, int len) {
  printf("{");
  for (int i = 0; i < len; i++) {
    printf("%d", tab[i]);
    if (i < len - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

void afficherTab(int* tab, int len) {
  printf("{");
  for (int i = 0; i < len; i++) {
    printf("%d", tab[i]);
    if (i < len - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

void triTab(int tab[], int n) {
  for (int i = 1; i < n; i++) {
    int key = tab[i];
    int j = i - 1;
    while (j >= 0 && tab[j] > key) {
      tab[j + 1] = tab[j];
      j--;
    }
    tab[j + 1] = key;
  }
}

int estTrieeTab(int tab[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (tab[i] > tab[i + 1]) return 0;
  }
  return 1;
}