#include <stdio.h>
#include <stdlib.h>
#include "../../lib/tableaux.h"

int main(){
    int len;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &len);
    int *tab = (int *)malloc(len * sizeof(int));

    if (tab == NULL) {
        fprintf(stderr, "L'allocation mémoire n'a pas réussi\n");
        return 1;
    }
    
    // get tab values
    for (int i = 0; i < len; i++){
        printf("Entrez la valeur pour l'élément %d: \n", i);
        scanf("%d", &tab[i]);
    }
    
    printf("\nLe tableau est : ");
    print_tab(tab, len);
    
    free(tab);
    return 0;
}