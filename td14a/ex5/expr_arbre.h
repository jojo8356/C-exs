#pragma once

#include <stdbool.h>

// Type de noeud: opérateur ou opérande
typedef enum { OPERANDE, OPERATEUR } TypeNoeud;

// Structure d'un noeud de l'arbre d'expression
typedef struct NoeudExpr {
  TypeNoeud type;
  union {
    int valeur;    // si OPERANDE
    char operateur; // si OPERATEUR (+, -, *, /)
  };
  struct NoeudExpr* gauche;
  struct NoeudExpr* droit;
} NoeudExpr;

// Construction de l'arbre
NoeudExpr* creerNoeudOperande(int valeur);
NoeudExpr* creerNoeudOperateur(char op, NoeudExpr* gauche, NoeudExpr* droit);
NoeudExpr* construireArbrePostfixe(const char* expression);

// Affichage
void afficherPrefixe(NoeudExpr* racine);
void afficherInfixe(NoeudExpr* racine);
void afficherPostfixe(NoeudExpr* racine);

// Évaluation
int evaluerArbre(NoeudExpr* racine);

// Libération mémoire
void libererArbreExpr(NoeudExpr** racine);

// Vérification
bool estOperateur(char c);
