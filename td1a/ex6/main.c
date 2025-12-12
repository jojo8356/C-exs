#include <stdio.h>

/* 10.
int main() {
  double f;
  double c;
  printf("Entrez une température en °F: ");
  scanf("%lf", &f);
  c = (f - 32) * 5 / 9;
  printf("Temperature de %lf °C\n", c);
  return 0;
}
*/

int main() {
  double f;
  double c;
  for (int i = 0; i <= 10; i++) {
    c = (double)i * 10;
    f = c * 9 / 5 + 32;
    printf("%lf°C = %lf°F\n", c, f);
  }
  return 0;
}