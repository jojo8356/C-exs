#include <stdbool.h>
#include <stdio.h>

#define MAX 1000

int saisie() {
  int n;
  printf("Donner la valeur de n (<= %d, 0 pour quitter) : ", MAX);
  scanf("%d", &n);
  return n;
}

bool estDivisible(int nb, int div) { return nb % div == 0; }

bool estPremier(int nb) {
  if (nb < 2) return 0;
  for (int i = 2; i * i <= nb; i++)
    if (estDivisible(nb, i)) return 0;
  return 1;
}

void cribleEratosthene(int n, bool tableau[]) {
  for (int i = 0; i <= n; i++) {
    tableau[i] = estPremier(i);
  }
}

void affichePremiers(int n, bool tableau[]) {
  printf("Nombres premiers <= %d :\n", n);
  for (int i = 2; i <= n; i++) {
    if (tableau[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main() {
  int n;
  bool tableau[MAX + 1];

  while (1) {
    n = saisie();
    if (n == 0) {
      printf("Fin du programme.\n");
      break;
    }
    if (n > MAX) {
      printf("Erreur : n trop grand (max = %d).\n", MAX);
      continue;
    }

    cribleEratosthene(n, tableau);
    affichePremiers(n, tableau);
  }

  return 0;
}
