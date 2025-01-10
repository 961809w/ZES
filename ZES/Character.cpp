

#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Character::Character(string nameInput)
{
	name = nameInput;
	level = 1;
	maxHealth = 100;
	attack = 10;
	experience = 0;
	gold = 0;
}

void Character::displayStats()
{
	cout << "=====================" << endl;
	cout << "=====================" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << maxHealth << endl;
	cout << "Attack: " << attack << endl;
	cout << "Experience: " << experience << endl;
	cout << "gold: " << gold << endl;
	cout << "=====================" << endl;
	cout << "=====================" << endl;
}

void Character::levelUp()
{
	if (experience >= 100)
	{
		level++;
		maxHealth = maxHealth + level * 20;
		attack = attack + level * 5;
		experience = 0;
	}
}

void Character::useItem(int index)
{
	srand(time(nullptr));
	int randIndex = rand() % inventory.size();

}