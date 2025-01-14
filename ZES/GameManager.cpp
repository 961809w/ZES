#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // ���� ���� ����
    cout << "Generating a monster of level " << level << endl;
    return new Monster(); // ���� ��ü ���� �ʿ�
}

void GameManager::battle(Character* player) {
<<<<<<< Updated upstream
    // ��Ʋ ����
    cout << "Battle initiated with player: " << player->getName() << endl;
=======

    Monster* monster = generateMonster();
    cout << "몬스터 " << monster->getName() << " 등장! 전투 시작!" << endl;
    bool isAlive = true;
    while (isAlive)
    {
        monster->displayInfo();
        cout << endl;

        player->useItem();
        monster->takeDamage(player->attack);
        cout << "몬스터 " << monster->getName() << "에게 " << player->attack << "만큼의 데미지를 입혔습니다." << endl;
		monster->displayInfo();
        if (monster->getHealth() <= 0)
        {
            cout << "몬스터 " << monster->getName() << "를 물리쳤습니다!" << endl;
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
        }
        player->useItem();
        monster->attackPlayer(*player);
        cout << "플레이어 " << player->getName() << "가 " << monster->getAttack() << "만큼의 데미지를 입었습니다." << endl;
        cout << "플레이어 " << player->getName() << "의 체력: " << player->getHealth() << endl;
        if (player->getHealth() <= 0)
        {
            cout << "플레이어 " << player->getName() << "가 죽었습니다!" << endl;
            isAlive = false;
        }
>>>>>>> Stashed changes
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // ���Ϳ� ��ȣ�ۿ� ���� 
    cout << "Handling interaction between player " << player->getName()
        << " and monster " << monster->getName() << endl;
}

<<<<<<< Updated upstream
// + �߰����� ��ҵ�
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // �κ��丮(������ ����Ʈ) ��� ����
    cout << "Displaying inventory:" << endl;
=======
void GameManager::displayInventory(const vector<Item*>&inventory) {
    // 인벤토리(아이템 리스트) 출력 로직
    cout << "인벤토리 :" << endl;
>>>>>>> Stashed changes
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // ������ �̸� ���
    }
}

<<<<<<< Updated upstream
void GameManager::initializeGame() {
    // ���� �ʱ�ȭ ����
    cout << "Initializing the game..." << endl;
}

void GameManager::endGame() {
    // ���� ���� ����
    cout << "Ending the game..." << endl;
}

//void GameManager::displayPlayerStatus(Character* player) {
//    // �÷��̾� ���� ǥ�� ����
//    cout << "Player Status: " << endl;
//    cout << "Name: " << player->getName() << endl;
//    cout << "Level: " << player->level << endl;
//    cout << "Health: " << player->health << "/" << player->maxHealth << endl;
//    cout << "Experience: " << player->experience << endl;
//    cout << "Gold: " << player->gold << endl;
//}

//void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
//    // ���Ϳ� ��ȣ�ۿ� ���� 
//    cout << "Handling interaction between player " << player->getName()
//        << " and monster " << monster->getName() << endl;
//}

=======

/*void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 몬스터와 상호작용 로직
    cout << "플레이어 " << player->getName()
        << " 와 몬스터 " << monster->getName() << " 전투 중" << endl;
}*/

void GameManager::initializeGame() {
    // 게임 초기화 로직
    cout << "게임 초기화..." << endl;
}

void GameManager::endGame() {
    // 게임 종료 로직
    cout << "게임 종료..." << endl;
}
>>>>>>> Stashed changes
