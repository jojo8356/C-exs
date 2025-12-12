#include <stdio.h>

#include "../lib/tableaux.h"

int main() {
  int tab0[] = {};
  afficherTab(tab0, 0);

  int tab1[] = {1, 2, 3, 4, 5};
  afficherTab(tab1, 5);

  return 0;
}