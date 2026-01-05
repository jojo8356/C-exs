#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_GRILLE 81

/**
 * @brief Vérifie si une grille de sudoku est valide (format)
 *
 * @param grille la chaîne représentant la grille
 * @return int 1 si valide, 0 sinon
 */
int estGrilleValide(const char* grille) {
  // Vérifier la longueur
  if (strlen(grille) != TAILLE_GRILLE) {
    return 0;
  }

  // Vérifier que tous les caractères sont des chiffres (0-9)
  for (int i = 0; i < TAILLE_GRILLE; i++) {
    if (grille[i] < '0' || grille[i] > '9') {
      return 0;
    }
  }

  return 1;
}

/**
 * @brief Vérifie si une grille existe déjà dans le fichier
 *
 * @param grille la grille à vérifier
 * @param nomFichier le nom du fichier
 * @return int 1 si existe, 0 sinon
 */
int grilleExiste(const char* grille, const char* nomFichier) {
  FILE* fichier = fopen(nomFichier, "r");
  if (fichier == NULL) {
    // Le fichier n'existe pas encore, donc la grille n'existe pas
    return 0;
  }

  char buffer[TAILLE_GRILLE + 2];  // +2 pour \n et \0

  while (fgets(buffer, sizeof(buffer), fichier) != NULL) {
    // Supprimer le retour à la ligne
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strcmp(buffer, grille) == 0) {
      fclose(fichier);
      return 1;
    }
  }

  fclose(fichier);
  return 0;
}

/**
 * @brief Ajoute une grille au fichier
 *
 * @param grille la grille à ajouter
 * @param nomFichier le nom du fichier
 * @return int 1 si succès, 0 sinon
 */
int ajouteGrille(const char* grille, const char* nomFichier) {
  FILE* fichier = fopen(nomFichier, "a");
  if (fichier == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 0;
  }

  fprintf(fichier, "%s\n", grille);
  fclose(fichier);
  return 1;
}

int main() {
  char grille[256];
  const char* nomFichier = "sudokus.txt";

  while (1) {
    printf("Entrez une grille de sudoku (ou STOP pour arrêter) : ");

    if (fgets(grille, sizeof(grille), stdin) == NULL) {
      break;
    }

    grille[strcspn(grille, "\n")] = '\0';

    if (strcmp(grille, "STOP") == 0) {
      break;
    }

    if (!estGrilleValide(grille)) {
      printf("La grille est invalide\n");
      continue;
    }

    if (grilleExiste(grille, nomFichier)) {
      printf("Cette grille a déjà été publiée\n");
      continue;
    }

    if (ajouteGrille(grille, nomFichier)) {
      printf("Grille ajoutée avec succès\n");
    } else {
      printf("Erreur lors de l'ajout de la grille\n");
    }
  }

  return 0;
}
