#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERVALLE_MAX 200
#define DUREE_TRAITEMENT_MAX 150

typedef struct {
    int numero;
    int dateArrivee;
    int dureeTraitement;
} Client;

typedef struct Noeud {
    Client donnee;
    struct Noeud* suivant;
} Noeud;

typedef struct {
    Noeud* tete;
    Noeud* queue;
} File;

int randint(int min, int max) {
    return min + rand() % (max - min + 1);
}

void enfiler(File *file, Client client) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee = client;
    nouveau->suivant = NULL;
    if (file->queue == NULL) {
        file->tete = nouveau;
    } else {
        file->queue->suivant = nouveau;
    }
    file->queue = nouveau;
}

void rempliFileClients(File *file) {
    int n;
    printf("Entrer le nombre de clients\n");
    scanf("%d", &n);

    int date_courante = 0; // 0 = 08:00:00
    for (int i = 0; i < n; i++) {
        Client client;
        client.numero = i + 1;
        int intervalle = randint(0, INTERVALLE_MAX);
        date_courante += intervalle;
        client.dateArrivee = date_courante;
        client.dureeTraitement = randint(0, DUREE_TRAITEMENT_MAX);
        enfiler(file, client);
    }
}

Client *defiler(File *file) {
    if (file->tete == NULL) return NULL;
    Noeud* temp = file->tete;
    Client* client = (Client*)malloc(sizeof(Client));
    *client = temp->donnee;
    file->tete = file->tete->suivant;
    if (file->tete == NULL) file->queue = NULL;
    free(temp);
    return client;
}

void afficherHeure(int secondes) {
    int h = 8 + secondes / 3600;
    int m = (secondes % 3600) / 60;
    int s = secondes % 60;
    printf("%02d:%02d:%02d", h, m, s);
}

int main() {
    srand((unsigned int)time(NULL));
    File file = {NULL, NULL};
    rempliFileClients(&file);

    printf("Traitement des clients dans l'ordre d'arrivée :\n");

    int temps_courant = 0;
    Client* client;
    while ((client = defiler(&file)) != NULL) {
        int debut_traitement = (client->dateArrivee > temps_courant) ? client->dateArrivee : temps_courant;
        int fin_traitement = debut_traitement + client->dureeTraitement;

        printf("Client %d: arrive à ", client->numero);
        afficherHeure(client->dateArrivee);
        printf(", début traitement à ");
        afficherHeure(debut_traitement);
        printf(", fin traitement à ");
        afficherHeure(fin_traitement);
        printf("\n");

        temps_courant = fin_traitement;
        free(client);
    }
    return 0;
}
