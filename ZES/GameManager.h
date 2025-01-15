#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>

class GameManager {
public:
    // 몬스터 생성
    Monster* generateMonster();

    // 배틀 로직
    void battle(Character* player);

    // 플레이어의 인벤토리(아이템 리스트) 표시
    void displayInventory(const vector<Item*>& inventory);


    // 게임 초기화
    void initializeGame();

    // 게임 종료
    void endGame();

    // 플레이어 상태 표시
    //void displayPlayerStatus(Character* player);

    void displayStatus(const string& name, int hp, int attackValue);

};

#endif