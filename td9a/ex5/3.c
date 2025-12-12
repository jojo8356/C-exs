#include <stdio.h>

typedef struct {
  int latitude;
  int longitude;
} Coordonnees;

void goSouthEast(Coordonnees* pos) {
  pos->latitude -= 1;
  pos->longitude += 1;
}

int main() {
  Coordonnees position = {43, 7};

  printf("Coordonnées initiales: (%d, %d)\n", position.latitude,
         position.longitude);

  goSouthEast(&position);

  printf("Coordonnées finales  : (%d, %d)\n", position.latitude,
         position.longitude);
  return 0;
}
