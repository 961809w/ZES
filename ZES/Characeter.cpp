#include "Character.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

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
	cout << ": " <<  << endl;
	cout << ": " <<  << endl;
	cout << ": " <<  << endl;
	cout << "Level: " << level << " Health: " << maxHealth << " Attack: " << attack << " Experience: " << experience << " Gold: " << gold << endl;
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