#pragma once

typedef struct NoeudGen {
  void* valeur;
  struct NoeudGen* suivant;
} NoeudGen;

typedef struct PileGen {
  NoeudGen* sommet;
} PileGen;

PileGen* creerPileGen(void);
void empilerGen(PileGen* p, void* val);
void* depilerGen(PileGen* p);
int estVidePileGen(PileGen* p);
void* sommetPileGen(PileGen* p);
void detruirePileGen(PileGen* p);
