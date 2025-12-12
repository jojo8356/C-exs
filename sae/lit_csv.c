/**
 * @file lit_csv.c
 * @brief Programme pour lire et afficher des données au format CSV depuis
 * l'entrée standard.
 */

#include <stdio.h>

#include "lib/exemple.h"

/**
 * @brief Fonction principale du programme.
 *
 * Cette fonction lit un en-tête et des données au format CSV depuis l'entrée
 * standard, puis les affiche sous forme de tableau sur la sortie standard.
 *
 * @return int Retourne 0 en cas de succès.
 */
int main(int argc, char *argv[]) {
  char enTete[4][16];  // Tableau de 4 chaînes de caractères de 16 caractères
  char date[11];       // 10 caractères + le caractère final
  char prod[16];
  int qte;
  float pu;
  puts("LECTURE DES DONNÉES\n");

  int cpt = 0;
  // traitement de l'en-tête
  // Lecture de 4 chaines de 15 caractères séparées par des virgules
  scanf("%15[^,],%15[^,],%15[^,],%15[^\n]", enTete[0], enTete[1], enTete[2],
        enTete[3]);

  // Affichage de l'en-tête
  afficherLigneSeparation();
  printf("| %-10s | %-16s | %-5s | %-5s |\n", enTete[0], enTete[1], enTete[2],
         enTete[3]);
  afficherLigneSeparation();

  // Vider le buffer après la lecture de l'en-tête
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }

  //  On lit maintenant les valeurs du fichier csv
  // On attend 2 chaines de caractères, un entier et un nb flottant séparés par
  // des virgules
  while (scanf("%10[^,],%15[^,],%d,%f\n", date, prod, &qte, &pu) == 4) {
    // Affichage des données sous forme de tableau
    printf("| %10s | %16s | %5d | %5.2f |\n", date, prod, qte, pu);
    cpt++;
  }
  afficherLigneSeparation();

  puts("\nLECTURE TERMINÉE");
  printf("%d lignes lues avec succès\n", cpt);

  return 0;
}