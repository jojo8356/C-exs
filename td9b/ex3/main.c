#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int ine;
    char nom[20];
    char prenom[20];
    double note;
} Etudiant;

void initialiserListeEtudiants(Etudiant t[]) {
    for (int i = 0; i < MAX_ETUDIANTS; i++) {
        t[i].ine = 0;
    }
}

int nbEtudiant(Etudiant t[]) {
    int count = 0;
    while (count < MAX_ETUDIANTS && t[count].ine != 0)
        count++;
    return count;
}

void afficherEtudiant(Etudiant e) {
    printf("%d: %s %s (Note: %.2f)\n", e.ine, e.nom, e.prenom, e.note);
}

void afficherListe(Etudiant t[]) {
    int n = nbEtudiant(t);
    for (int i = 0; i < n; i++) {
        afficherEtudiant(t[i]);
    }
}

void insererEtudiant(Etudiant t[], Etudiant nouvelEtudiant) {
    int i = nbEtudiant(t);

    if (i >= MAX_ETUDIANTS) {
        fprintf(stderr, "Nb d'étudiants maximum atteint\n");
        return;
    }

    if (i == 0) {
        t[0] = nouvelEtudiant;
        return;
    }

    int j = i - 1;
    while (j >= 0 && t[j].ine > nouvelEtudiant.ine) {
        t[j + 1] = t[j];
        j--;
    }

    t[j + 1] = nouvelEtudiant;
}

int rechercherEtudiant(Etudiant t[], int ineRecherche) {
    int debut = 0;
    int fin = nbEtudiant(t) - 1;

    while (debut <= fin) {
        int milieu = (debut + fin) / 2;

        if (t[milieu].ine == ineRecherche)
            return milieu;
        else if (t[milieu].ine < ineRecherche)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1;
}

int main() {
    Etudiant liste[MAX_ETUDIANTS];

    // initialise la liste
    initialiserListeEtudiants(liste);

    // Ajout de trois étudiants
    Etudiant etu1 = {123, "Seydoux", "Laura", 15.3};
    insererEtudiant(liste, etu1);
    Etudiant etu2 = {324, "Alexis", "Manenti", 5.9};
    insererEtudiant(liste, etu2);
    Etudiant etu3 = {255, "Camélia", "Jordana", 9.9};
    insererEtudiant(liste, etu3);

    printf("\nVoici la liste de %d étudiants triée par ine\n", nbEtudiant(liste));
    afficherListe(liste);

    // Recherche d'un étudiant
    int numeroRecherche;
    printf("\nEntrez un numéro d'étudiant à rechercher: ");
    scanf("%d", &numeroRecherche);

    int indice = rechercherEtudiant(liste, numeroRecherche);
    if (indice != -1) {
        Etudiant etu = liste[indice];
        if (etu.note > 10) {
            printf("ADMIS:) ");
        } else if (etu.note >= 8) {
            printf("RATTRAPAGE:! ");
        } else {
            printf("RECALÉ! ");
        }
        afficherEtudiant(etu);
    } else {
        printf("Étudiant non trouvé.\n");
    }

    return 0;
}
