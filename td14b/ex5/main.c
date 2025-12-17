#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expr_arbre.h"
#include "../../lib/pilegen.h"

// ============================================================================
// Implémentation des fonctions de l'arbre d'expression
// ============================================================================

bool estOperateur(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

NoeudExpr* creerNoeudOperande(int valeur) {
    NoeudExpr* noeud = malloc(sizeof(NoeudExpr));
    noeud->type = OPERANDE;
    noeud->valeur = valeur;
    noeud->gauche = NULL;
    noeud->droit = NULL;
    return noeud;
}

NoeudExpr* creerNoeudOperateur(char op, NoeudExpr* gauche, NoeudExpr* droit) {
    NoeudExpr* noeud = malloc(sizeof(NoeudExpr));
    noeud->type = OPERATEUR;
    noeud->operateur = op;
    noeud->gauche = gauche;
    noeud->droit = droit;
    return noeud;
}

NoeudExpr* construireArbrePostfixe(const char* expression) {
    PileGen* pile = creerPileGen();
    char* copie = strdup(expression);
    char* token = strtok(copie, " \t\n");

    while (token != NULL) {
        if (strlen(token) == 1 && estOperateur(token[0])) {
            NoeudExpr* droit = depilerGen(pile);
            NoeudExpr* gauche = depilerGen(pile);
            if (gauche == NULL || droit == NULL) {
                fprintf(stderr, "Erreur: expression postfixe invalide\n");
                free(copie);
                detruirePileGen(pile);
                return NULL;
            }
            empilerGen(pile, creerNoeudOperateur(token[0], gauche, droit));
        } else {
            empilerGen(pile, creerNoeudOperande(atoi(token)));
        }
        token = strtok(NULL, " \t\n");
    }

    NoeudExpr* racine = depilerGen(pile);
    if (!estVidePileGen(pile)) {
        fprintf(stderr, "Erreur: expression postfixe invalide\n");
    }

    free(copie);
    detruirePileGen(pile);
    return racine;
}

void afficherPrefixe(NoeudExpr* racine) {
    if (racine == NULL) return;
    if (racine->type == OPERATEUR) {
        printf("%c ", racine->operateur);
    } else {
        printf("%d ", racine->valeur);
    }
    afficherPrefixe(racine->gauche);
    afficherPrefixe(racine->droit);
}

void afficherInfixeRec(NoeudExpr* racine) {
    if (racine == NULL) return;
    if (racine->type == OPERATEUR) {
        printf("(");
        afficherInfixeRec(racine->gauche);
        printf(" %c ", racine->operateur);
        afficherInfixeRec(racine->droit);
        printf(")");
    } else {
        printf("%d", racine->valeur);
    }
}

void afficherInfixe(NoeudExpr* racine) {
    if (racine == NULL) return;
    if (racine->type == OPERATEUR) {
        afficherInfixeRec(racine->gauche);
        printf(" %c ", racine->operateur);
        afficherInfixeRec(racine->droit);
    } else {
        printf("%d", racine->valeur);
    }
}

void afficherPostfixe(NoeudExpr* racine) {
    if (racine == NULL) return;
    afficherPostfixe(racine->gauche);
    afficherPostfixe(racine->droit);
    if (racine->type == OPERATEUR) {
        printf("%c ", racine->operateur);
    } else {
        printf("%d ", racine->valeur);
    }
}

int evaluerArbre(NoeudExpr* racine) {
    if (racine == NULL) return 0;
    if (racine->type == OPERANDE) return racine->valeur;

    int g = evaluerArbre(racine->gauche);
    int d = evaluerArbre(racine->droit);

    switch (racine->operateur) {
        case '+': return g + d;
        case '-': return g - d;
        case '*': return g * d;
        case '/':
            if (d == 0) {
                fprintf(stderr, "Erreur: division par zero\n");
                exit(1);
            }
            return g / d;
    }
    return 0;
}

void libererArbreExpr(NoeudExpr** racine) {
    if (*racine == NULL) return;
    libererArbreExpr(&(*racine)->gauche);
    libererArbreExpr(&(*racine)->droit);
    free(*racine);
    *racine = NULL;
}

// ============================================================================
// Programme principal
// ============================================================================

int main() {
    char expression[256];

    printf("Entrez une expression postfixe : ");
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }

    NoeudExpr* racine = construireArbrePostfixe(expression);
    if (racine == NULL) return 1;

    printf("Arbre en prefixe : ");
    afficherPrefixe(racine);
    printf("\n");

    printf("Arbre en infixe : ");
    afficherInfixe(racine);
    printf("\n");

    printf("Arbre en postfixe : ");
    afficherPostfixe(racine);
    printf("\n");

    printf("Resultat : %d\n", evaluerArbre(racine));

    libererArbreExpr(&racine);
    return 0;
}
