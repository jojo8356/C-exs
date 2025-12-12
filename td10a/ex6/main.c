#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* entreeUtilisateur(int len_max){
    char* buffer = (char *)malloc((len_max + 1) * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "L'allocation mémoire n'a pas réussi\n");
        exit(0);
    }

    printf("Entrez un texte (max %d caractères) : ", len_max);
    fgets(buffer, len_max + 1, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}
*/

char* entreeUtilisateur(int len_max, char *msg){
    char* buffer = (char *)malloc((len_max + 1) * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "L'allocation mémoire n'a pas réussi\n");
        exit(1);
    }

    printf("%s", msg);
    fgets(buffer, len_max + 1, stdin);
    // strcspn: get pos of one of target elements (any of "\n")
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

int main(){
    const int TAILLE_MAX = 128;
    char* texte = entreeUtilisateur(TAILLE_MAX, "Entrez une chaîne de caractères: ");
    printf("User : %s\n",texte);
    free(texte);
    return 0;
}