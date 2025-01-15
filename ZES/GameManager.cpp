#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "Shop.h"
#include <vector>
#include <iostream>
#include <cstdlib> // 난수 생성을 위한 헤더 파일 - rand() 함수, srand() 함수 제공
#include <ctime> // 난수 생성을 위한 헤더 파일 - time() 함수 제공
using namespace std;

// 몬스터 생성 로직
Monster* GameManager::generateMonster() {
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 시드 설정 (몬스터 랜덤 생성을 위해)
    int level = rand() % 16 + 1; // 1~16 사이의 레벨 랜덤 생성

    // 일반 몬스터 생성
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
    else if (level <= 16) {
        return new bluewattplus(); // 일반 레벨의 최고 몬스터
    }
     else { 
        cout << "Boss Monster is here!" << endl;
        return generateBossMonster(); // 레벨이 16을 초과한 경우 보스 몬스터 생성
    }
}

// 보스 몬스터 생성 (최종 보스만 생성)
BossMonster* GameManager::generateBossMonster() {
    cout << "The ultimate boss appears! The Rainbow Watt is here!" << endl;
    return new rainbowwatt(); // 최종 보스 생성
}

//배틀 로직
void GameManager::battle(Character* player) {
    cout << endl << endl;
    cout << "========================Befor The Battle========================" << endl;
    Monster* monster = generateMonster();

    displayStatus(player->getName(), player->getHealth(), player->attack);
    displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

    cout << "\nMonster " << monster->getName() << " is here! Battle begins!" << endl;

    bool isAlive = true;
    while (isAlive)
    {
        cout << endl << endl;

        monster->takeDamage(player->attack);
        cout << "==========================My Turn!==========================" << endl;
        displayStatus(player->getName(), player->getHealth(), player->attack);
        cout << "vvvvvvvvvvvvATTACKvvvvvvvvvvvv" << endl;
        displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

        player->useItem();

        if (monster->getHealth() <= 0)
        {
            cout << "You've killed " << monster->getName() << "!!" << endl;
            cout << endl;
            monster->dropitem(*player);
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
            break;
        }

        monster->attackPlayer(*player);
        cout << "=======================Monster's Turn!======================" << endl;
        displayStatus(player->getName(), player->getHealth(), player->attack);
        cout << "^^^^^^^^^^^^ATTACK^^^^^^^^^^^^" << endl;
        displayStatus(monster->getName(), monster->getHealth(), monster->getAttack());

        player->useItem();

        if (player->getHealth() <= 0)
        {
            cout << "Player " << player->getName() << " is dead" << endl;
            isAlive = false;
            break;
        }

    }
	delete monster; // 몬스터 객체 메모리 해제
}


// 인벤토리(아이템 리스트) 출력 로직
void GameManager::displayInventory(const vector<Item*>& inventory) {
    cout << "Inventory:" << endl;
    for (const auto& Item : inventory) {
        cout << " - " << Item->getName() << endl; // 아이템 이름 출력
    }
}

// 상점 방문 로직 (구매 -> 판매 -> 현재상태출력)
void GameManager::visitShop(Character* player) {

    cout << player->getName() << " has visited the shop." << endl;

    Shop shop;
    shop.displayItems();

    int choice;

    // 아이템 구매
    cout << "Enter the number of the item you want to buy. (Enter -1 to cancel): ";
    cin >> choice;
    if (choice != -1 && choice >= 0 && choice < shop.items.size()) {
        shop.buyItem(choice, player);
    }
    else if (choice != -1) {
        cout << "Invalid item number." << endl;
    }

    // 아이템 판매
    cout << "Enter the number of the item you want to sell. (Enter -1 to cancel): ";
    cin >> choice;
    if (choice != -1 && choice >= 0 && choice < player->inventory.size()) {
        shop.sellItem(choice, player);
    }
    else if (choice != -1) {
        cout << "Invalid item number." << endl;
    }

    // 상점 방문 후 현재 골드 및 인벤토리 상태 출력
    cout << "Current gold: " << player->gold << endl;
    displayInventory(player->inventory);  // 기존에 작성한 displayInventory 함수 재사용
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