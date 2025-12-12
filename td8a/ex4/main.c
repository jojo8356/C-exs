#include <stdio.h>

int somme(int n) {
    if (n == 0) return 0;
    return n + somme(n - 1);
}

int sommeIT(int n) {
    int s = 0;
    for (int i = 1; i<=n; i++){
        s += i;
    }
    return s;
}

int sommePuissance4(int n) {
    if (n == 0) return 0;
    return n * n * n * n + sommePuissance4(n - 1);
}

int sommePuissance4IT(int n) {
    int s = 0;
    for (int i = 1; i<=n; i++){
        s += i*i*i*i;
    }
    return s;
}

int main() {
    int u6 = somme(6);
    int s4 = sommePuissance4(3);

    printf("u(6) = %d\n", u6);
    printf("sommePuissance4(3) = %d\n\n", s4);

    u6 = sommeIT(6);
    s4 = sommePuissance4IT(3);

    printf("uRec(6) = %d\n", u6);
    printf("sommePuissance4Rec(3) = %d\n", s4);

    return 0;
}
