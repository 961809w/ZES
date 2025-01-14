#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Monster class ±¸Çö
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
<<<<<<< Updated upstream
	character.takeDamage(attack);

	cout << name << "°¡" << character.getName() << "°ø°ÝÇß½À´Ï´Ù." << attack << "µ¥¹ÌÁö" << endl;
}

void Monster::displayInfo() const {
	cout << "¸ó½ºÅÍ " << name << "Ã¼·Â " << health << "°ø°Ý " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << " ¾²·¯Æ®·È´Ù " << character.getName() << " ¾ò¾ú½À´Ï´Ù. " << experience << " °æÇèÄ¡" << endl;
=======
	character.currentHealth -= attack;
}

void Monster::displayInfo() const {
	cout << "ëª¬ìŠ¤í„°: " << name << ", ì²´ë ¥: " << health << ", ê³µê²©ë ¥: " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << "ë¥¼ ì“°ëŸ¬íŠ¸ë ¸ë‹¤! " << character.name << "ëŠ” ì–»ì—ˆìŠµë‹ˆë‹¤. " << experience << " ê²½í—˜ì¹˜ íšë“" << endl;
>>>>>>> Stashed changes
	character.gainExperience(experience);
}

//¾ÆÀÌÅÛ µå¶ø ¼³Á¤
unique_ptr<Item> Monster::dropitem() {
	srand(static_cast<unsigned int>(time(nullptr)));

	int experience = (rand() % 100) + 10;
	cout << "Ã³Áö º¸»ó" << experience << "°æÇèÄ¡" << endl;

	Character.gainExperience(EXP);

	int gold = (rand() % 100) + 1;
	cout << "Ã³Áö º¸»ó" << gold << "°ñµå" << endl;

	int chance = rand() % 100;

	if (chance < 30) {
		cout << "Æ÷¼ÇÀ» ÇÏ³ª¸¦ ¼Õ¿¡ ³Ö¾ú´Ù!" << endl;
		return make_unique<HealthPotion>();
	}
<<<<<<< Updated upstream
	if (chance < 30) && chance < 60){
		cout << name << "¾îÅÃºÎ½ºÆ®¸¦ ¼Õ¿¡ ³Ö¾ú´Ù!" << endl;
=======
	if (chance > 30 && chance < 60){
		cout << name << "ì–´íƒë¶€ìŠ¤íŠ¸ë¥¼ ì†ì— ë„£ì—ˆë‹¤!" << endl;
>>>>>>> Stashed changes
		return make_unique<AttackBoost>();
	}

return make_unique<gold>(gold);
}



//watt 1500K class
watt1500K::watt1500K() : Monster("¿ÍÆ®·¹µå", 10, 5, 10) {
}

//watt 3000K class
watt3000K::watt3000K() : Monster("¿ÍÆ®·¹µå+", 30, 6, 15) {
}

//watt 4000K class
watt4000K::watt4000K() : Monster("¿ÍÆ®¿¤·Î¿ì", 50, 9, 20) {
}

//watt 4500K class
watt4500K::watt4500K() : Monster("¿ÍÆ®¿¤·Î¿ì+", 55, 10, 25) {
}

//watt 5000K class
watt5000K::watt5000K() : Monster("¿ÍÆ®±×¸°", 60, 12, 30) {
}

//watt 6000K class
watt6000K::watt6000K() : Monster("¿ÍÆ®±×¸°+", 65, 14, 35) {
}

//watt 8000K class
watt8000K::watt8000K() : Monster("¿ÍÆ®ºí·ç", 80, 18, 40) {
}

//watt 10000K class
watt10000K::watt10000K() : Monster("¿ÍÆ®ºí·ç+", 100, 25, 45) {
}

//watt 15000K class
watt15000K::watt15000K() : Monster("·¹ÀÎº¸¿ì¿ÍÆ®", 300, 50, 150) {
}

