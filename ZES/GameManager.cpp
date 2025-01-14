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
    int level = rand() % 30 + 1; // 1~30 사이의 레벨 랜덤 생성

    // 일반 몬스터 생성
    cout << "A 'monster' of level " << level << " is generated." << endl;
    if (level <= 5) {
        return new watt1500K();
    }
    else if (level <= 10) {
        return new watt3000K();
    }
    else if (level <= 15) {
        return new watt4000K();
    }
    else if (level <= 20) {
        return new watt5000K();
    }
    else if (level <= 25) {
        return new watt8000K();
    }
    else if (level <= 30) {
        return new watt10000K(); // 최고 레벨의 일반 몬스터
    }
    else {
        cout << "Error: Monster level exceeds the valid range." << endl;
        return nullptr; // 레벨이 30을 초과 했을 때 예외 처리
    }
}

// 보스 몬스터 생성 (최종 보스만 생성)
BossMonster* GameManager::generateBossMonster() {
    cout << "The ultimate boss appears! The Rainbow Watt is here!" << endl;
    return new watt15000K(); // 최종 보스 생성
}

// 배틀 로직
void GameManager::battle(Character* player) {
    Monster* monster = generateMonster();

    cout << "Monster " << monster->getName() << " has appeared! Battle begins!" << endl;
    bool isAlive = true;

    while (isAlive)
    {
        monster->displayInfo();
        cout << endl;

        player->useItem();
        monster->takeDamage(player->attack);
        cout << "You dealt " << player->attack << " damage to the monster " << monster->getName() << "." << endl;
        monster->displayInfo();

        if (monster->getHealth() <= 0)
        {
            cout << "You have defeated the monster " << monster->getName() << "!" << endl;
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
        }

        player->useItem();
        monster->attackPlayer(*player);
        cout << "Player " << player->getName() << " took " << monster->getAttack() << " damage." << endl;
        cout << "Player " << player->getName() << "'s health: " << player->getHealth() << ", Attack: " << player->attack << endl;

        if (player->getHealth() <= 0)
        {
            cout << "Player " << player->getName() << " has died!" << endl;
            isAlive = false;
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
