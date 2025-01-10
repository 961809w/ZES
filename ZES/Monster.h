#pragma once
#ifndef Monster_H_
#define Monster_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//moster class
class monster {
protected:
	string name;
	int health;
	int attack;

public:
	monster(const string& name, int health, int attack);
	virtual ~monster();

	string getName() const;
	int getHealth() const;
	int getAttack() const;

	virtual void takeDamege(int damage);
	virtual void attackPlayer(Player& Player);
	virtual void displayInfo() const;
};


//watt 1500K class
class watt1500K : public monster {
public:
	watt1500K();
};


//watt 3000K class
class watt3000K : public monster {
public:
	watt3000K();
};


//watt 4000K class
class watt4000K : public monster {
public:
	watt4000K();
};

//watt 4500K class
class watt4500K : public monster {
public:
	watt4500K();
};

//watt 5000K class
class watt5000K : public monster {
public:
	watt5000K();
};

//watt 6000K class
class watt6000K : public monster {
public:
	watt6000K();
};

//watt 8000K class
class watt8000K : public monster {
public:
	watt8000K();
};

//watt 10000K class
class watt10000K : public monster {
public:
	watt10000K();
};

//watt 15000K class
class watt15000K : public monster {
public:
	watt15000K();
};

#endif