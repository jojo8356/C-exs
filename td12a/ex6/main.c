#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int capacity, size, front;
  int* data;
} RingBuffer;

bool estVideRB(RingBuffer* rb) {
  return rb->size == 0;
}

bool estPleineRB(RingBuffer* rb) {
  return rb->size == rb->capacity;
}

RingBuffer* initRB(int capacity) {
  RingBuffer* rb = (RingBuffer*)malloc(sizeof(RingBuffer));
  rb->capacity = capacity;
  rb->size = 0;
  rb->front = 0;
  rb->data = (int*)malloc(capacity * sizeof(int));
  return rb;
}

void enfilerRB(RingBuffer* rb, int valeur) {
  if (estPleineRB(rb)) {
    printf("Erreur: la file est pleine\n");
    return;
  }
  int index = (rb->front + rb->size) % rb->capacity;
  rb->data[index] = valeur;
  rb->size++;
}

int defilerRB(RingBuffer* rb) {
  if (estVideRB(rb)) {
    printf("Erreur: la file est vide\n");
    return -1;
  }
  int valeur = rb->data[rb->front];
  rb->front = (rb->front + 1) % rb->capacity;
  rb->size--;
  return valeur;
}

void libererRB(RingBuffer* rb) {
  free(rb->data);
  free(rb);
}

int main() {
  // Initialisation
  int taille = 5;
  printf("Initialisation d'une file circulaire vide de taille %d\n", taille);
  RingBuffer* q = initRB(taille);
  printf("File vide? -> %d\n", estVideRB(q));
  printf("File pleine? -> %d\n", estPleineRB(q));
  afficherRB(q);

  puts("\nRempli la file");
  for (int i = 1; i <= taille; i++) {
    printf("Enfile %d -> ", i);
    enfilerRB(q, i);
    afficherRB(q);
  }

  printf("File vide? -> %d\n", estVideRB(q));
  printf("File pleine? -> %d\n", estPleineRB(q));
  // Affiche et défile les éléments
  puts("\nDéfile la motié de la file");

  for (int i = 0; i < taille / 2; i++) {
    printf("%d  <- ", defilerRB(q));
    afficherRB(q);
  }

  puts("Enfile à nouveau");
  for (int i = taille; i < 3 * taille / 2; i++) {
    printf("Enfile %d -> ", i);
    enfilerRB(q, i);
    afficherRB(q);
  }
  puts("Vide la file");
  while (!estVideRB(q)) {
    printf("%d  <- ", defilerRB(q));
    afficherRB(q);
  }

  // Libère la mémoire
  libererRB(q);

  return 0;
}
