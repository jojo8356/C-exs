#pragma once

typedef struct NoeudAB {
  int valeur;
  struct NoeudAB* gauche;
  struct NoeudAB* droit;
} NoeudAB;

typedef enum { PRE, IN, POST } DFSOrdre;

int getDeep(NoeudAB* racine);
int lenNodes(NoeudAB* racine);
int* BFS(NoeudAB* racine, int level, int tab[], int index);
void libererAB(NoeudAB** racine);
NoeudAB* creerExempleAB();
void afficherAB(NoeudAB* racine);
void parcourirProfondeurAB(NoeudAB* racine, DFSOrdre ordre, bool inverse);
void parcoursPrefixe(NoeudAB* racine);
void parcoursInfixe(NoeudAB* racine);
void parcoursSuffixe(NoeudAB* racine);
int calculerHauteurAB(NoeudAB* racine);
int calculerTailleAB(NoeudAB* racine);
int compterFeuillesAB(NoeudAB* racine);
bool estParfaitAB(NoeudAB* racine);
int calculerTailleTabAB(int* tab, int taille);
int calculerHauteurTabAB(int* tab, int taille);
bool estParfaitTabAB(int* tab, int taille);
bool verifierTabAB(int* tab, int taille);
int compterFeuillesTabAB(int* tab, int taille);
void parcoursLargeurTabAB(int* tab, int taille);