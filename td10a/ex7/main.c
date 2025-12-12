#include <stdio.h>
#include <stdlib.h>
#include "../../lib/tableaux.h"

int main(){
    int len = 10;
    int* monTableau = tableauScanfTaille(len);
    print_tab(monTableau, len);

    int new_len = len * 2;
    int* temp = realloc(monTableau, new_len * sizeof(int));
    if (temp == NULL){
        fprintf(stderr, "Reallocation mémoire a échoué\n");
        free(monTableau);
        exit(1);
    }
    monTableau = temp;

    for(int i = len; i < new_len; i++){
        monTableau[i] = -1;
    }

    print_tab(monTableau, new_len);

    free(monTableau);
    return 0;
}
