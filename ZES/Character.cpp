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
	cout << "      �̸� : " << name << endl;
	cout << "      ���� : " << level << endl;
	cout << "      ü�� : " << maxHealth << endl;
	cout << "    ���ݷ� : " << attack << endl;
	cout << "    ����ġ : " << experience << endl;
	cout << "      ��� : " << gold << endl;
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

		cout << "���� ��!! " << level - 1 << " -> " << level << endl;
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
	int randindex = rand() % inventory.size();
	Item* Nth_Item = inventory[randindex];

	Nth_Item->use(this);
	cout << "������ ���!" << endl;
	cout << endl;
	delete Nth_Item;
	inventory.erase(inventory.begin() + randindex);
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
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
	return currentHealth;
}

void Character::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth < 0) currentHealth = 0;
}