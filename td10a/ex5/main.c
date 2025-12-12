#include <stdio.h>
#include <stdlib.h>
#include "../../lib/tableaux.h"

int main(){
    int* monTableau = tableauScanfTaille(5);
    free(monTableau);
    return 0;
}