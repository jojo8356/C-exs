#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoeudStr {
  char* url;
  struct NoeudStr* suivant;
} NoeudStr;

typedef struct {
  NoeudStr* sommet;
} Historique;

typedef struct {
  NoeudStr* sommet;
} Redo;

void initPileStr(Historique* h) { h->sommet = NULL; }

void initRedo(Redo* r) { r->sommet = NULL; }

void push(NoeudStr** head, const char* url) {
  NoeudStr* nouveau = malloc(sizeof(NoeudStr));
  if (!nouveau) {
    fprintf(stderr, "Erreur alloc mem\n");
    exit(1);
  }
  nouveau->url = strdup(url);
  nouveau->suivant = *head;
  *head = nouveau;
}

char* pop(NoeudStr** head) {
  if (*head == NULL) return NULL;

  NoeudStr* temp = *head;
  char* url = strdup(temp->url);

  *head = temp->suivant;
  free(temp->url);
  free(temp);

  return url;
}

/* ---- API Navigateur ---- */

void aller(Historique* h, Redo* r, const char* url) {
  while (r->sommet != NULL) {
    char* tmp = pop(&r->sommet);
    free(tmp);
  }

  push(&h->sommet, url);
}

void revenir(Historique* h, Redo* r) {
  if (h->sommet == NULL || h->sommet->suivant == NULL) {
    printf("Impossible de revenir.\n");
    return;
  }

  char* courante = pop(&h->sommet);
  push(&r->sommet, courante);
  free(courante);
}

void avancer(Historique* h, Redo* r) {
  if (r->sommet == NULL) {
    printf("Impossible d'avancer.\n");
    return;
  }

  char* url = pop(&r->sommet);
  push(&h->sommet, url);
  free(url);
}

const char* getPageCourante(Historique* h) {
  if (h->sommet == NULL) return "Aucune page";
  return h->sommet->url;
}

int main() {
  Historique h;
  Redo r;

  initPileStr(&h);
  initRedo(&r);

  aller(&h, &r, "google.com");
  aller(&h, &r, "youtube.com");
  aller(&h, &r, "github.com");

  printf("Page actuelle : %s\n", getPageCourante(&h));

  revenir(&h, &r);
  printf("Après revenir : %s\n", getPageCourante(&h));

  revenir(&h, &r);
  printf("Après revenir encore : %s\n", getPageCourante(&h));

  avancer(&h, &r);
  printf("Après avancer : %s\n", getPageCourante(&h));

  return 0;
}
