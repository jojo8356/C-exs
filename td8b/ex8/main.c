#include <stdio.h>

int pgcdRec(int a, int b) {
    if (a == b) // cas de base
        return a;
    if (a > b)
        return pgcdRec(a - b, b);
    else
        return pgcdRec(a, b - a);
}

int main() {
    int x = 48, y = 18;
    printf("PGCD de %d et %d = %d\n", x, y, pgcdRec(x, y));
    return 0;
}
