#include <stdio.h>
#include <string.h>

/*
void inverseChaine(char chaine[]) {
  int taille = strlen(chaine);
  for (int i = 0; i < taille / 2; i++) {
    char tmp = chaine[i];
    chaine[i] = chaine[taille - i - 1];
    chaine[taille - i - 1] = tmp;
  }
}

bool estPalindrome(char chaine[]) {
  int longueur = strlen(chaine);
  for (int i = 0; i < longueur / 2; i++) {
    if (chaine[i] != chaine[longueur - i - 1]) {
      return false;
    }
  }
  return true;
}
*/

int remplace(char *chaine, char caractere);

int main() {
  char chaine[200];
  char caractere;

  printf("Entrez une chaîne de caractères : ");
  fgets(chaine, sizeof(chaine), stdin);
  chaine[strcspn(chaine, "\n")] = '\0';
  printf("Entrez le caractère à remplacer : ");
  scanf(" %c", &caractere);
  int nb = remplace(chaine, caractere);
  printf("\nChaîne après remplacement : %s\n", chaine);
  printf("Nombre de remplacements effectués : %d\n", nb);
  return 0;
}

int remplace(char *chaine, char caractere) {
  int nb = 0;
  for (int i = 0; chaine[i]; i++) {
    if (chaine[i] == caractere) {
      chaine[i] = '_';
      nb++;
    }
  }
  return nb;
}