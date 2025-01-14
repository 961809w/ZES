#include "Item.h"

using namespace std;

  HealthPotion::HealthPotion()
      : name("HP potion"),
        healthRestore(50)
  {}
  
  string HealthPotion::getName() const
  {
      return name;
  }

  void HealthPotion::use(Character* character)
  {
      character->currentHealth +=healthRestore;
	  cout << "Current Health has been restored by " << healthRestore << endl;
	  if (character->currentHealth > character->maxHealth)
	  {
		  character->currentHealth = character->maxHealth;
	  }
  }

  AttackBoost::AttackBoost()
	  : name("AD potion"),
		attackIncrease(10)
  {}

  string AttackBoost::getName() const
  {
      return name;
  }

  void AttackBoost::use(Character* character)
  {
	  character->attack += attackIncrease;
	  cout << "The attack power has been increased by " << attackIncrease << endl;
  }