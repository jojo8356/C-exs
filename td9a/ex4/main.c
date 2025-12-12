#include <stdio.h>

typedef enum {
    VERROUILLE,
    DEVERROUILLE,
    ALARME,
    MAINTENANCE
} etatSysteme;

void afficherEtat(const etatSysteme *etat) {
    switch (*etat) {
        case VERROUILLE:
            printf("Le système est verrouillé.\n");
            break;
        case DEVERROUILLE:
            printf("Le système est déverrouillé.\n");
            break;
        case ALARME:
            printf("Le système est en mode alarme.\n");
            break;
        case MAINTENANCE:
            printf("Le système est en mode maintenance.\n");
            break;
        default:
            printf("État inconnu.\n");
    }
}

void changerEtat(etatSysteme *etat) {
    *etat = (*etat + 1) % 4;
}

int main() {
    etatSysteme etat = VERROUILLE;

    printf("État initial: ");
    afficherEtat(&etat);

    for (int i = 1; i <= 5; i++) {
        changerEtat(&etat);
        printf("Changement %d: ", i);
        afficherEtat(&etat);
    }

    return 0;
}
