#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item 
{
public:
 virtual string getName() const = 0;
 virtual void use(class Character* character) = 0;
 virtual ~Item() = default;
};

// 체력 회복 아이템
class HealthPotion : public Item 
{
private:
    string name;
    int healthRestore;

public:
    HealthPotion();
    string getName() const override;
    void use(Character* character) override;
    };

// 공격력 증가 아이템
class AttackBoost : public Item 
{
private:
    string name;
    int attackIncrease;

public:
    AttackBoost();
    string getName() const override;
    void use(Character* character) override;
};



#endif
