#include "../�������/GameManager.h"
#include "../�������/Character.h"
#include "../�������/Monster.h"
#include "../�������/Item.h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // ���� ���� ����
    cout << "Generating a monster of level " << level << endl;
    return new Monster(); // ���� ��ü ���� �ʿ�
}

void GameManager::battle(Character* player) {
    // ��Ʋ ����
    cout << "Battle initiated with player: " << player->getName() << endl;
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // ���Ϳ� ��ȣ�ۿ� ���� 
    cout << "Handling interaction between player " << player->getName()
        << " and monster " << monster->getName() << endl;
}

// + �߰����� ��ҵ�
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // �κ��丮(������ ����Ʈ) ��� ����
    cout << "Displaying inventory:" << endl;
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // ������ �̸� ���
    }
}

void GameManager::initializeGame() {
    // ���� �ʱ�ȭ ����
    cout << "Initializing the game..." << endl;
}

void GameManager::endGame() {
    // ���� ���� ����
    cout << "Ending the game..." << endl;
}

void GameManager::displayPlayerStatus(Character* player) {
    // �÷��̾� ���� ǥ�� ����
    cout << "Player Status: " << endl;
    cout << "Name: " << player->getName() << endl;
    cout << "Level: " << player->level << endl;
    cout << "Health: " << player->health << "/" << player->maxHealth << endl;
    cout << "Experience: " << player->experience << endl;
    cout << "Gold: " << player->gold << endl;
}
