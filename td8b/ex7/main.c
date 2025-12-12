#include <stdio.h>

int poidsNombre(int nb) {
    if (nb < 10)
        return nb;
    return (nb % 10) * poidsNombre(nb / 10);
}

int main() {
    int n = 234;
    printf("Poids de %d = %d\n", n, poidsNombre(n));
    return 0;
}
