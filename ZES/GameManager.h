#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Monster.h"
#include "item.h"
#include "shop.h"   
#include <vector>

class GameManager {
public:

    // 게임 종료 상태
    bool isGameOver = false;

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
    
    // 상점 호출 메서드
    void shop(Character* player);

    // 보스 생성
    void generateBoss(Character* player);

    // 보스 전투
    void bossBattle(Character* player, Monster* boss);


};


#endif