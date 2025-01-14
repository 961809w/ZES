#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
class Character;

//Monster class 구현
Monster::Monster() : name(""), health(0), attack(0), experience(0) { }

Monster::Monster(const string& name, int health, int attack, int experience) : name(name), health(health), attack(attack), experience(experience) {}

Monster::~Monster() {}

string Monster::getName() const {return name;}

int Monster::getHealth() const {return health;}

int Monster::getAttack() const {return attack;}

int Monster::getExperience() const {return experience;}

void Monster::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void Monster::attackPlayer(Character& player) {
	player.currentHealth -= attack;
}

void Monster::displayInfo() const {
	cout << "Monster: " << name << ", HP: " << health << ", AD: " << attack << endl;
}

void Monster::dropitem(Character& character) {

    int chance = rand() % 100;
    Item* Drop = nullptr;

    if (chance < 30) {
        cout << "You got an HP potion" << endl;
        Drop = new HealthPotion();
    } else if (chance < 60) {
        cout << "You got an AD potion" << endl;
        Drop = new AttackBoost();
    }

    if (Drop) {
        character.inventory.push_back(Drop);
    }
}



redwatt::redwatt() : Monster("Red Watt", 20, 5, 10) { }

redwattplus::redwattplus() : Monster("Red Watt+", 30, 6, 15) { }

yellowwatt::yellowwatt() : Monster("Yellow Watt", 50, 9, 20) { }

yellowwattplus::yellowwattplus() : Monster("Yellow Watt+", 55, 10, 25) { }

greenwatt::greenwatt() : Monster("Green Watt", 60, 12, 30) { }

greenwattplus::greenwattplus() : Monster("Green Watt+", 65, 14, 35) { }

bluewatt::bluewatt() : Monster("Blue Watt", 80, 18, 40) { }

bluewattplus::bluewattplus() : Monster("Blue Watt+", 100, 25, 45) { }

rainbowwatt::rainbowwatt() : Monster("Rainbow Watt", 300, 50, 150) { }