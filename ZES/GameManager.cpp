#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item. h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // ���� ���� ����
    cout << "���� " << level << " ���� ���� ��" << endl;
    return new Monster(); // ���� ��ü ���� �� ��ȯ
}

void GameManager::battle(Character* player) {
    // ��Ʋ ����
    cout << "�÷��̾�� ���� ���� : " << player->getName() << endl;
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // ���Ϳ� ��ȣ�ۿ� ���� 
    cout << "�÷��̾� " << player->getName()
        << " �� ���� " << monster->getName() << " ���� ��" << endl;
}

// + �Ʒ� �߰����� ��ҵ�
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // �κ��丮(������ ����Ʈ) ��� ����
    cout << "�κ��丮 :" << endl;
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // ������ �̸� ���
    }
}

void GameManager::initializeGame() {
    // ���� �ʱ�ȭ ����
    cout << "���� �ʱ�ȭ..." << endl;
}

void GameManager::endGame() {
    // ���� ���� ����
    cout << "���� ����..." << endl;
}

void GameManager::displayPlayerStatus(Character* player) {
    // �÷��̾� ���� ǥ�� ����
    cout << "�÷��̾� ���� : " << endl;
    cout << "�̸� : " << player->getName() << endl;
    cout << "���� : " << player->level << endl;
    cout << "ü�� : " << player->health << "/" << player->maxHealth << endl;
    cout << "����ġ : " << player->experience << endl;
    cout << "��� : " << player->gold << endl;
}
