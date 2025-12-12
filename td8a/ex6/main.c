#include <stdio.h>
#include <time.h>

#include "../lib/tableaux.h"

int main() {
  // Teste pour 4 valeurs de n
  int N = 500000;

  for (int i = 1; i <= 4; i *= 2) {
    int n = i * N;
    printf("Test avec une tableau de %d valeurs\n", n);
    int tab[n];
    for (int j = 0; j < n; j++) tab[j] = j;

    // Mesure du temps d'exécution
    time_t debut = clock();

    // On se place dans le pire cas
    // On répète la recherche pour faire une moyenne
    for (int val = -1; val > -1000000; val--) rechercheDichoRec(tab, 0, n-1, val);

    // Fin du chronométrage
    clock_t fin = clock();
    double tempsExecution = 1000.0 * ((double)(fin - debut)) / CLOCKS_PER_SEC;
    ;

    printf("1000000 de recherches en %.3lf ms\n", tempsExecution);
  }
  return 0;
}