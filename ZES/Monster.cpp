#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Monster class 구현
Monster::Monster(const string& name, int health, int attack, int experience) : name(name), health(health), attack(attack), experience(experience) {}

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

int Monster::getExperience() const {
	return experience;
}

void Monster::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void Monster::attackPlayer(Character& character) {
	character.takeDamage(attack);

	cout << name << "가" << character.getName() << "공격했습니다." << attack << "데미지" << endl;
}

void Monster::displayInfo() const {
	cout << "몬스터 " << name << "체력 " << health << "공격 " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << " 쓰러트렸다 " << character.getName() << " 얻었습니다. " << experience << " 경험치" << endl;
	character.gainExperience(experience);
}

//아이템 드랍 설정
unique_ptr<Item> Monster::dropitem() {
	srand(static_cast<unsigned int>(time(nullptr)));
	
	int experience = (rand() % 100) + 10;
	cout << "처지 보상" << experience << "경험치" << endl;

	Character.gainExperience(EXP);

	int gold = (rand() % 100) + 1;
	cout << "처지 보상" << gold << "골드" << endl;

	int chance = rand() % 100; 
	
	if (chance < 30){
		cout << "포션을 하나를 손에 넣었다!" << endl;
		return make_unique<HealthPotion>();
	}

return make_unique<gold>(gold);
}



//watt 1500K class
watt1500K::watt1500K() : Monster("와트레드", 10, 5, 10) {
}

//watt 3000K class
watt3000K::watt3000K() : Monster("와트레드+", 30, 6, 15) {
}

//watt 4000K class
watt4000K::watt4000K() : Monster("와트엘로우", 50, 9, 20) {
}

//watt 4500K class
watt4500K::watt4500K() : Monster("와트엘로우+", 55, 10, 25) {
}

//watt 5000K class
watt5000K::watt5000K() : Monster("와트그린", 60, 12, 30) {
}

//watt 6000K class
watt6000K::watt6000K() : Monster("와트그린+", 65, 14, 35) {
}

//watt 8000K class
watt8000K::watt8000K() : Monster("와트블루", 80, 18, 40) {
}

//watt 10000K class
watt10000K::watt10000K() : Monster("와트블루+", 100, 25, 45) {
}

//watt 15000K class
watt15000K::watt15000K() : Monster("빅와트", 300, 50, 150) {
}

