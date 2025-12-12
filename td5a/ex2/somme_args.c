#include <stdio.h>
#include <stdlib.h>

/*
int main(int argc, char *argv[]) {
  int somme = 0;
  for (int i = 0; i < argc; i++) {
    somme += atoi(argv[i]);
  }
  printf("La somme des entiers passés en ligne de commande est: %d\n", somme);
  return 0;
}
*/

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Erreur: Aucun argument passé.\n");
    exit(1);
  }
  int somme = 0;
  for (int i = 0; i < argc; i++) {
    somme += atoi(argv[i]);
  }
  printf("La somme des entiers passés en ligne de commande est: %d\n", somme);
  return 0;
}