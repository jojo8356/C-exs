#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int min, int max) {
  return min + rand() % (max - min + 1);
}

typedef struct {
  int x;
  int y;
} Point;

void translate(Point *point, int dx, int dy) {
    if (point != NULL) {
        point->x += dx;
        point->y += dy;
    }
}

void print_points(Point* points, int n) {
  for (int i = 0; i < n; i++) {
    printf("Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
  }
}

int main() {
  srand(time(NULL));
  int n = randint(5, 10);
  Point* points = (Point*)malloc(n * sizeof(Point));
  if (points == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    points[i].x = randint(-10, 10);
    points[i].y = randint(-10, 10);
  }

  print_points(points, n);

  printf("Translation et affichage des points\n");

  for (int i = 0; i < n; i++) {
    translate(&points[i], 2, -1);
  }

  print_points(points, n);

  free(points);
  return 0;
}