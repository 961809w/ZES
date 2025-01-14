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
	character.maxHealth -= attack;

	cout << name << "가" << character.name << "를 공격했습니다." << attack << "데미지" << endl;
}

void Monster::displayInfo() const {
	cout << "몬스터 " << name << "체력 " << health << "공격 " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << "를 쓰러트렸다 " << character.name << "는 얻었습니다. " << experience << " 경험치 획득" << endl;
	character.gainExperience(experience);
}

//아이템 드랍 설정
void Monster::dropitem(Character& character) {

	int chance = rand() % 100;
	Item* Drop = nullptr;

	if (chance < 30) {
		cout << "포션을 하나를 손에 넣었다!" << endl;
		Drop = new HealthPotion();
	}
	if (chance < 30) {
		cout << "어택부스트를 손에 넣었다!" << endl;
		Drop = new AttackBoost();
	}
	if (Drop) {
		character.inventory.push_back(Drop);
	}

}


redwatt::redwatt() : Monster("레드와트", 10, 5, 10) { }

redwattplus::redwattplus() : Monster("레드와트+", 30, 6, 15) { }

yellowwatt::yellowwatt() : Monster("옐로우와트", 50, 9, 20) { }

yellowwattplus::yellowwattplus() : Monster("옐로우와트+", 55, 10, 25) { }

greenwatt::greenwatt() : Monster("그린와트", 60, 12, 30) { }

greenwattplus::greenwattplus() : Monster("그린와트+", 65, 14, 35) { }

bluewatt::bluewatt() : Monster("블루와트", 80, 18, 40) { }

bluewattplus::bluewattplus() : Monster("블루와트+", 100, 25, 45) { }

rainbowwatt::rainbowwatt() : Monster("레인보우와트", 300, 50, 150) { }
