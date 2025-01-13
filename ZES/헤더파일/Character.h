#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Item.h"

using namespace std;

class Character
{
private:
	static Character* instance;

public:
	string name;
	int level;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<Item*> inventory;

	Character(string name);
	
	static Character* getInstance(string name = "");
	void displayStats();
	void levelUp();
	void useItem(int index);
};



#endif
