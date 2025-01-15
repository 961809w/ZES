#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "BossMonster.h"
#include "Item.h"
#include "Shop.h"

class GameManager {
public:
    // 몬스터 생성 로직
    Monster* generateMonster();
    BossMonster* generateBossMonster();

    // 배틀 로직
    void battle(Character* player);

    // 인벤토리 출력
    void displayInventory(const std::vector<Item*>& inventory);

    // 상점 방문
    void visitShop(Character* player);

    // 게임 초기화 및 종료
    void initializeGame();
    void endGame();

    // 상태 출력
    void displayStatus(const std::string& name, int hp, int attackValue);
};

#endif // GAMEMANAGER_H
