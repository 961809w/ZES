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
    cout << level << " 레벨의 몬스터를 생성합니다." << endl;

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
        return new watt10000K();
    }
    else {
        cout << "보스 몬스터 등장!" << endl;
        return new watt15000K();
    }
}


//배틀 로직
void GameManager::battle(Character* player) {

}


void GameManager::displayInventory(const vector<Item*>& inventory) {
    // 인벤토리(아이템 리스트) 출력 로직
    cout << "인벤토리 :" << endl;
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // 아이템 이름 출력
    }
}


/*void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 몬스터와 상호작용 로직
    cout << "플레이어 " << player->getName()
        << " 와 몬스터 " << monster->getName() << " 전투 중" << endl;
}*/

/*void GameManager::initializeGame() {
    // 게임 초기화 로직
    cout << "게임 초기화..." << endl;
}

void GameManager::endGame() {
    // 게임 종료 로직
    cout << "게임 종료..." << endl;
}*/