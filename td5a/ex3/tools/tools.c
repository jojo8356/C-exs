#include "tools.h"

#include <stdio.h>

#include "limits.h"

int decrease(int init) {
  if (init < INT_MIN || init > INT_MAX) {
    fprintf(stderr,
            "GccException: Runtime Error: %d - 1 = %ld\nOverflow "
            "detected %ld ne peut être décrémenté\n",
            INT_MIN, (long)INT_MIN - 1, (long)INT_MIN - 1);
  }
  return init - 1;
}

int increase(int init) {
  if (init < INT_MIN || init > INT_MAX) {
    fprintf(
        stderr,
        "GccException: Runtime Error: 2147483646 + 1 = 2147483647\nOverflow "
        "detected 2147483647 ne peut être incrémenté\n");
  }
  return init + 1;
}

bool greaterThan(int a, int b) { return a > b; }

bool lowerThan(int a, int b) { return a < b; }

bool equalTo(int a, int b) { return a == b; };

bool isMultiple(int a, int b) { return a % b == 0; }

int absValue(int nb) {
  if (nb < 0) return -nb;
  return nb;
}