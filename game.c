#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NAME_LENGTH 21

typedef struct Warrior {
  char name[NAME_LENGTH];
  int health;
  int defence;
  int attack;
} Warrior;

char NAME_POOL[4][NAME_LENGTH] = {
  "Ulf",
  "Brantuas",
  "Boros",
  "Tinker",
};

Warrior createWarrior(char name[NAME_LENGTH]) {
  struct Warrior w = { .health = 10, .attack = 5, .defence = 5 };
  strncpy(w.name, name, sizeof(w.name) - 1);

  return w;
}

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

int main() {
  printf("Welcome to the start of your adventure\n");

  char playerName[NAME_LENGTH];
  printf("\n--------------------\n");
  printf("  Enter your name\n");
  printf("--------------------\n");
  
  scanf("%20s", playerName);

  Warrior player = createWarrior(playerName);
  Warrior enemy = createRandomWarrior();

  printf("You are %s, an intrepid warrior\n", player.name);
  printf("Your enemey is %s\n", enemy.name);
}
