#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item. h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // 몬스터 생성 로직
    cout << "레벨 " << level << " 몬스터 생성 중" << endl;
    return new Monster(); // 몬스터 객체 생성 후 반환
}

void GameManager::battle(Character* player) {
    // 배틀 로직
    cout << "플레이어와 전투 시작 : " << player->getName() << endl;
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 몬스터와 상호작용 로직 
    cout << "플레이어 " << player->getName()
        << " 와 몬스터 " << monster->getName() << " 전투 중" << endl;
}

// + 아래 추가적인 요소들
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // 인벤토리(아이템 리스트) 출력 로직
    cout << "인벤토리 :" << endl;
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // 아이템 이름 출력
    }
}

/*void GameManager::initializeGame() {
    // 게임 초기화 로직
    cout << "게임 초기화..." << endl;
}

void GameManager::endGame() {
    // 게임 종료 로직
    cout << "게임 종료..." << endl;
}*/

