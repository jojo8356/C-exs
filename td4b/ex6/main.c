#include <stdio.h>

int count0(int *tab, int len) {
  int c = 0;
  for (int i = 0; i < len; i++)
    if (tab[i] == 0) c++;
  return c;
}

int max(int *tab, int len) {
  int max = tab[0];
  for (int i = 0; i < len; i++)
    if (tab[i] > max) max = tab[i];
  return max;
}

double somme(double tab[], int len) {
  double s = 0;
  for (int i = 0; i < len; i++) s += tab[i];
  return s;
}

int recherche(char tab[], int taille, char c) {
  for (int i = 0; i < taille; i++)
    if (tab[i] == c) return 1;
  return 0;
}

void print_tab(int tab[], int len) {
  printf("{");
  for (int i = 0; i < len; i++) {
    printf("%d", tab[i]);
    if (i < len - 1) printf(", ");
  }
  printf("}");
}

int main() {
  int tabs[3][5] = {{0, 2, 0, 4, 5}, {0, 0, 0, 0, 0}, {1, 2, 3, 4, -5}};

  int len = sizeof(tabs[0]) / sizeof(tabs[0][0]);

  for (int i = 0; i < 3; i++) {
    print_tab(tabs[i], len);
    printf("\nIl y a %d éléments nuls dans ce tableau\n", count0(tabs[i], len));
  }

  int tab[] = {-12, -28, -34, -42, -1, -6, -12, -34};
  len = sizeof(tab) / sizeof(tab[0]);
  print_tab(tab, len);
  printf("\nMaximum: %d\n", max(tab, len));
}