#pragma once

typedef struct NoeudFileGen {
  void* valeur;
  struct NoeudFileGen* suivant;
} NoeudFileGen;

typedef struct FileGen {
  NoeudFileGen* tete;
  NoeudFileGen* queue;
} FileGen;

FileGen* creerFileGen(void);
void enfilerGen(FileGen* f, void* val);
void* defilerGen(FileGen* f);
int estVideFileGen(FileGen* f);
void* teteFileGen(FileGen* f);
void detruireFileGen(FileGen* f);
