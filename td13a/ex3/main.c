#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

int comparerDbl(const void* a, const void* b){
    return (double *)a-(double *)b;
}

int roundDouble(double val){
    return (int)(val + 0.5);
}

double distance(Point *p){
    return roundDouble(sqrt(p->x * p->x + p->y * p->y)*10)/10.0;
}

int comparePoints(const void* a, const void* b){
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;

    double dist1 = distance(p1);
    double dist2 = distance(p2);

    if (dist1 < dist2) return -1;
    else if (dist1 > dist2) return 1;
    return 0;
}

void triPoints(Point* tab, int taille){
    qsort(tab, taille, sizeof(Point), comparePoints);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

void afficherPoint(Point *tab){
    printf("(%3d, %3d) --d->  %.1f", tab->x, tab->y, distance(tab));
}

void afficherPoints(Point *tab, int taille){
    for(int i=0; i<taille; i++){
        afficherPoint(&tab[i]);
        printf("\n");
    }
}

int main(){
    printf("Affichage des points aléatoires et distances au centre\n");
    srand(time(NULL));
    int taille = 10;
    Point tab[taille];
    for(int i=0; i<taille; i++){
        tab[i].x = randint(-10, 10);
        tab[i].y = randint(-10, 10);
    }
    afficherPoints(tab, taille);

    printf("\nTri avec qsort par distance au centre\n");
    triPoints(tab, taille);
    afficherPoints(tab, taille);
    return 0;
}