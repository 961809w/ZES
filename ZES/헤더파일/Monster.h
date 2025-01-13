#pragma once
#ifndef Monster_H_
#define Monster_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "../헤더파일/Character.h"
#include "../헤더파일/Item.h"

using namespace std;


//moster class
class Monster {
protected:
	string name;
	int health;
	int attack;

public:
	Monster(const string& name, int health, int attack);
	virtual ~Monster();

	string getName() const;
	int getHealth() const;
	int getAttack() const;

	virtual void takeDamege(int damage);
	virtual void attackPlayer(Character& Character);
	virtual void displayInfo() const;
	unique_ptr<Item> dropitem();
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