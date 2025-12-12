#include <stdio.h>

void goSouthEast(int* lat, int* lon) {
  *lat = *lat - 1;
  *lon = *lon + 1;
}

int main() {
  int latitude = 43;
  int longitude = 7;

  printf("Coordonnées initiales: (%d, %d)\n", latitude, longitude);

  goSouthEast(&latitude, &longitude);

  printf("Coordonnées finales  : (%d, %d)\n", latitude, longitude);
  return 0;
}
