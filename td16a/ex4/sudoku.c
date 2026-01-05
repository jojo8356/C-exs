

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 81  // 9x9 = 81 caractères

/**
 *  @brief Vérifie qu'une grille est valide
 *
 * Deux critères simples sont utilisés:
 *  - La grille doit contenir exactement 81 caractères
 *  - Chaque caractère doit être un chiffre entre 0 et 9
 *
 * @note La faisabilité et l'unicité de la solution n'est pas vérifiée
 *
 * @param grid La grille à vérifier
 * @return true si la grille est valide, false sinon
 *
 *  */
bool estValide(const char* grid) {
  if (strlen(grid) != GRID_SIZE) return false;
  for (int i = 0; i < GRID_SIZE; i++) {
    if (grid[i] < '0' || grid[i] > '9') {
      return false;
    }
  }
  return true;
}

/**
 * @brief Vérifie si une grille est déjà présente dans le fichier sudokus.txt
 *
 * @param grille La grille à vérifier
 * @return true si la grille est déjà présente, false sinon
 *
 */
bool estDejaFaite(const char* grille) {
  FILE* file = fopen("sudokus.txt", "r");
  if (file == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    exit(1);
  };

  // parcours du fichier pour vérifier que la grille n'est pas déjà présente
  char buffer[GRID_SIZE + 1];
  while (fgets(buffer, GRID_SIZE + 1, file) != NULL) {
    if (strcmp(buffer, grille) == 0) {
      // la grille est déjà présente
      return true;
    }
  }
  // aucune grille identique a été trouvée
  return false;
}

/** @brief Ajoute une grille au fichier sudokus.txt
 *
 * @param grille La grille à ajouter
 * @return true si la grille a été ajoutée, false sinon
 *
 * La procédure vérifie que la grille n'est pas déjà présente avant de l'ajouter
 * à la fin du fichier sudokus.txt. Un message est affiché pour indiquer si
 * l'ajout a été effectué ou non.
 *
 * @note Le fichier sudokus.txt doit exister et être accessible en écriture
 */
void ajouterSudoku(char* grille) {
  // vérification de la validité de la grille
  bool estInvalide = !estValide(grille);
  bool estFaite = estDejaFaite(grille);
  if (estInvalide || estFaite) {
    fprintf(stderr, "\t:( La grille %s\n",
            estInvalide ? "est invalide" : "est déjà faite");
    return;
  }

  // Ouvre en mode ajout pour les ajouter à la fin
  FILE* file = fopen("sudokus.txt", "a");
  if (file == NULL) {
    perror("\t:( Erreur lors de l'ouverture du fichier");
    return;
  };

  // On ajoute à la fin grâce au mode append!
  fprintf(file, "%s\n", grille);
  fclose(file);

  puts("\t:) Grille ajoutée avec succès");
}

int main() {
  char grille[GRID_SIZE] = "";
  while (true) {
    printf("\nEntrez une grille de sudoku (ou STOP pour arrêter): ");
    scanf("%s", grille);
    if (strcmp(grille, "STOP") == 0) break;
    ajouterSudoku(grille);
  }
  return 0;
}