#include <stdio.h>

int longueur(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

int compare(char *str1, char *str2) {
  int i = 0;

  while (str1[i] && str2[i]) {
    if (str1[i] != str2[i]) return str1[i] - str2[i];
    i++;
  }
  return str1[i] - str2[i];
}

int main() {
  char str1[32];
  char str2[32];
  for (int i = 0; i < 3; i++) {
    printf("Tour %d/3\n--------\nEntrez le 1er mot:\n", i + 1);
    scanf("%s", str1);
    printf("Entrez le 2e mot:\n");
    scanf("%s", str2);
    if (compare(str1, str2) < 0)
      printf("%s <= %s", str1, str2);
    else
      printf("%s <= %s", str2, str1);
    printf("\n\n");
  }
}