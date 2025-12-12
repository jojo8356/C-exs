#include <stdio.h>

int main(){
    int lines;
    printf("Combien de lignes? ");
    scanf("%d", &lines);
    printf("\n\n\n");
    int total = lines*2+1;
    for (int i = 0; i < lines; i++){
        int stars = 1+i*2;
        int space = total-stars;
        for (int x = 0; x < space/2; x++)
            printf(" ");
        for (int x = 0; x < stars; x++)
            printf("*");
        for (int x = 0; x < space/2; x++)
            printf(" ");
        printf("\n");
    }
    for (int i = lines; i >= 0; i--){
        int stars = 1+i*2;
        int space = total-stars;
        for (int x = 0; x < space/2; x++)
            printf(" ");
        for (int x = 0; x < stars; x++)
            printf("*");
        for (int x = 0; x < space/2; x++)
            printf(" ");
        printf("\n");
    }
}