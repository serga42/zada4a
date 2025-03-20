#include "counter.h"

static int count = 0;

int incrementCounter() {
  count++;
  return count;
}

int getCount() {
    return count;
}