#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "warrior.h"

char NAME_POOL[4][NAME_LENGTH] = {
    "Ulf",
    "Brantuas",
    "Boros",
    "Tinker",
};

Warrior createRandomWarrior() {
  int numNames = 4;
  static bool isInit = false;

  if (!isInit) {
    srand(time(NULL));
    isInit = true;
  }

  int i = rand() % numNames;
  char *name = NAME_POOL[i];

  return createWarrior(name);
}
