#pragma once
#ifndef MONSTER_H_
#define MONSTER_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "Character.h"
#include "Item.h"

using namespace std;

//moster class
class Monster {
protected:
    string name;
    int health;
    int attack;
    int experience;

public:
    Monster();
    Monster(const string& name, int health, int attack, int experience);
    virtual ~Monster();

    string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getExperience() const;

    virtual void takeDamage(int damage);
    virtual void attackPlayer(Character& Character);
    virtual void dropitem(Character& character);

    virtual void displayInfo() const;
    int test;
};

class redwatt : public Monster {
public:
    redwatt();
};

class redwattplus : public Monster {
public:
    redwattplus();
};

class yellowwatt : public Monster {
public:
    yellowwatt();
};

class yellowwattplus : public Monster {
public:
    yellowwattplus();
};

class greenwatt : public Monster {
public:
    greenwatt();
};

class greenwattplus : public Monster {
public:
    greenwattplus();
};

class bluewatt : public Monster {
public:
    bluewatt();
};

class bluewattplus : public Monster {
public:
    bluewattplus();
};

class rainbowwatt : public Monster {
public:
    rainbowwatt();
};

#endif
