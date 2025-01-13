#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Character::Character(string name)
	: name(name),
	level(1),
	maxHealth(100),
	attack(10),
	experience(0),
	gold(0){ }


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
	cout << "      Name : " << name << endl;
	cout << "     Level : " << level << endl;
	cout << "    Health : " << maxHealth << endl;
	cout << "    Attack : " << attack << endl;
	cout << "Experience : " << experience << endl;
	cout << "      gold : " << gold << endl;
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
		attack = attack + level * 5;
		experience -= 100;

		cout << "레벨 업!! " << level - 1 << " -> " << level << endl;
		cout << endl;
	}
}

void Character::useItem(int index)
{
	if (inventory.size() == 0)
	{
		return;
	}
	Item* item = inventory[index];

	item->use(this);
	cout << "아이템 사용!" << endl;
	cout << endl;
	delete item;
	inventory.erase(inventory.begin() + index);
}
