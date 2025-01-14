#pragma once
#ifndef Monster_H_
#define Monster_H_

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
	Monster(const string& name, int health, int attack, int experience);
	virtual ~Monster();

	string getName() const;
	int getHealth() const;
	int getAttack() const;
	int getExperience() const;

	void takeDamage(int damage);
	void attackPlayer(Character& character);
	void grantexperienceToPlayer(Character& character);
	Item* dropitem();

	virtual void displayInfo() const;
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
