#include <stdio.h>

bool isPrimaryNumber(int valeur) {
  int i;
  if (valeur == 0 || valeur == 1)
    return false;
  for (i = 2; i < valeur; i++) // parcours des nombres précédents
    if (valeur % i == 0) // si le nombre est divisible à un des nombres précédents à celui-ci
      return false; // si le nombre est divisible à un des nombres précédents à celui-ci alors c'est faux
  return true; // si le nombre n'est pas divisible par tous les nombres précédents à celui-ci alors c'est vrai
}

int isPair(int valeur){
  return valeur % 2 == 0; // si le reste de la division de la valeur par 2 est 0 alors cela retourne 1 sinon 0
}


int main() {
  
  printf("Tableaux des nombres premiers\n\n");
  for (int i = 1; i <= 100; i++) {
    if (isPrimaryNumber(i))
      printf("|%3d ", i);
    else
      printf("|%4s", "");
    if (i % 10 == 0)
      printf("\n");
  }

  return 0;
}