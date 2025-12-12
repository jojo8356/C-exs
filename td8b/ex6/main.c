#include <stdio.h>

int puissanceRecursive(int a, int b) {
    if (b == 0)
        return 1;
    return a * puissanceRecursive(a, b - 1);
}

int main() {
    int x = 2, y = 5;
    printf("%d^%d = %d\n", x, y, puissanceRecursive(x, y));
    return 0;
}
