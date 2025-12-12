#include <limits.h>
#include <stdio.h>

void bar() {
  printf(
      "+------------------+-------------------------+-------------------------+"
      "\n");
}

int main() {
  bar();
  printf("| %-17s|%24s |%24s |\n", "Type", "Minimum", "Maximum");
  bar();
  printf("| %-17s|%24d |%24d |\n", "signed char", SCHAR_MIN, SCHAR_MAX);
  printf("| %-17s|%24d |%24d |\n", "short", SHRT_MIN, SHRT_MAX);
  printf("| %-17s|%24d |%24d |\n", "int", INT_MIN, INT_MAX);
  printf("| %-17s|%24ld |%24ld |\n", "long", LONG_MIN, LONG_MAX);
  printf("| %-17s|%24ld |%24ld |\n", "long long", LONG_MIN, LONG_MAX);
  bar();
}