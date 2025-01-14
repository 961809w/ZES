#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>

class GameManager {
public:
    // ���� ����
    Monster* generateMonster(int level);

    // ���� ����
    void battle(Character* player);

    // ���Ϳ� �÷��̾� ��ȣ�ۿ�
    //void handleMonsterInteraction(Monster* monster, Character* player);

    // + �߰����� ��ҵ�

    // �÷��̾��� �κ��丮(������ ����Ʈ) ǥ��
    // ������ ������ ������ ��� �ٲ�Ƿ� �����迭 Vector ���
    // const�� �κ��丮 ����Ʈ�� ������ �������� ���ϵ��� ����
    void displayInventory(const vector<Item*>& inventory);


    // ���� �ʱ�ȭ
    //void initializeGame();

    // ���� ����
    void endGame();

    // �÷��̾� ���� ǥ��
    //void displayPlayerStatus(Character* player);


private:
    // �ʿ��� ��� �߰����� ��� ������ ����
};

#endif // GAMEMANAGER_H


