#include "Monster.h"
#include <iostream>

using namespace std;

//Monster class ±¸Çö
monster::monster(const string& name, int health, int attack) : name(name), health(health), attack(attack) {}

monster::~monster() {}

string monster::getName() const {
	return name;
}

int monster::getHealth() const {
	return health;
}

int monster::getAttack() const {
	return attack;
}

void monster::takeDamege(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void monster::attackPlayer(Character& Character) {
	Character.takeDamage(attack);

	cout << name << "attacks" << Character.getName() << "for" << attack << "damage!" << endl;
}

void monster::displayInfo() const {
	cout << "Monster: " << name << "Hralth: " << health << "Attack: " << attack << endl;
}


//watt 1500K class
watt1500K::watt1500K() : monster("watt 1500K", 50, 10) {
}

//watt 3000K class
watt3000K::watt3000K() : monster("watt 3000K", 50, 10) {
}

//watt 4000K class
watt4000K::watt4000K() : monster("watt 4000K", 50, 10) {
}

//watt 4500K class
watt4500K::watt4500K() : monster("watt 4500K", 50, 10) {
}

//watt 5000K class
watt5000K::watt5000K() : monster("watt 5000K", 50, 10) {
}

//watt 6000K class
watt6000K::watt6000K() : monster("watt 4500K", 50, 10) {
}

//watt 8000K class
watt8000K::watt8000K() : monster("watt 8000K", 50, 10) {
}

//watt 10000K class
watt10000K::watt10000K() : monster("watt 10000K", 50, 10) {
}

//watt 15000K class
watt15000K::watt15000K() : monster("watt 15000K", 50, 10) {
}