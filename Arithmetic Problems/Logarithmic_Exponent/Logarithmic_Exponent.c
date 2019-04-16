#include <stdio.h>

long long exponent (int base, int power) {
  long long result = 1, value = base;

  while (power) {
    if (power & 1)
      result *= value;
    value *= value;

    power >>= 1;
  }

  return result;
}

int main () {
  int base = 2, power = 32;
  printf("Value of %d raised to the power %d is %lld", base, power, exponent(base, power));
  return 0;
}

/*
Output:
Value of 2 raised to the power 32 is 4294967296
*/
