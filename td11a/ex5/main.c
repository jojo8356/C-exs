#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoeudStr {
  char* url;
  struct NoeudStr* suivant;
} NoeudStr;

void aller(NoeudStr** head, const char* url) {
  NoeudStr* nouveau = (NoeudStr*)malloc(sizeof(NoeudStr));
  if (nouveau == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    return;
  }
  nouveau->url = strdup(url);
  nouveau->suivant = *head;
  *head = nouveau;
}

char *revenir(NoeudStr** head) {
  if (*head == NULL) {
    fprintf(stderr, "Erreur : pile vide\n");
    return NULL;
  }
  NoeudStr* temp = *head;
  char* ret = temp->url;
  *head = (*head)->suivant;
  free(temp);
  return ret;
}

void afficheUrl(NoeudStr* head) {
  if (head == NULL) {
    printf("Aucune URL dans l'historique\n");
    return;
  }
  printf("URL actuelle : %s\n", head->url);
}

void nettoieHistorique(NoeudStr* pile) {
  while (pile != NULL) {
    NoeudStr* temp = pile;
    pile = pile->suivant;
    free(temp->url);
    free(temp);
  }
}

int main() {
  puts("Début de navigation");

  NoeudStr* navigateur = {NULL};
  afficheUrl(navigateur);

  puts("\nSimulation de navigation");
  char urls[][128] = {"https://www.qwant.com", "https://www.framasoft.org",
                      "https://www.stackoverflow.com"};
  for (int i = 0; i < 3; i++) {
    char* url = urls[i];
    printf("Navigation vers; %s\n", url);
    aller(&navigateur, url);
    afficheUrl(navigateur);
  }

  puts("\nRetour en arrière");
  printf("Dépile %s\n", revenir(&navigateur));
  afficheUrl(navigateur);

  puts("\nNaviguer vers une nouvelle page");
  aller(&navigateur, "https://www.wikipedia.org");
  afficheUrl(navigateur);  // Affiche wikipedia

  // Libération
  puts("\nNettoyage de la mémoire dynamique\n");
  nettoieHistorique(navigateur);
  return 0;
}