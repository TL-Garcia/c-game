#include "warrior.h"
#include <string.h>

Warrior createWarrior(char name[NAME_LENGTH]) {
  struct Warrior w = {.health = 10, .attack = 5, .defence = 5};
  strncpy(w.name, name, sizeof(w.name) - 1);

  return w;
}
