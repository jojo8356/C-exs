#include <stdio.h>

#define NB_LIGNE 2
#define NB_COL 3

void afficheMatrice(int tab[NB_LIGNE][NB_COL]) {
  for (int i = 0; i < NB_LIGNE; i++) {
    for (int j = 0; j < NB_COL; j++) {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
}

void afficheLigneMatrice(int tab[NB_LIGNE][NB_COL], int nLigne) {
  if (nLigne >= 0 && nLigne < NB_LIGNE) {  // sécurité
    for (int j = 0; j < NB_COL; j++) {
      printf("%d ", tab[nLigne][j]);
    }
  }
}

void afficheColonneMatrice(int tab[NB_LIGNE][NB_COL], int nCol) {
  if (nCol >= 0 && nCol < NB_COL) {  // sécurité
    for (int i = 0; i < NB_LIGNE; i++) {
      printf("%d\n", tab[i][nCol]);
    }
  }
}

int main() {
  int tab[NB_LIGNE][NB_COL] = {{1, 2, 3}, {4, 5, 6}};

  puts("Affichage de la matrice :");
  afficheMatrice(tab);

  puts("\nAffichage de la ligne 1 :");
  afficheLigneMatrice(tab, 1);

  puts("\n\nAffichage de la colonne 2 :");
  afficheColonneMatrice(tab, 2);
}
