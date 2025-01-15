#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include "shop.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// 몬스터 생성 로직
// level에 따라 다른 몬스터 생성
Monster* GameManager::generateMonster() {
	srand(static_cast<unsigned int>(time(nullptr))); // 난수 시드 설정 (몬스터 랜덤 생성을 위해)

	int level = rand() % 16 + 1; // 1~30 사이의 레벨 랜덤 생성
	cout << "Create a level " << level << " monster." << endl;

	if (level <= 2) {
		return new redwatt();
	}
	else if (level <= 4) {
		return new redwattplus();
	}
	else if (level <= 6) {
		return new yellowwatt();
	}
	else if (level <= 8) {
		return new yellowwattplus();
	}
	else if (level <= 10) {
		return new greenwatt();
	}
	else if (level <= 12) {
		return new greenwattplus();
	}
	else if (level <= 14) {
		return new bluewatt();
	}
	else {
		return new bluewattplus();
	}

}


//배틀 로직
void GameManager::battle(Character* player) {
	ClearConsole();

	cout << "=======================Before The Battle=======================" << endl;
	Monster* monster = generateMonster();

	displayStatus(player->getName(), player->getHealth(), player->attack);
	displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

	cout << "\nMonster " << monster->getName() << " is here! Battle begins!" << endl;

	bool isAlive = true;
	while (isAlive)
	{
		buffer();
		ClearConsole();

		monster->takeDamage(player->attack);
		cout << "==========================My Turn!==========================" << endl;
		displayStatus(player->getName(), player->getHealth(), player->attack);
		cout << "vvvvvvvvvvvvATTACKvvvvvvvvvvvv" << endl;
		displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

		player->useItem();

		if (monster->getHealth() <= 0)
		{
			buffer();
			ClearConsole();

			cout << "You've killed " << monster->getName() << "!!" << endl;
			cout << endl;
			monster->dropitem(*player);
			player->gainExperience(monster->getExperience());
			player->levelUp();
			int goldgain = rand() % 100 + 50;
			cout << "You got " << goldgain << " gold! " << player->gold << " -> " << player->gold + goldgain << endl;
			player->gold += goldgain;

			isAlive = false;
			break;
		}

		buffer();
		ClearConsole();

		monster->attackPlayer(*player);
		cout << "=======================Monster's Turn!======================" << endl;
		displayStatus(player->getName(), player->getHealth(), player->attack);
		cout << "^^^^^^^^^^^^ATTACK^^^^^^^^^^^^" << endl;
		displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

		player->useItem();

		if (player->getHealth() <= 0)
		{
			buffer();
			ClearConsole();

			cout << "Player " << player->getName() << " is dead" << endl;
			endGame();

			isGameOver = true;
			isAlive = false;
			break;
		}

	}
	delete monster;
}

void GameManager::displayInventory(const vector<Item*>& inventory) {
	// 인벤토리(아이템 리스트) 출력 로직
	if (inventory.empty()) {
		cout << "Inventory is empty." << endl;
		return;
	}
	else
	{
		cout << "Inventory List :" << endl;
		for (const auto& item : inventory) {
			cout << " - " << item->getName() << endl; // 아이템 이름 출력
		}
	}
}

void GameManager::initializeGame() {
	// 게임 초기화 로직
	cout << "Game Initializing..." << endl;
}

void GameManager::endGame() {
	// 게임 종료 로직
	cout << "The End..." << endl;
}

void GameManager::displayStatus(const string& name, int hp, int attackValue) {
	int hpBar = static_cast<int>(hp / 10);
	cout << "\n---------- " << name << " ----------" << endl;
	while (hpBar-- > 0) {
		cout << "O";
	}
	cout << "\nHP: " << hp << ", AD: " << attackValue << endl;
	cout << "-------------------------------" << endl << endl;
}

void GameManager::generateBoss(Character* player) {
	// 캐릭터 레벨 10 이상이면 보스 몬스터 생성
	if (player->getLevel() >= 10) {
		Monster* boss = new rainbowwatt();
		cout << "A boss monster has appeared: " << boss->getName() << "!" << endl;

		// 보스 몬스터와 전투 시작
		bossBattle(player, boss);
	}
}

void GameManager::bossBattle(Character* player, Monster* boss) {

	cout << " Boss Appears! " << boss->getName() << "!" << endl;

	displayStatus(boss->getName(), boss->getHealth(), boss->getAttack());

	buffer();
	ClearConsole();


	bool isAlive = true;
	while (isAlive) {

		boss->takeDamage(player->getAttack());
		cout << "==========================My Turn!==========================" << endl;
		displayStatus(player->getName(), player->getHealth(), player->getAttack());
		cout << "vvvvvvvvvvvvATTACKvvvvvvvvvvvv" << endl;
		displayStatus(boss->getName(), boss->getHealth(), boss->getAttack());

		buffer();
		ClearConsole();

		player->useItem();

		buffer();
		ClearConsole();


		if (boss->getHealth() <= 0) {
			cout << "You've killed the boss: " << boss->getName() << "!!" << endl;
			cout << "Congratulations! You've cleared the game!" << endl;
			cout << "The game will be ended." << endl;

			buffer();
			ClearConsole();


			isAlive = false;
			isGameOver = true; // 게임 종료 상태 설정
			break;
		}
		boss->attackPlayer(*player);
		cout << "=======================Boss's Turn!======================" << endl;
		displayStatus(player->getName(), player->getHealth(), player->getAttack());
		cout << "^^^^^^^^^^^^ATTACK^^^^^^^^^^^^" << endl;
		displayStatus(boss->getName(), boss->getHealth(), boss->getAttack());

		buffer();
		ClearConsole();

		player->useItem();

		buffer();
		ClearConsole();


		if (player->getHealth() <= 0) {
			cout << "Player " << player->getName() << " is dead" << endl;

			buffer();
			ClearConsole();

			isGameOver = true;
			isAlive = false;
			break;
		}
	}
	delete boss;
}

void GameManager::shop(Character* player) {
	// 상점 호출 로직
	Shop shop;
	shop.enter(*player);
}

void GameManager::buffer() {
	//출력 분할 로직
	cin.ignore();
	cin.get();
}

void GameManager::ClearConsole() {
	//콘솔창 싸악 정리
	system("cls");
}


