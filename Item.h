#include "Item.h"

using namespace std;

  HealthPotion(int healthRestore) : name("체력 회복 포션"), healthRestore(healthRestore){}
  string HealthPotionm::getName() const
  {

    return name;
  }

  void HealthPotion::use(Character* character)
  {

    character->heal(healthRestore);
  }

  AttackBoost(int attackIncrease) : name("공격력 증가 아이템"), attackIncrease(attackIncrease){}
  string AttackBoost ::getName() const
  {

    return name;
  }

  void AttackBoost :: use(Character*character)
  {
    character->increaseAttack(attackIncrease);
  }