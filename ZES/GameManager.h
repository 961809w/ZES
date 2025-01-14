#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "Shop.h"

class GameManager {
public:
    // ���� ����
    Monster* generateMonster();
    // ���� ���� ����
    BossMonster* generateBossMonster();
    // ��Ʋ ����
    void battle(Character* player);
    // �κ��丮 ���
    void displayInventory(const std::vector<Item*>& inventory);
    // ���� �湮
    void visitShop(Character* player);
};

#endif // GAMEMANAGER_H
