#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string name)
	: name(name),
	level(1),
	maxHealth(300),
	currentHealth(300),
	attack(20),
	experience(0),
	gold(0){
}


Character* Character::getInstance(string name)
{
	if (!instance)
	{
		instance = new Character(name);
	}
	return instance;
}

void Character::displayStats()
{
	cout << endl;
	cout << "=========================" << endl;
	cout << "=========================" << endl;
	cout << "    Name : " << name << endl;
	cout << "   Level : " << level << endl;
	cout << "      HP : " << currentHealth << " / " << maxHealth << endl;
	cout << "      AD : " << attack << endl;
	cout << "     EXP : " << experience << endl;
	cout << "    Gold : " << gold << endl;
	cout << "=========================" << endl;
	cout << "=========================" << endl;
	cout << endl;
}

void Character::levelUp()
{
	if (experience >= 100)
	{
		level++;
		maxHealth = maxHealth + level * 20;
		currentHealth = maxHealth;
		attack = attack + level * 5;
		experience -= 100;

		cout << "Level Up!! " << level - 1 << " -> " << level << endl;
		cout << endl;
	}
}

void Character::useItem()
{
	if (inventory.size() == 0)
	{
		return;
	}
	srand(time(nullptr));
	int ItemUsePercentage = rand() % 100 + 1;
	int randindex = rand() % inventory.size();
	if (ItemUsePercentage < 20)
	{
		Item* Nth_Item = inventory[randindex];

		Nth_Item->use(this);
		cout << "Item Used!" << endl << endl;

		inventory.erase(inventory.begin() + randindex);

		delete Nth_Item;
	}
}

string Character::getName() const
{
	return name;
}

void Character::gainExperience(int experience)
{
	this->experience += experience;
	levelUp();
}

int Character::getHealth()
{
	return currentHealth;
}

void Character::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth < 0) currentHealth = 0;
}