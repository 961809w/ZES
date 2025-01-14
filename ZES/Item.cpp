#include "Item.h"

using namespace std;

  HealthPotion::HealthPotion()
      : name("체력 회복 포션"),
        healthRestore(50)
  {}
  
  string HealthPotion::getName() const
  {
      return name;
  }

  void HealthPotion::use(Character* character)
  {
      character->currentHealth +=healthRestore;
	  cout << "체력이 " << healthRestore << "만큼 회복되었습니다." << endl;
	  if (character->currentHealth > character->maxHealth)
	  {
		  character->currentHealth = character->maxHealth;
	  }
  }

  AttackBoost::AttackBoost() : name("공격력 증가 아이템"), attackIncrease(10)
  {}

  string AttackBoost::getName() const
  {
      return name;
  }

  void AttackBoost :: use(Character* character)
  {
	  character->attack += attackIncrease;
	  cout << "공격력이 " << attackIncrease << "만큼 증가했습니다." << endl;
  }