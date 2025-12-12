/**
 * Démonstration de l'utilisation des modules lib
 */
#include <stdio.h>

#include "../lib/affichage.h"

int main() {
  // afficheSep est défini dans lib
  afficheSep();

  printf("Hello world with separators!\n");

  afficheSep();

  return 0;
}