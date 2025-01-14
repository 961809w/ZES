#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "Shop.h"

class GameManager {
public:
    // 몬스터 생성
    Monster* generateMonster();
    // 보스 몬스터 생성
    BossMonster* generateBossMonster();
    // 배틀 로직
    void battle(Character* player);
    // 인벤토리 출력
    void displayInventory(const std::vector<Item*>& inventory);
    // 상점 방문
    void visitShop(Character* player);
};

#endif // GAMEMANAGER_H
