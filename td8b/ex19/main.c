#include <stdio.h>

void tresse(int N, int rang, int brins[4]) {
    if (rang > N)
        return;

    if (rang % 2 == 1) {
        int temp = brins[0];
        brins[0] = brins[1];
        brins[1] = temp;

        temp = brins[2];
        brins[2] = brins[3];
        brins[3] = temp;
    } else {
        int temp = brins[1];
        brins[1] = brins[2];
        brins[2] = temp;
    }

    tresse(N, rang + 1, brins);
}

int main() {
    int brins[4] = {1, 2, 3, 4};
    int N = 5;

    tresse(N, 1, brins);

    printf("Ordre final des brins : ");
    for (int i = 0; i < 4; i++)
        printf("%d ", brins[i]);
    printf("\n");

    return 0;
}
