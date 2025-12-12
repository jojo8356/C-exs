#include <stdio.h>

/*
int main(){
    char min = 0b10000000;
    char max = 0b01111111;
    char zero = 0b00000000;
    printf("min: %d\n", min);
    printf("max: %d\n", max);
    printf("zero: %d\n", zero);
}
*/

int main() {
  int min = 0x7FFFFFFF;
  int max = 0x80000000;
  int zero = 0x00000000;
  printf("min: %d\n", min);
  printf("max: %d\n", max);
  printf("zero: %d\n", zero);
}