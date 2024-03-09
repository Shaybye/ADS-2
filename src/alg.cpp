// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0)
      return 1;
  if (n == 1)
      return value;
  return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
  if (n == 1 || n == 0)
      return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  if (x == 0)
      return 0;
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (int i = 1; i <= count; ++i) 
      e+=calcItem(x, i);
  return e;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  for (int i = 2; i <= count; ++i) 
      sin += pown(-1,i-1)* calcItem(x, i*2-1);

  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  for (int i = 2; i <= count; ++i)
      cos += pown(-1, i - 1) * calcItem(x, i * 2 - 2);
  return cos;
}
