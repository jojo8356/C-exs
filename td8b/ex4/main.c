#include <stdio.h>

int additionNonTerminale(int a, int b) {
    if (b == 0)
        return a;
    return 1 + additionNonTerminale(a, b - 1);
}

int main() {
    int x = 5, y = 3;
    printf("%d + %d = %d\n", x, y, additionNonTerminale(x, y));
    return 0;
}
