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


//watt 1500K class
class watt1500K : public Monster {
public:
	watt1500K();
};


//watt 3000K class
class watt3000K : public Monster {
public:
	watt3000K();
};


//watt 4000K class
class watt4000K : public Monster {
public:
	watt4000K();
};

//watt 4500K class
class watt4500K : public Monster {
public:
	watt4500K();
};

//watt 5000K class
class watt5000K : public Monster {
public:
	watt5000K();
};

//watt 6000K class
class watt6000K : public Monster {
public:
	watt6000K();
};

//watt 8000K class
class watt8000K : public Monster {
public:
	watt8000K();
};

//watt 10000K class
class watt10000K : public Monster {
public:
	watt10000K();
};

//watt 15000K class
class watt15000K : public Monster {
public:
	watt15000K();
};



#endif