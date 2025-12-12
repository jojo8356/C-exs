#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned fibRec(unsigned n){
    if(n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

unsigned _fibRecMemo(unsigned n, unsigned memo[]){
    if(memo[n] != 0) return memo[n]; // trouver valeur existante
    if(n <= 1) return n; // cas de base
    memo[n] = _fibRecMemo(n-1, memo) + _fibRecMemo(n-2, memo); // calculer et stocker
    return memo[n];
}

unsigned fibRecMemo(unsigned n){
    unsigned* memo = calloc(n + 1, sizeof(unsigned));
    unsigned result = _fibRecMemo(n, memo);
    free(memo);
    return result;
}

int main() {
  unsigned n = 40;
  clock_t debut, fin;
  double duree;

  printf("Calcul de fibonacci(%d)\n", n);

  debut = clock();
  unsigned res = fibRec(n);
  fin = clock();
  duree = ((double)(fin - debut)) / CLOCKS_PER_SEC;
  printf("Version naïve: %u (temps: %f secondes)\n", res, duree);

  debut = clock();
  unsigned resMemo = fibRecMemo(n);
  fin = clock();
  duree = ((double)(fin - debut)) / CLOCKS_PER_SEC;
  printf("Version mémoïsation: %u (temps: %f secondes)\n", resMemo, duree);

  return 0;
}