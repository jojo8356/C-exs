#include <stdio.h>

int multiplicationRecursive(int a, int b) {
    if (b == 0)
        return 0;
    return a + multiplicationRecursive(a, b - 1);
}

int main() {
    int x = 5, y = 3;
    printf("%d * %d = %d\n", x, y, multiplicationRecursive(x, y));
    return 0;
}
