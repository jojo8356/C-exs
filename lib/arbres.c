#include "arbres.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "filegen.h"
#include "pilegen.h"

int calculerHauteurAB(NoeudAB* racine) {
  if (racine == NULL) {  // si vide
    return -1;
  } else {
    int hauteurGauche = calculerHauteurAB(racine->gauche);
    int hauteurDroite = calculerHauteurAB(racine->droit);
    return (hauteurGauche > hauteurDroite ? hauteurGauche : hauteurDroite) +
           1;  // 1 + max(gauche, droite)
  }
}

int calculerTailleAB(NoeudAB* racine) {
  if (racine == NULL) {  // si vide
    return 0;
  } else {  // si pas vide
    return 1 + calculerTailleAB(racine->gauche) +
           calculerTailleAB(racine->droit);  // 1 + taille sous-arbres gauche et
                                             // droit (parcours)
  }
}

int compterFeuillesAB(NoeudAB* racine) {
  if (racine == NULL) {  // si vide
    return 0;
  }
  if (racine->gauche == NULL && racine->droit == NULL) {  // si pas d'enfants
    return 1;
  } else {
    return compterFeuillesAB(racine->gauche) +
           compterFeuillesAB(racine->droit);  // parcours le reste de l'arbre
  }
}

bool estParfaitAB(NoeudAB* racine) {
  int hauteur = calculerHauteurAB(racine);
  int taille = calculerTailleAB(racine);
  return taille ==
         (1 << (hauteur + 1)) - 1;  // verif arbre parfait: 2^(h+1) - 1
}

int* parcourirLargeurAB(NoeudAB* racine) {
  if (racine == NULL) {
    return NULL;
  }

  int taille = calculerTailleAB(racine);
  int* resultat = malloc(taille * sizeof(int));
  if (resultat == NULL) {
    return NULL;
  }

  // File (queue) pour le parcours en largeur
  NoeudAB** file = malloc(taille * sizeof(NoeudAB*));
  if (file == NULL) {
    free(resultat);
    return NULL;
  }

  int debut = 0;  // index de début de la file
  int fin = 0;    // index de fin de la file
  int index = 0;  // index du résultat

  // Enfiler la racine
  file[fin++] = racine;

  while (debut < fin) {
    // Défiler le noeud courant
    NoeudAB* courant = file[debut++];
    resultat[index++] = courant->valeur;

    // Enfiler les enfants
    if (courant->gauche != NULL) {
      file[fin++] = courant->gauche;
    }
    if (courant->droit != NULL) {
      file[fin++] = courant->droit;
    }
  }

  free(file);
  return resultat;
}

void parcoursPrefixe(NoeudAB* racine) {
  if (racine != NULL) {
    printf("%d ", racine->valeur);
    parcoursPrefixe(racine->gauche);
    parcoursPrefixe(racine->droit);
  }
}

void parcoursInfixe(NoeudAB* racine) {
  if (racine != NULL) {
    parcoursInfixe(racine->gauche);
    printf("%d ", racine->valeur);
    parcoursInfixe(racine->droit);
  }
}

void parcoursSuffixe(NoeudAB* racine) {
  if (racine != NULL) {
    parcoursSuffixe(racine->gauche);
    parcoursSuffixe(racine->droit);
    printf("%d ", racine->valeur);
  }
}

/*
void parcourirProfondeurAB(NoeudAB* racine, DFSOrdre ordre) {
  switch (ordre) {
    case PRE:
      parcoursPrefixe(racine);
      break;
    case IN:
      parcoursInfixe(racine);
      break;
    case POST:
      parcoursSuffixe(racine);
      break;
    default:
      printf("Ordre de parcours inconnu.\n");
      break;
  }
}
*/

void parcourirProfondeurAB(NoeudAB* racine, DFSOrdre ordre, bool inverse) {
  if (racine == NULL) {
    return;
  }
  if (ordre == PRE) {
    printf("%d ", racine->valeur);
  }
  if (inverse) {
    parcourirProfondeurAB(racine->droit, ordre, inverse);
    if (ordre == IN) {
      printf("%d ", racine->valeur);
    }
    parcourirProfondeurAB(racine->gauche, ordre, inverse);
  } else {
    parcourirProfondeurAB(racine->gauche, ordre, inverse);
    if (ordre == IN) {
      printf("%d ", racine->valeur);
    }
    parcourirProfondeurAB(racine->droit, ordre, inverse);
  }
  if (ordre == POST) {
    printf("%d ", racine->valeur);
  }
}

void libererAB(NoeudAB** racine) {
  NoeudAB* courant = *racine;
  if (courant != NULL) {
    // libérer les sous-arbres
    // -> est prioritaire sur &
    libererAB(&courant->gauche);
    libererAB(&courant->droit);

    // libérer la mémoire du noeud courant
    free(*racine);
    // mettre le pointeur à NULL
    *racine = NULL;
  }
}

// Ancienne version simple (parcours préfixe)
// void afficherABSimple(NoeudAB* racine) {
//   if (racine == NULL) {
//     printf("Arbre vide\n");
//     return;
//   }
//   printf("Arbre (parcours préfixe): ");
//   parcoursPrefixe(racine);
//   printf("\n");
// }

NoeudAB* creerExempleAB() {
  // Création de la racine et de ses sous-arbres
  NoeudAB* racine = malloc(sizeof(NoeudAB));
  racine->valeur = 2;
  NoeudAB* n7 = malloc(sizeof(NoeudAB));
  n7->valeur = 7;
  NoeudAB* n5 = malloc(sizeof(NoeudAB));
  n5->valeur = 5;
  NoeudAB* n6 = malloc(sizeof(NoeudAB));
  n6->valeur = 6;
  NoeudAB* n2 = malloc(sizeof(NoeudAB));
  n2->valeur = 2;
  NoeudAB* n9 = malloc(sizeof(NoeudAB));
  n9->valeur = 9;
  NoeudAB* n52 = malloc(sizeof(NoeudAB));
  n52->valeur = 5;
  NoeudAB* n11 = malloc(sizeof(NoeudAB));
  n11->valeur = 11;
  NoeudAB* n4 = malloc(sizeof(NoeudAB));
  n4->valeur = 4;

  // arêtes
  racine->gauche = n7;
  racine->droit = n5;
  n7->gauche = n2;
  n7->droit = n6;
  n6->gauche = n52;
  n6->droit = n11;
  n5->gauche = NULL;
  n5->droit = n9;
  n9->gauche = n4;
  n9->droit = NULL;

  // feuilles à NULL
  n2->gauche = NULL;
  n2->droit = NULL;
  n52->gauche = NULL;
  n52->droit = NULL;
  n11->gauche = NULL;
  n11->droit = NULL;
  n4->gauche = NULL;
  n4->droit = NULL;

  return racine;
}

int calculerTailleTabAB(int* tab, int taille) {  // compter les nœuds non vides
  int count = 0;
  for (int i = 0; i < taille; i++) {
    if (tab[i] != -1) {  // -1: nœud vide
      count++;
    }
  }
  return count;
}

int compterFeuillesTabAB(int* tab, int taille) {
  int count = 0;
  for (int i = 0; i < taille; i++) {
    if (tab[i] != -1) {             // si le nœud existe
      int gaucheIndex = 2 * i + 1;  // index enfant gauche
      int droiteIndex = 2 * i + 2;  // index enfant droit
      // vérifier si les enfants sont hors limites ou vides
      bool gaucheVide = (gaucheIndex >= taille) || (tab[gaucheIndex] == -1);
      bool droiteVide = (droiteIndex >= taille) || (tab[droiteIndex] == -1);
      if (gaucheVide && droiteVide) {
        count++;
      }
    }
  }
  return count;
}

int calculerHauteurTabAB(int* tab, int taille) {
  int hauteur = -1;
  int index = 0;
  while (index < taille) {
    hauteur++;
    index = 2 * index + 2;  // aller au dernier nœud du niveau actuel
  }
  return hauteur;
}

bool estParfaitTabAB(int* tab, int taille) {
  int hauteur = calculerHauteurTabAB(tab, taille);
  int tailleArbre = calculerTailleTabAB(tab, taille);
  return tailleArbre ==
         (1 << (hauteur + 1)) - 1;  // verif arbre parfait: 2^(h+1) - 1
}

bool verifierTabAB(int* tab, int taille) {
  if (tab == NULL || taille == 0) {
    return false;
  }
  // Vérifier que chaque nœud (sauf la racine) a un parent non-vide
  for (int i = 1; i < taille; i++) {
    if (tab[i] != -1) {  // si le nœud existe
      int parent =
          (i - 1) / 2;  // formule pour trouver le parent dans un tableau
      if (tab[parent] == -1) {  // si le parent n'existe pas
        return false;
      }
    }
  }
  return true;
}

void parcoursLargeur(NoeudAB* racine) {
  if (racine == NULL) {
    printf("Arbre vide.\n");
    return;
  }

  FileGen* file = creerFileGen();
  enfilerGen(file, racine);

  while (!estVideFileGen(file)) {
    NoeudAB* courant = defilerGen(file);
    printf("%d ", courant->valeur);

    if (courant->gauche != NULL) {
      enfilerGen(file, courant->gauche);
    }
    if (courant->droit != NULL) {
      enfilerGen(file, courant->droit);
    }
  }
  detruireFileGen(file);
  printf("\n");
}

void parcourirPreItAB(NoeudAB* racine) {
  if (racine == NULL) {
    return;
  }

  PileGen* stack = creerPileGen();
  empilerGen(stack, racine);

  while (!estVidePileGen(stack)) {
    NoeudAB* courant = depilerGen(stack);
    printf("%d ", courant->valeur);

    if (courant->droit != NULL) empilerGen(stack, courant->droit);
    if (courant->gauche != NULL) empilerGen(stack, courant->gauche);
  }
  detruirePileGen(stack);
  printf("\n");
}

void parcourirInItAB(NoeudAB* racine) {
  if (racine == NULL) {
    return;
  }

  PileGen* stack = creerPileGen();
  NoeudAB* courant = racine;

  while (!estVidePileGen(stack) || courant != NULL) {
    if (courant != NULL) {
      empilerGen(stack, courant);
      courant = courant->gauche;
    } else {
      courant = depilerGen(stack);
      printf("%d ", courant->valeur);
      courant = courant->droit;
    }
  }
  detruirePileGen(stack);
  printf("\n");
}

void parcourirPostItAB(NoeudAB* racine) {
  if (racine == NULL) {
    return;
  }

  PileGen* stack = creerPileGen();
  NoeudAB* courant = racine;
  NoeudAB* lastVisited = NULL;

  while (!estVidePileGen(stack) || courant != NULL) {
    if (courant != NULL) {
      empilerGen(stack, courant);
      courant = courant->gauche;
    } else {
      NoeudAB* peekNode = sommetPileGen(stack);
      if (peekNode->droit != NULL && lastVisited != peekNode->droit) {
        courant = peekNode->droit;
      } else {
        printf("%d ", peekNode->valeur);
        lastVisited = depilerGen(stack);
      }
    }
  }
  detruirePileGen(stack);
  printf("\n");
}

NoeudAB* creerArbreDunTab(int* tab, int taille, int index) {
  if (index >= taille || tab[index] == -1) {
    return NULL;
  }

  NoeudAB* noeud = malloc(sizeof(NoeudAB));
  noeud->valeur = tab[index];
  noeud->gauche = creerArbreDunTab(tab, taille, 2 * index + 1);
  noeud->droit = creerArbreDunTab(tab, taille, 2 * index + 2);
  return noeud;
}

NoeudAB* creerNoeudAB(int valeur) {
  NoeudAB* noeud = malloc(sizeof(NoeudAB));
  noeud->valeur = valeur;
  noeud->droit = NULL;
  noeud->gauche = NULL;
  return noeud;
}

void printSpace(int nb) {
  while (nb--) {
    printf(" ");
  }
}

int puissance(int nb, int p) {
  int result = 1;
  while (p-- > 0) {
    result *= nb;
  }
  return result;
}

static NoeudAB noeudVide = {-1, NULL, NULL};

void afficherAB(NoeudAB* racine) {
  if (racine == NULL) {
    printf("Arbre vide.\n");
    return;
  }

  int h = calculerHauteurAB(racine);
  int w = 2;

  int tailleMax = puissance(2, h + 1);
  NoeudAB** niveau = malloc(tailleMax * sizeof(NoeudAB*));
  NoeudAB** prochainNiveau = malloc(tailleMax * sizeof(NoeudAB*));

  niveau[0] = racine;
  int tailleNiveau = 1;

  for (int p = 0; p <= h; p++) {
    int facteur = puissance(2, h - p);
    int espaceIni = facteur * w - w;
    int espaceInter = 2 * facteur * w - w;

    printSpace(espaceIni);

    int tailleProchain = 0;

    for (int i = 0; i < tailleNiveau; i++) {
      NoeudAB* courant = niveau[i];

      if (courant == &noeudVide) {
        printSpace(w);
      } else {
        printf("%2d", courant->valeur);
      }

      if (i < tailleNiveau - 1) {
        printSpace(espaceInter);
      }

      if (p < h) {
        if (courant == &noeudVide) {
          prochainNiveau[tailleProchain++] = &noeudVide;
          prochainNiveau[tailleProchain++] = &noeudVide;
        } else {
          prochainNiveau[tailleProchain++] =
              (courant->gauche != NULL) ? courant->gauche : &noeudVide;
          prochainNiveau[tailleProchain++] =
              (courant->droit != NULL) ? courant->droit : &noeudVide;
        }
      }
    }

    printf("\n");

    NoeudAB** tmp = niveau;
    niveau = prochainNiveau;
    prochainNiveau = tmp;
    tailleNiveau = tailleProchain;
  }

  free(niveau);
  free(prochainNiveau);
}