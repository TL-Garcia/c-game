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


void playerTurn() {

}

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

/* Returns true if the defender is still alive */
bool attack(Warrior *attacker, Warrior *defender) {
  int damage = (attacker->attack * 1.5) - defender->defence; // TODO: Improve dmg calculation
  defender->health -= damage;

  return defender->health > 0;
}

enum Action {
  Attack,
  Flee
};

enum Action getPlayerAction(Warrior *player) {
  printf("Choose your next step wisely\n");
  printf("%d: Attack\n", Attack);
  printf("%d: Flee\n", Flee);
  int action;
  scanf("%d", &action);

  return action;
}

// Returns false if actor loses the encounter
bool performAction(enum Action action, Warrior *actor, Warrior *target) {
  switch(action) {
    case Attack:
      attack(actor, target);
      printf("%s attacks %s. %s has %d health left\n", actor->name, target->name, target->name, target->health);
      return true;
    case Flee:
      printf("%s flees like a coward. Better to live another day\n", actor->name);
      return false;
    default:
      // TODO: Throw error
      printf("Invalid choice\n");
      return false;
  }
}

int main() {
  printf("Welcome to the start of your adventure\n");

  char playerName[NAME_LENGTH];
  printf("\n--------------------\n");
  printf("  Enter your name\n");
  printf("--------------------\n");
  
  scanf("%20s", playerName);

  // Create Player
  Warrior player = createWarrior(playerName);
  printf("You are %s, an intrepid warrior\n", player.name);

  // Enemy spawns - TODO: Trigger based on gameplay event
  Warrior enemy = createRandomWarrior();
  printf("Your enemy is %s\n", enemy.name);

  // Combat loop
  bool isPlayerAlive = true, isEnemyAlive = true;
  
  while(isPlayerAlive && isEnemyAlive) {
    if(isPlayerAlive) {
      // Player Turn
      enum Action playerAction = getPlayerAction(&player);
      isPlayerAlive = performAction(playerAction, &player, &enemy);
      isEnemyAlive = enemy.health > 0;
    } 

    if (isEnemyAlive) {
      // Enemy turn
      // TODO: Implement enemy choosing action
      isEnemyAlive = performAction(Attack, &enemy, &player);
      isPlayerAlive = player.health > 0;
    }
  }

  printf("Game over!\n");
  printf("%s health is %d\n", player.name, player.health);
  printf("%s health is %d\n", enemy.name, enemy.health);
}

