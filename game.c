#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 21

typedef struct Warrior {
  char name[NAME_LENGTH];
  int health;
  int attack;
} Warrior;

Warrior createWarrior(char name[NAME_LENGTH]) {
  struct Warrior w = { .health = 10, .attack = 5 };
  strncpy(w.name, name, sizeof(w.name) - 1);

  return w;
}

int main() {
  printf("Welcome to the start of your adventure\n");

  char playerName[NAME_LENGTH];
  printf("\n--------------------\n");
  printf("  Enter your name\n");
  printf("--------------------\n");
  
  scanf("%20s", playerName);

  Warrior player = createWarrior(playerName);

  printf("You are %s, an intrepid warrior\n", player.name);
}
