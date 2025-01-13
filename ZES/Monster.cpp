#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Monster class 구현
Monster::Monster(const string& name, int health, int attack) : name(name), health(health), attack(attack) {}

Monster::~Monster() {}

string Monster::getName() const {
	return name;
}

int Monster::getHealth() const {
	return health;
}

int Monster::getAttack() const {
	return attack;
}

void Monster::takeDamege(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void Monster::attackPlayer(Character& Character) {
	Character.takeDamage(attack);

	cout << name << "attacks" << Character.getName() << "for" << attack << "damage!" << endl;
}

void Monster::displayInfo() const {
	cout << "Monster: " << name << "Hralth: " << health << "Attack: " << attack << endl;
}

//아이템 드랍 설정
unique_ptr<Item> Monster::dropitem() {
	srand(static_cast<unsigned int>(time(nullptr)));
	
	int EXP = (rand() % 100) + 10;
	cout << "처지 보상" << EXP << "경험치" << endl;

	Character.gainExperience(EXP);

	int MoneyAmount = (rand() % 100) + 1;
	cout << "처지 보상" << MoneyAmount << "골드" << endl;

	int chance = rand() % 100; 
	
	if (chance < 30){
		cout << "포션을 하나를 손에 넣었다!" << endl;
		return make_unique<Potion>();
	}

return make_unique<Money>(MoneyAmount);
}



//watt 1500K class
watt1500K::watt1500K() : Monster("watt 1500K", 10, 5) {
}

//watt 3000K class
watt3000K::watt3000K() : Monster("watt 3000K", 30, 6) {
}

//watt 4000K class
watt4000K::watt4000K() : Monster("watt 4000K", 50, 9) {
}

//watt 4500K class
watt4500K::watt4500K() : Monster("watt 4500K", 55, 10) {
}

//watt 5000K class
watt5000K::watt5000K() : Monster("watt 5000K", 60, 12) {
}

//watt 6000K class
watt6000K::watt6000K() : Monster("watt 4500K", 65, 14) {
}

//watt 8000K class
watt8000K::watt8000K() : Monster("watt 8000K", 80, 18) {
}

//watt 10000K class
watt10000K::watt10000K() : Monster("watt 10000K", 100, 25) {
}

//watt 15000K class
watt15000K::watt15000K() : Monster("watt 15000K", 300, 50) {
}

