#include <stdio.h>

typedef struct {
  int latitude;
  int longitude;
} Coordonnees;

Coordonnees goSouthEast(Coordonnees pos) {
  pos.latitude -= 1;
  pos.longitude += 1;
  return pos;
}

int main() {
  Coordonnees position = {43, 7};

  printf("Coordonnées initiales: (%d, %d)\n", position.latitude,
         position.longitude);

  position = goSouthEast(position);

  printf("Coordonnées finales  : (%d, %d)\n", position.latitude,
         position.longitude);
  return 0;
}
