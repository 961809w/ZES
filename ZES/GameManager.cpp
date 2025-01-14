#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>
using namespace std;

Monster* GameManager::generateMonster(int level) {
    // ¸ó½ºÅÍ »ı¼º ·ÎÁ÷
    cout << "Generating a monster of level " << level << endl;
    return new Monster(); // ¸ó½ºÅÍ °´Ã¼ »ı¼º ÇÊ¿ä
}

void GameManager::battle(Character* player) {
<<<<<<< Updated upstream
    // ¹èÆ² ·ÎÁ÷
    cout << "Battle initiated with player: " << player->getName() << endl;
=======

    Monster* monster = generateMonster();
    cout << "ëª¬ìŠ¤í„° " << monster->getName() << " ë“±ì¥! ì „íˆ¬ ì‹œì‘!" << endl;
    bool isAlive = true;
    while (isAlive)
    {
        monster->displayInfo();
        cout << endl;

        player->useItem();
        monster->takeDamage(player->attack);
        cout << "ëª¬ìŠ¤í„° " << monster->getName() << "ì—ê²Œ " << player->attack << "ë§Œí¼ì˜ ë°ë¯¸ì§€ë¥¼ ì…í˜”ìŠµë‹ˆë‹¤." << endl;
		monster->displayInfo();
        if (monster->getHealth() <= 0)
        {
            cout << "ëª¬ìŠ¤í„° " << monster->getName() << "ë¥¼ ë¬¼ë¦¬ì³¤ìŠµë‹ˆë‹¤!" << endl;
            player->gainExperience(monster->getExperience());
            player->levelUp();
            player->gold += rand() % 100 + 50;
            isAlive = false;
        }
        player->useItem();
        monster->attackPlayer(*player);
        cout << "í”Œë ˆì´ì–´ " << player->getName() << "ê°€ " << monster->getAttack() << "ë§Œí¼ì˜ ë°ë¯¸ì§€ë¥¼ ì…ì—ˆìŠµë‹ˆë‹¤." << endl;
        cout << "í”Œë ˆì´ì–´ " << player->getName() << "ì˜ ì²´ë ¥: " << player->getHealth() << endl;
        if (player->getHealth() <= 0)
        {
            cout << "í”Œë ˆì´ì–´ " << player->getName() << "ê°€ ì£½ì—ˆìŠµë‹ˆë‹¤!" << endl;
            isAlive = false;
        }
>>>>>>> Stashed changes
}

void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // ¸ó½ºÅÍ¿Í »óÈ£ÀÛ¿ë ·ÎÁ÷ 
    cout << "Handling interaction between player " << player->getName()
        << " and monster " << monster->getName() << endl;
}

<<<<<<< Updated upstream
// + Ãß°¡ÀûÀÎ ¿ä¼Òµé
void GameManager::displayInventory(const vector<Item*>& inventory) {
    // ÀÎº¥Åä¸®(¾ÆÀÌÅÛ ¸®½ºÆ®) Ãâ·Â ·ÎÁ÷
    cout << "Displaying inventory:" << endl;
=======
void GameManager::displayInventory(const vector<Item*>&inventory) {
    // ì¸ë²¤í† ë¦¬(ì•„ì´í…œ ë¦¬ìŠ¤íŠ¸) ì¶œë ¥ ë¡œì§
    cout << "ì¸ë²¤í† ë¦¬ :" << endl;
>>>>>>> Stashed changes
    for (const auto& item : inventory) {
        cout << " - " << item->getName() << endl; // ¾ÆÀÌÅÛ ÀÌ¸§ Ãâ·Â
    }
}

<<<<<<< Updated upstream
void GameManager::initializeGame() {
    // °ÔÀÓ ÃÊ±âÈ­ ·ÎÁ÷
    cout << "Initializing the game..." << endl;
}

void GameManager::endGame() {
    // °ÔÀÓ Á¾·á ·ÎÁ÷
    cout << "Ending the game..." << endl;
}

//void GameManager::displayPlayerStatus(Character* player) {
//    // ÇÃ·¹ÀÌ¾î »óÅÂ Ç¥½Ã ·ÎÁ÷
//    cout << "Player Status: " << endl;
//    cout << "Name: " << player->getName() << endl;
//    cout << "Level: " << player->level << endl;
//    cout << "Health: " << player->health << "/" << player->maxHealth << endl;
//    cout << "Experience: " << player->experience << endl;
//    cout << "Gold: " << player->gold << endl;
//}

//void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
//    // ¸ó½ºÅÍ¿Í »óÈ£ÀÛ¿ë ·ÎÁ÷ 
//    cout << "Handling interaction between player " << player->getName()
//        << " and monster " << monster->getName() << endl;
//}

=======

/*void GameManager::handleMonsterInteraction(Monster* monster, Character* player) {
    // ëª¬ìŠ¤í„°ì™€ ìƒí˜¸ì‘ìš© ë¡œì§
    cout << "í”Œë ˆì´ì–´ " << player->getName()
        << " ì™€ ëª¬ìŠ¤í„° " << monster->getName() << " ì „íˆ¬ ì¤‘" << endl;
}*/

void GameManager::initializeGame() {
    // ê²Œì„ ì´ˆê¸°í™” ë¡œì§
    cout << "ê²Œì„ ì´ˆê¸°í™”..." << endl;
}

void GameManager::endGame() {
    // ê²Œì„ ì¢…ë£Œ ë¡œì§
    cout << "ê²Œì„ ì¢…ë£Œ..." << endl;
}
>>>>>>> Stashed changes
