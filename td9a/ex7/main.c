#include <stdio.h>
#include <string.h>

typedef enum {
    FORCE,
    VITESSE,
    INTELLIGENCE
} TypePouvoir;

typedef union {
    int force;
    float vitesse;
    int intelligence;
} Pouvoir;

typedef struct {
    char nom[50];
    TypePouvoir type;
    Pouvoir pouvoir;
} SuperHeros;

void afficherSuperHeros(SuperHeros hero) {
    printf("Nom: %s\n", hero.nom);
    switch (hero.type) {
        case FORCE:
            printf("Force: %d\n", hero.pouvoir.force);
            break;
        case VITESSE:
            printf("Vitesse: %f\n", hero.pouvoir.vitesse);
            break;
        case INTELLIGENCE:
            printf("Intelligence: %d\n", hero.pouvoir.intelligence);
            break;
        default:
            printf("Type de pouvoir inconnu.\n");
    }
}

int main() {
    SuperHeros superman;
    strcpy(superman.nom, "Superman");
    superman.type = FORCE;
    superman.pouvoir.force = 100;

    SuperHeros flash;
    strcpy(flash.nom, "Flash");
    flash.type = VITESSE;
    flash.pouvoir.vitesse = 99.9f;

    SuperHeros batman;
    strcpy(batman.nom, "Batman");
    batman.type = INTELLIGENCE;
    batman.pouvoir.intelligence = 150;

    afficherSuperHeros(superman);
    afficherSuperHeros(flash);
    afficherSuperHeros(batman);

    return 0;
}
