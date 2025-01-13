#include "../헤더파일/GameManager.h"
#include "../헤더파일/Character.h"
#include "../헤더파일/Monster.h"
#include "../헤더파일/Item.h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // 몬스터 생성 로직
    cout << "Generating a monster of level " << level << endl;
    return new Monster(); // 몬스터 객체 생성 필요
}

void GameManager::battle(Character* player) {
    // 배틀 로직
    cout << "Battle initiated with player: " << player->getName() << endl;
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 몬스터와 상호작용 로직 
    cout << "Handling interaction between player " << player->getName()
        << " and monster " << monster->getName() << endl;
}

// + 추가적인 요소들
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // 인벤토리(아이템 리스트) 출력 로직
    cout << "Displaying inventory:" << endl;
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // 아이템 이름 출력
    }
}

void GameManager::initializeGame() {
    // 게임 초기화 로직
    cout << "Initializing the game..." << endl;
}

void GameManager::endGame() {
    // 게임 종료 로직
    cout << "Ending the game..." << endl;
}

void GameManager::displayPlayerStatus(Character* player) {
    // 플레이어 상태 표시 로직
    cout << "Player Status: " << endl;
    cout << "Name: " << player->getName() << endl;
    cout << "Level: " << player->level << endl;
    cout << "Health: " << player->health << "/" << player->maxHealth << endl;
    cout << "Experience: " << player->experience << endl;
    cout << "Gold: " << player->gold << endl;
}
