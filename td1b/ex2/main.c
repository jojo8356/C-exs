#include <stdio.h>

/*
int main() {
  double x;
  double y;
  double maxi;
  printf("Donnez deux valeurs numériques\n");
  scanf("%lf %lf", &x, &y);
  if (x > y)
    maxi = x;
  else
    maxi = y;
  printf("Le plus grand nombre de %lf, %lf est %lf\n", x, y, maxi);
  return 0;
}
*/

/*
Variables x, y, z et maxi numériques
AFFICHER "Donnez trois valeurs numériques"
LIRE x, y et z
SI x > y AND x > z ALORS
    maxi = x;
SINON SI y > x AND y > z ALORS
    maxi = y
SINON
    maxi = z;
AFFICHER Le plus grand nombre de <x>, <y>, <z> est <maxi>
*/

int main() {
  double x;
  double y;
  double z;
  double maxi;
  printf("Donnez trois valeurs numériques\n");
  scanf("%lf %lf %lf", &x, &y, &z);
  if (x > y && x > z)
    maxi = x;
  else if (y > x && y > z)
    maxi = y;
  else
    maxi = z;
  printf("Le plus grand nombre de %lf, %lf, %lf est %lf\n", x, y, z, maxi);
  return 0;
}