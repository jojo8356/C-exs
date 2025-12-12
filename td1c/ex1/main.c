#include <stdio.h>

double calculAire(double a, double b) { return a * b; }

double calculPerimetre(double longueur, double largeur) {
  return (longueur + largeur) * 2;
}

void afficheInfos(double longueur, double largeur) {
  printf("Le périmètre du rectangle est %lf cm.\n",
         calculPerimetre(longueur, largeur));
  printf("L'aire du rectangle est %lf cm.\n", calculAire(longueur, largeur));
}

int main() {
  double longueur, largeur;
  printf("Indiquez la longueur en cm: ");
  scanf("%lf", &longueur);
  printf("Indiquez la largeur en cm: ");
  scanf("%lf", &largeur);
  afficheInfos(longueur, largeur);

  return 0;
}