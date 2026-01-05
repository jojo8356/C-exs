#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* source = fopen("Euclide_algorithme.svg", "r");
  if (source == NULL) {
    perror("Erreur lors de l'ouverture du fichier source");
    return 1;
  }

  FILE* destination = fopen("Euclide_algorithme_copy.svg", "w");
  if (destination == NULL) {
    perror("Erreur lors de l'ouverture du fichier destination");
    fclose(source);
    return 1;
  }

  // Lecture caractère par caractère
  // EOF : End Of File
  int c;
  while ((c = fgetc(source)) != EOF) {
    fputc(c, destination);
  }

  fclose(source);
  fclose(destination);

  printf("Copie textuelle terminée avec succès.\n");

  return 0;
}
