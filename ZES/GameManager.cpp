#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // 몬스터 생성 로직
    cout << "Generating a monster of level " << level << endl;
    return new Monster(); // 몬스터 객체 생성 필요
}

void GameManager::battle(Character* player) {
<<<<<<< Updated upstream
    // 배틀 로직
    cout << "Battle initiated with player: " << player->getName() << endl;
=======

    Monster* monster = generateMonster();
    cout << "紐ъ뒪�꽣 " << monster->getName() << " �벑�옣! �쟾�닾 �떆�옉!" << endl;
    bool isAlive = true;
    while (isAlive)
    {
        monster->displayInfo();
        cout << endl;

        player->useItem();
        monster->takeDamage(player->attack);
        cout << "紐ъ뒪�꽣 " << monster->getName() << "�뿉寃� " << player->attack << "留뚰겮�쓽 �뜲誘몄��瑜� �엯�삍�뒿�땲�떎." << endl;
		monster->displayInfo();
        if (monster->getHealth() <= 0)
        {
            cout << "紐ъ뒪�꽣 " << monster->getName() << "瑜� 臾쇰━爾ㅼ뒿�땲�떎!" << endl;
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
        }
        player->useItem();
        monster->attackPlayer(*player);
        cout << "�뵆�젅�씠�뼱 " << player->getName() << "媛� " << monster->getAttack() << "留뚰겮�쓽 �뜲誘몄��瑜� �엯�뿀�뒿�땲�떎." << endl;
        cout << "�뵆�젅�씠�뼱 " << player->getName() << "�쓽 泥대젰: " << player->getHealth() << endl;
        if (player->getHealth() <= 0)
        {
            cout << "�뵆�젅�씠�뼱 " << player->getName() << "媛� 二쎌뿀�뒿�땲�떎!" << endl;
            isAlive = false;
        }
>>>>>>> Stashed changes
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 몬스터와 상호작용 로직 
    cout << "Handling interaction between player " << player->getName()
        << " and monster " << monster->getName() << endl;
}

<<<<<<< Updated upstream
// + 추가적인 요소들
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // 인벤토리(아이템 리스트) 출력 로직
    cout << "Displaying inventory:" << endl;
=======
void GameManager::displayInventory(const vector<Item*>&inventory) {
    // �씤踰ㅽ넗由�(�븘�씠�뀥 由ъ뒪�듃) 異쒕젰 濡쒖쭅
    cout << "�씤踰ㅽ넗由� :" << endl;
>>>>>>> Stashed changes
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // 아이템 이름 출력
    }
}

<<<<<<< Updated upstream
void GameManager::initializeGame() {
    // 게임 초기화 로직
    cout << "Initializing the game..." << endl;
}

void GameManager::endGame() {
    // 게임 종료 로직
    cout << "Ending the game..." << endl;
}

//void GameManager::displayPlayerStatus(Character* player) {
//    // 플레이어 상태 표시 로직
//    cout << "Player Status: " << endl;
//    cout << "Name: " << player->getName() << endl;
//    cout << "Level: " << player->level << endl;
//    cout << "Health: " << player->health << "/" << player->maxHealth << endl;
//    cout << "Experience: " << player->experience << endl;
//    cout << "Gold: " << player->gold << endl;
//}

//void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
//    // 몬스터와 상호작용 로직 
//    cout << "Handling interaction between player " << player->getName()
//        << " and monster " << monster->getName() << endl;
//}

=======

/*void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // 紐ъ뒪�꽣��� �긽�샇�옉�슜 濡쒖쭅
    cout << "�뵆�젅�씠�뼱 " << player->getName()
        << " ��� 紐ъ뒪�꽣 " << monster->getName() << " �쟾�닾 以�" << endl;
}*/

void GameManager::initializeGame() {
    // 寃뚯엫 珥덇린�솕 濡쒖쭅
    cout << "寃뚯엫 珥덇린�솕..." << endl;
}

void GameManager::endGame() {
    // 寃뚯엫 醫낅즺 濡쒖쭅
    cout << "寃뚯엫 醫낅즺..." << endl;
}
>>>>>>> Stashed changes
