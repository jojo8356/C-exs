#include <stdio.h>

/*
int main(){
    int nb;
printf("Indiquer un nombre entier entre 1 et 12: ");
scanf("%d", &nb);
printf(" 1 x %d = %d\n", nb, nb * 1);
printf(" 2 x %d = %d\n", nb, nb * 2);
printf(" 3 x %d = %d\n", nb, nb * 3);
printf(" 4 x %d = %d\n", nb, nb * 4);
printf(" 5 x %d = %d\n", nb, nb * 5);
printf(" 6 x %d = %d\n", nb, nb * 6);
printf(" 7 x %d = %d\n", nb, nb * 7);
printf(" 8 x %d = %d\n", nb, nb * 8);
printf(" 9 x %d = %d\n", nb, nb * 9);
}
*/

int main(){
    int nb;
    do{
        printf("Indiquer un nombre entier entre 1 et 12: ");
        scanf(" %d", &nb);
    } while (nb < 1 || nb > 12);
    for (int i = 1; i <= 9; i++)
        printf(" %d x %d = %d\n", i, nb, nb * i);
}