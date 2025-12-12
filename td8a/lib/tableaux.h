#pragma once

#include <stdbool.h>

void afficherTab(int* tab, int taille);
int sommeTab(int tab[], int taille);
double moyenneTab(int tab[], int taille);
int maxTab(int tab[], int taille);
int minTab(int tab[], int taille);
int compterOccurrences(int tab[], int taille, int valeur);
void inverserTab(int tab[], int taille);
void copierTab(int source[], int dest[], int taille);
bool estCroissantTab(int tab[], int taille);
bool estDecroissant(int tab[], int taille);
void fusionnerTableaux(int tab1[], int taille1, int tab2[], int taille2,
                       int resultat[]);
void extraireSousTab(int source[], int debut, int fin, int dest[]);
void triABullesTab(int tab[], int taille);
void swap_tab(int tab[], int i, int j);
void triABullesOptimiseTab(int tab[], int taille);
void triInsertionTab(int tab[], int taille);
void triSelectionTab(int tab[], int taille);
int verif_tab(int tab[], int taille);
void triFusionIteratifTab(int tableau[], int taille);
void fusionnerTriTab(int tab[], int gauche, int milieu, int droite);
int rechercheDichoRec(int tab[], int gauche, int droite, int valeur);