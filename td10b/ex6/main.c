#include <stdio.h>
#include <stdlib.h>

int main(){
    char *path = (char *)malloc(256 * sizeof(char));
    if (path == NULL){
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }
    printf("Entrer un chemin d'accés: \n");
    scanf("%s", path);
    int i = 0;
    while (path[i]){
        printf("%c", path[i]);
        if (path[i + 1]){
            printf(" ");
        }
        i++;
    }
    printf("\nLa longueur de la chaine est: %d\n", i);
    free(path);
    return 0;
}