#include "Monster.h"
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Monster class ����
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

	cout << name << "��" << character.getName() << "�����߽��ϴ�." << attack << "������" << endl;
}

void Monster::displayInfo() const {
	cout << "���� " << name << "ü�� " << health << "���� " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << " ����Ʈ�ȴ� " << character.getName() << " ������ϴ�. " << experience << " ����ġ" << endl;
=======
	character.currentHealth -= attack;
}

void Monster::displayInfo() const {
	cout << "몬스터: " << name << ", 체력: " << health << ", 공격력: " << attack << endl;
}

void Monster::grantexperienceToPlayer(Character& character) {
	cout << name << "를 쓰러트렸다! " << character.name << "는 얻었습니다. " << experience << " 경험치 획득" << endl;
>>>>>>> Stashed changes
	character.gainExperience(experience);
}

//������ ��� ����
unique_ptr<Item> Monster::dropitem() {
	srand(static_cast<unsigned int>(time(nullptr)));

	int experience = (rand() % 100) + 10;
	cout << "ó�� ����" << experience << "����ġ" << endl;

	Character.gainExperience(EXP);

	int gold = (rand() % 100) + 1;
	cout << "ó�� ����" << gold << "���" << endl;

	int chance = rand() % 100;

	if (chance < 30) {
		cout << "������ �ϳ��� �տ� �־���!" << endl;
		return make_unique<HealthPotion>();
	}
<<<<<<< Updated upstream
	if (chance < 30) && chance < 60){
		cout << name << "���úν�Ʈ�� �տ� �־���!" << endl;
=======
	if (chance > 30 && chance < 60){
		cout << name << "어택부스트를 손에 넣었다!" << endl;
>>>>>>> Stashed changes
		return make_unique<AttackBoost>();
	}

return make_unique<gold>(gold);
}



//watt 1500K class
watt1500K::watt1500K() : Monster("��Ʈ����", 10, 5, 10) {
}

//watt 3000K class
watt3000K::watt3000K() : Monster("��Ʈ����+", 30, 6, 15) {
}

//watt 4000K class
watt4000K::watt4000K() : Monster("��Ʈ���ο�", 50, 9, 20) {
}

//watt 4500K class
watt4500K::watt4500K() : Monster("��Ʈ���ο�+", 55, 10, 25) {
}

//watt 5000K class
watt5000K::watt5000K() : Monster("��Ʈ�׸�", 60, 12, 30) {
}

//watt 6000K class
watt6000K::watt6000K() : Monster("��Ʈ�׸�+", 65, 14, 35) {
}

//watt 8000K class
watt8000K::watt8000K() : Monster("��Ʈ���", 80, 18, 40) {
}

//watt 10000K class
watt10000K::watt10000K() : Monster("��Ʈ���+", 100, 25, 45) {
}

//watt 15000K class
watt15000K::watt15000K() : Monster("���κ����Ʈ", 300, 50, 150) {
}

