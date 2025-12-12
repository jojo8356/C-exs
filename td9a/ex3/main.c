#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point A, B;

    printf("Entrez les coordonnees du point A:\n");
    scanf("%lf", &A.x);
    scanf("%lf", &A.y);
    printf("A(%f, %f)\n\n", A.x, A.y);

    printf("Entrez les coordonnees du point B:\n");
    scanf("%lf", &B.x);
    scanf("%lf", &B.y);
    printf("B(%f, %f)\n\n", B.x, B.y);

    double d = distance(A, B);
    printf("La distance entre les points A et B est: %.2f\n", d);

    return 0;
}
