#include <stdio.h>

int additionTerminaleHelper(int a, int b, int acc) {
    if (b == 0)
        return acc + a;
    return additionTerminaleHelper(a + 1, b - 1, acc);
}

int additionTerminale(int a, int b) {
    return additionTerminaleHelper(a, b, 0);
}

int main() {
    int x = 5, y = 3;
    printf("%d + %d = %d\n", x, y, additionTerminale(x, y));
    return 0;
}
