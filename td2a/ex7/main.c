#include <stdio.h>

int main(){
    printf("  |");
    for (int i = 1; i <= 10; i++)
        printf("%4d",i);
    printf("\n-------------------------------------------\n");
    for (int x = 1; x <= 10; x++){
        printf("%2d|", x);
        for (int y = 1; y <= 10; y++){
            printf("%4d", x*y);
        }
        printf("\n");
    }
}