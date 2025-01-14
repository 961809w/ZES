#include "Item.h"

using namespace std;

  HealthPotion() : name("체력 회복 포션"), healthRestore(healthRestore){}
  string HealthPotionm::getName() const
  {

    return name;
  }

  void HealthPotion::use(Character* character)
  {

    character->currentHealth +=50;
  }

  AttackBoost() : name("공격력 증가 아이템"), attackIncrease(attackIncrease){}
  string AttackBoost ::getName() const
  {

    return name;
  }

  void AttackBoost :: use(Character*character)
  {
    character->attack +=10
  }