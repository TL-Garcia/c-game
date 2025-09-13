#define NAME_LENGTH 21

typedef struct Warrior {
  char name[21];
  int health;
  int defence;
  int attack;
} Warrior;

Warrior createWarrior(char name[NAME_LENGTH]);
