#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool estDivisible(int nb, int div) { return nb % div == 0; }

/*
bool estPremier(int nb) {
  for (int i = 2; i <= sqrt(nb); i++)
    if (estDivisible(nb, i)) return 0;
  return 1;
}

int main() {
  printf("Liste des nombres premiers\n");
  for (int i = 2; i <= 1000; i++)
    if (estPremier(i)) printf("%d ", i);
  printf("\n");
  return 0;
}
*/

#include <stdio.h>

void Crible_Ératosthène(int M) {
  int compteDiviseurs[M + 1];

  for (int i = 1; i <= M; i++) {
    compteDiviseurs[i] = 1;
  }

  for (int i = 2; i <= M; i++) {
    for (int j = 2; j <= i; j++) {
      if (i % j == 0) {
        compteDiviseurs[i]++;
      }
    }
  }

  printf("Nombres premiers dans l'intervalle [1, %d]:\n", M);
  for (int i = 2; i <= M; i++) {
    if (compteDiviseurs[i] == 2) {
      printf("%d\n", i);
    }
  }
}

int main() {
  int M;
  printf("Entrez la valeur de M : ");
  scanf("%d", &M);

  if (M < 2) {
    printf("Veuillez entrer une valeur de M supérieure ou égale à 2.\n");
    return 1;
  }

  Crible_Ératosthène(M);

  return 0;
}