#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// 몬스터 생성 로직
// level에 따라 다른 몬스터 생성
Monster* GameManager::generateMonster() {
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 시드 설정 (몬스터 랜덤 생성을 위해)
    int level = rand() % 30 + 1; // 1~30 사이의 레벨 랜덤 생성
    cout << "Create a level "<< level << " monster." << endl;

    if (level <= 5) {
        return new redwatt();
    }
    else if (level <= 10) {
        return new redwattplus();
    }
    else if (level <= 15) {
        return new yellowwatt();
    }
    else if (level <= 20) {
        return new greenwatt();
    }
    else if (level <= 25) {
        return new bluewatt();
    }
    else if (level <= 30) {
        return new bluewattplus();
    }
    else {
        cout << "Boss Monster is here!" << endl;
        return new rainbowwatt();
    }
}


//배틀 로직
void GameManager::battle(Character* player){

    Monster* monster = generateMonster();
    cout << "Monster " << monster->getName() << " is here! Battle begins!" << endl;
    bool isAlive = true;
    while (isAlive)
    {
        monster->displayInfo();
        cout << endl;

        player->useItem();
        monster->takeDamage(player->attack);
        cout << "You gave " << monster->getName() << " " << player->attack << " damage." << endl;
        monster->displayInfo();
        if (monster->getHealth() <= 0)
        {
            cout << "You've killed " << monster->getName() << "!!" << endl;
            cout << endl;
            monster->dropitem(*player);
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
        }
        player->useItem();
        monster->attackPlayer(*player);
        cout << "Player " << player->getName() << "'s current HP: " << player->getHealth() << ", AD: " << player->attack << endl;
        if (player->getHealth() <= 0)
        {
            cout << "Player " << player->getName() << " is dead" << endl;
            isAlive = false;
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
