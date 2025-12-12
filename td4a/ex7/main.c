#include <stdio.h>

/*
int count0(int *tab, int len) {
  int c = 0;
  for (int i = 0; i < len; i++)
    if (tab[i] == 0) c++;
  return c;
}

int main() {
  int tab[] = {0, 0, 1, 2, 0, 2, 3, 0, 3, 3};
  int len = sizeof(tab) / sizeof(tab[0]);
  for (int i = 0; i < len; i++) printf("%d ", tab[i]);
  printf("\n\n");
  printf("Nb = %d", count0(tab, len));
  printf("\n");
}
*/

/*
double max(double *tab, int len) {
  double max = tab[0];
  for (int i = 0; i < len; i++)
    if (tab[i] > max) max = tab[i];
  return max;
}

int main() {
  double tab[] = {2.70, 3.20, 0.90, 4.80};
  int len = sizeof(tab) / sizeof(tab[0]);
  for (int i = 0; i < len; i++) printf("%.2lf ", tab[i]);
  printf("\n\n");
  printf("Le maximum est: %.2lf", max(tab, len));
}
*/

/*
int main() {
  int numbers[] = {1, 2, 3, 4, 5};
  int sum = 0;
  int length = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = 0; i < length; i++) {
    printf("%d ", numbers[i]);
    sum += numbers[i];
  }

  printf("\n\nLa somme des éléments est: %d\n", sum);
}
*/

int search(char a, char *str) {
  int find = 0;
  int i = 0;
  while (str[i] != a && str[i]) i++;
  if (str[i] == a) find = 1;
  return find;
}

int main() {
  char *str = "B o n j o u r : )";
  char c = 'b';
  printf("Le caractère %c", c);
  if (search(c, str))
    printf(" a été trouvé");
  else
    printf(" n'est pas présent");
  printf(" dans le tableau\n");
}