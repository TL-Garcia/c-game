#include <stdbool.h>
#include <stdio.h>
#include "enemy.h"

/* Returns true if the defender is still alive */
bool attack(Warrior *attacker, Warrior *defender) {
  int damage = (attacker->attack * 1.5) -
               defender->defence; // TODO: Improve dmg calculation
  defender->health -= damage;

  return defender->health > 0;
}

enum Action { Attack, Flee };

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
  switch (action) {
  case Attack:
    attack(actor, target);
    printf("%s attacks %s. %s has %d health left\n", actor->name, target->name,
           target->name, target->health);
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

  while (isPlayerAlive && isEnemyAlive) {
    if (isPlayerAlive) {
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
