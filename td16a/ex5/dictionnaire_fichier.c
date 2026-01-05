#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Définir la taille maximale du dico
#define LENGTHDICO 20

// Définir la taille maximale d'un mot
#define MAX_MOT 100

typedef struct {
  char* mot;
  int longueur;
} sMot;

/**
 * @brief parcourt le tableau et libère la mémoire de chaque structure mot
 * rencontrée.
 * @param dictionnaire le dictionnaire
 * @return void
 */
void effaceMots(sMot* dictionnaire[LENGTHDICO]) {
  for (int i = 0; i < LENGTHDICO; i++) {
    if (dictionnaire[i] != NULL) {
      free(dictionnaire[i]->mot);
      free(dictionnaire[i]);
      dictionnaire[i] = NULL;
    }
  }
}

/**
 * @brief Renvoie le nombre de mots dans le dictionnaire
 * @param dictionnaire le dictionnaire
 * @return le nombre de mots dans le dictionnaire
 */
int longueurDico(sMot* dictionnaire[LENGTHDICO]) {
  int count = 0;
  for (int i = 0; i < LENGTHDICO; i++) {
    if (dictionnaire[i] != NULL) {
      count++;
    }
  }
  return count;
}

/**
 * @brief Ajoute un mot au dictionnaire depuis une chaîne
 *
 * @param dictionnaire le dictionnaire
 * @param mot le mot à ajouter
 * @return void
 */
void ajouteMotDepuisChaine(sMot* dictionnaire[LENGTHDICO], const char* mot) {
  int index = -1;
  for (int i = 0; i < LENGTHDICO; i++) {
    if (dictionnaire[i] == NULL) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    fprintf(stderr, "Erreur: le dictionnaire est plein!\n");
    exit(1);
  }

  dictionnaire[index] = malloc(sizeof(sMot));
  if (dictionnaire[index] == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire!\n");
    exit(1);
  }

  dictionnaire[index]->mot = malloc(strlen(mot) + 1);
  if (dictionnaire[index]->mot == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire!\n");
    exit(1);
  }
  strcpy(dictionnaire[index]->mot, mot);
  dictionnaire[index]->longueur = strlen(mot);
}

/**
 * @brief Charge les mots depuis un fichier
 *
 * @param dictionnaire le dictionnaire
 * @param nomFichier le nom du fichier
 * @return int le nombre de mots chargés
 */
int chargeDico(sMot* dictionnaire[LENGTHDICO], const char* nomFichier) {
  FILE* fichier = fopen(nomFichier, "r");
  if (fichier == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 0;
  }

  char buffer[MAX_MOT];
  int count = 0;

  while (fgets(buffer, sizeof(buffer), fichier) != NULL && count < LENGTHDICO) {
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) > 0) {
      ajouteMotDepuisChaine(dictionnaire, buffer);
      count++;
    }
  }

  fclose(fichier);
  return count;
}

/**
 * @brief Affiche les mots du dictionnaire
 *
 * @param dictionnaire le dictionnaire
 * @return void
 */
void afficheDict(sMot* dictionnaire[LENGTHDICO]) {
  for (int i = 0; i < LENGTHDICO; i++) {
    if (dictionnaire[i] != NULL) {
      printf("Mot %d: %s\n", i, dictionnaire[i]->mot);
    }
  }
}

int main() {
  srand(time(NULL));

  // Initialiser le dictionnaire à NULL
  sMot* dictionnaire[LENGTHDICO] = {NULL};

  printf("Remplissage du dictionnaire à partir de dico.txt\n");
  int nbCharges = chargeDico(dictionnaire, "dico.txt");

  if (nbCharges == 0) {
    printf("Aucun mot chargé.\n");
    return 1;
  }

  printf("\nAffichage du dictionnaire\n");
  afficheDict(dictionnaire);

  int nbMotsDico = longueurDico(dictionnaire);
  if (nbMotsDico > 0) {
    int aleatoire = rand() % nbMotsDico;
    printf("Choix au hasard d'un element: \n");
    printf("Mot %d de longeur %d: %s\n", aleatoire,
           dictionnaire[aleatoire]->longueur, dictionnaire[aleatoire]->mot);
  }

  printf("Effacement du dictionnaire \n");
  effaceMots(dictionnaire);

  return 0;
}
