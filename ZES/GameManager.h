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
    // ���� ���� ����
    Monster* generateMonster();
    BossMonster* generateBossMonster();

    // ��Ʋ ����
    void battle(Character* player);

    // �κ��丮 ���
    void displayInventory(const std::vector<Item*>& inventory);

    // ���� �湮
    void visitShop(Character* player);

    // ���� �ʱ�ȭ �� ����
    void initializeGame();
    void endGame();

    // ���� ���
    void displayStatus(const std::string& name, int hp, int attackValue);
};

#endif // GAMEMANAGER_H
