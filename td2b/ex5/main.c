#include <stdio.h>

/*
int main(){
    for (int i = 1; i < 7; i++)
    {
        for (int x = 0; x < i; x++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}
*/

/*
int main(){
    for (int i = 1; i < 7; i++)
    {
        for (int x = 0; x < i; x++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}
*/

int main(){
    for (int i = 5; i > 0; i--)
    {
        for (int x = i; x > 0; x--)
            printf("%d", x);
        printf("\n");
    }
}