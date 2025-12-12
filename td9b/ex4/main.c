#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100

typedef struct {
    char titre[100];
    char auteur[100];
    int anneePub;
} Livre;

typedef struct {
    char nom[100];
    int nbLivre;
    Livre livres[MAX_LIVRES];
} Bibliotheque;

void ajouterLivre(Bibliotheque *biblio, Livre nouveau) {
    if (biblio->nbLivre < MAX_LIVRES) {
        biblio->livres[biblio->nbLivre] = nouveau;
        biblio->nbLivre++;
    } else {
        printf("⚠️ La bibliothèque est pleine !\n");
    }
}

void afficherBibliotheque(Bibliotheque *biblio) {
    printf("Bibliothèque: %s, Nombre de livres: %d\n", biblio->nom, biblio->nbLivre);
    for (int i = 0; i < biblio->nbLivre; i++) {
        printf("Titre: %s, Auteur: %s, Année: %d\n",
               biblio->livres[i].titre,
               biblio->livres[i].auteur,
               biblio->livres[i].anneePub);
    }
    printf("\n");
}

void rechercherLivreParAuteur(Bibliotheque *biblio, const char *auteur) {
    printf("Livres de l'auteur %s:\n", auteur);
    int trouve = 0;
    for (int i = 0; i < biblio->nbLivre; i++) {
        if (strcmp(biblio->livres[i].auteur, auteur) == 0) {
            printf("Titre: %s, Année: %d\n",
                   biblio->livres[i].titre,
                   biblio->livres[i].anneePub);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun livre trouvé pour cet auteur.\n");
    }
    printf("\n");
}

void trierParAnnee(Bibliotheque *biblio) {
    for (int i = 1; i < biblio->nbLivre; i++) {
        Livre cle = biblio->livres[i];
        int j = i - 1;

        while (j >= 0 && biblio->livres[j].anneePub > cle.anneePub) {
            biblio->livres[j + 1] = biblio->livres[j];
            j--;
        }

        biblio->livres[j + 1] = cle;
    }
}

int main() {
    Bibliotheque maBiblio = {"Ma Bibliothèque", 0};

    Livre l1 = {"Le Petit Prince", "Antoine de Saint-Exupéry", 1943};
    Livre l2 = {"1984", "George Orwell", 1949};
    Livre l3 = {"Les Misérables", "Victor Hugo", 1862};

    ajouterLivre(&maBiblio, l1);
    ajouterLivre(&maBiblio, l2);
    ajouterLivre(&maBiblio, l3);

    printf("Bibliothèque avant le tri:\n");
    afficherBibliotheque(&maBiblio);

    trierParAnnee(&maBiblio);

    printf("Bibliothèque après le tri par année:\n");
    afficherBibliotheque(&maBiblio);

    rechercherLivreParAuteur(&maBiblio, "George Orwell");

    return 0;
}
