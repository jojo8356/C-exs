#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTHDICO 20
#define MAX_MOT 100

// Structure pour un mot
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
 * @brief Ajoute un mot au dictionnaire
 *
 * Demande à l'utilisateur de saisir un mot, puis crée une structure sMot
 * dynamiquement et l'ajoute au dictionnaire au premier emplacement vide.
 *
 * Si le dictionnaire est plein, affiche un message
 * d'erreur et quitte le programme.
 *
 * @param dictionnaire le dictionnaire
 * @return void
 */
void ajouteMot(sMot* dictionnaire[LENGTHDICO]) {
  // Trouver le premier emplacement vide
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

  // Lire le mot
  char buffer[MAX_MOT];
  printf("Entrez un mot: ");
  scanf("%s", buffer);

  // Créer la structure dynamiquement
  dictionnaire[index] = malloc(sizeof(sMot));
  if (dictionnaire[index] == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire!\n");
    exit(1);
  }

  // Allouer et copier le mot
  dictionnaire[index]->mot = malloc(strlen(buffer) + 1);
  if (dictionnaire[index]->mot == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire!\n");
    exit(1);
  }
  strcpy(dictionnaire[index]->mot, buffer);
  dictionnaire[index]->longueur = strlen(buffer);
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
  // Initialiser le générateur de nombres aléatoires
  srand(time(NULL));

  // Initialiser le dictionnaire à NULL
  sMot* dictionnaire[LENGTHDICO] = {NULL};

  // Demander le nombre de mots
  int nbMots;
  printf("Combien de mots souhaitez-vous stocker?\n");
  scanf("%d", &nbMots);

  if (nbMots > LENGTHDICO) {
    printf("Nombre de mots limité à %d\n", LENGTHDICO);
    nbMots = LENGTHDICO;
  }

  // Remplissage du dictionnaire
  printf("Remplissage du dictionnaire\n");
  for (int i = 0; i < nbMots; i++) {
    ajouteMot(dictionnaire);
  }

  // Affichage du dictionnaire
  printf("\nAffichage du dictionnaire\n");
  afficheDict(dictionnaire);

  // Tirage aléatoire
  int nbMotsDico = longueurDico(dictionnaire);
  if (nbMotsDico > 0) {
    int aleatoire = rand() % nbMotsDico;
    printf("Choix au hasard d'un element: \n");
    printf("Mot %d de longueur %d: %s\n", aleatoire,
           dictionnaire[aleatoire]->longueur, dictionnaire[aleatoire]->mot);
  }

  // Libération de la mémoire
  printf("Effacement du dictionnaire \n");
  effaceMots(dictionnaire);

  return 0;
}
