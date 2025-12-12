#include <stdio.h>
#include <string.h>

#define TAILLE_STR 100

void swap_str(char *a, char *b) {
  char temp[TAILLE_STR];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

void triSelectionStr(char titres[][TAILLE_STR], int taille) {
  for (int i = 0; i < taille - 1; i++) {
    int min = i;
    
    // get min index
    for (int j = i + 1; j < taille; j++) {
      if (strcmp(titres[j], titres[min]) < 0) {
        min = j;
      }
    }

    if (min != i) {
      swap_str(titres[i], titres[min]);
    }
  }
}

int main() {
  // Déclaration directe de la playlist
  char playlist[][TAILLE_STR] = {
      "Bohemian Rhapsody",       "Imagine",
      "Hotel California",        "Stairway to Heaven",
      "Smells Like Teen Spirit", "Billie Jean",
      "Like a Rolling Stone",    "Hey Jude",
      "Sweet Child O' Mine",     "What a Wonderful World"};

  int nChanson = sizeof(playlist) / sizeof(playlist[0]);

  // Affichage avant tri
  printf("PLAYLIST AVANT TRI:\n");
  for (int i = 0; i < nChanson; i++) {
    printf("%s\n", playlist[i]);
  }

  // Tri des titres
  triSelectionStr(playlist, nChanson);

  // Affichage après tri
  printf("\nPLAYLIST APRÈS TRI:\n");
  for (int i = 0; i < nChanson; i++) {
    printf("%s\n", playlist[i]);
  }

  return 0;
}