#pragma once

#include <stdbool.h>

typedef struct NoeudAB {
  int valeur;
  struct NoeudAB* gauche;
  struct NoeudAB* droit;
} NoeudAB;

typedef enum { PRE, IN, POST } DFSOrdre;

// Fonctions sur arbres chaînés
NoeudAB* creerExempleAB(void);
void libererAB(NoeudAB** racine);
void afficherAB(NoeudAB* racine);

// Parcours
void parcourirProfondeurAB(NoeudAB* racine, DFSOrdre ordre, bool inverse);
void parcoursPrefixe(NoeudAB* racine);
void parcoursInfixe(NoeudAB* racine);
void parcoursSuffixe(NoeudAB* racine);
void parcoursLargeur(NoeudAB* racine);
int* parcourirLargeurAB(NoeudAB* racine);

// Parcours itératifs
void iterativePreorder(NoeudAB* racine);
void iterativeInorder(NoeudAB* racine);
void iterativePostorder(NoeudAB* racine);

// Mesures
int calculerHauteurAB(NoeudAB* racine);
int calculerTailleAB(NoeudAB* racine);
int compterFeuillesAB(NoeudAB* racine);
bool estParfaitAB(NoeudAB* racine);

// Fonctions sur arbres en tableau
int calculerTailleTabAB(int* tab, int taille);
int calculerHauteurTabAB(int* tab, int taille);
int compterFeuillesTabAB(int* tab, int taille);
bool estParfaitTabAB(int* tab, int taille);
bool verifierTabAB(int* tab, int taille);
void printTree(NoeudAB* racine);
void parcourirPreItAB(NoeudAB* racine);
void parcourirInItAB(NoeudAB* racine);
void parcourirPostItAB(NoeudAB* racine);