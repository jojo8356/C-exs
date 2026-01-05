#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* source = fopen("Euclide_algorithme.png", "rb");
  if (source == NULL) {
    perror("Erreur lors de l'ouverture du fichier source");
    return 1;
  }

  FILE* destination = fopen("Euclide_algorithme_copy.png", "wb");
  if (destination == NULL) {
    perror("Erreur lors de l'ouverture du fichier destination");
    fclose(source);
    return 1;
  }

  // Buffer de 4 Ko
  char buffer[4096];
  size_t nbLu;

  // Lecture par blocs
  while ((nbLu = fread(buffer, sizeof(char), sizeof(buffer), source)) > 0) {
    fwrite(buffer, sizeof(char), nbLu, destination);
  }

  fclose(source);
  fclose(destination);

  printf("Copie binaire terminée avec succès.\n");

  return 0;
}
