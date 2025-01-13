#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
protected:
    string name;

public:
    Item(const string& name) : name(name) {}
    
    
};

// 체력 회복 아이템
class HealthPotion : public Item {
private:
    int healthRestore;

public:
    HealthPotion(int healthRestore) : Item("체력 회복 포션"), healthRestore(healthRestore) {}

    
};

// 공격력 증가 아이템
class AttackBoost : public Item {
private:
    int attackIncrease;

public:
    AttackBoost(int attackIncrease) : Item("공격력 증가 아이템"), attackIncrease(attackIncrease) {}


};



#endif