#include <stdio.h>

/* 1.
a = 30
b = 4
div = 0
TANT QUE a > b{
    a = a - b;
    div = div + 1;
}
*/

/* 2.
int main() {
  int a = 30;
  int temp = a;
  int b = 4;
  int div = 0;
  while (temp > b) {
    temp -= b;
    div++;
  }
  int rest = temp;
  printf("%d / %d\n = %d", a, b, div);
}
*/

int main() {
  int a = 30;
  int temp = a;
  int b = 4;
  int div = 0;
  while (temp > b) {
    temp -= b;
    div++;
  }
  int rest = temp;
  printf(
      "%d / %d =\nQuotient de la division entière : %d\nReste de la division "
      "entière : %d\n",
      a, b, div, rest);

  return 0;
}