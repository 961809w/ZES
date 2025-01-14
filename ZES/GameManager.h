#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>

class GameManager {
public:
    // ¸ó½ºÅÍ »ı¼º
    Monster* generateMonster(int level);

    // ÀüÅõ ¼öÇà
    void battle(Character* player);

    // ¸ó½ºÅÍ¿Í ÇÃ·¹ÀÌ¾î »óÈ£ÀÛ¿ë
    void handleMonsterInteraction(Monster* monster, Character* player);

    // + Ãß°¡ÀûÀÎ ¿ä¼Òµé

    // ÇÃ·¹ÀÌ¾îÀÇ ÀÎº¥Åä¸®(¾ÆÀÌÅÛ ¸®½ºÆ®) Ç¥½Ã
    // ¾ÆÀÌÅÛ °³¼ö´Â °ÔÀÓÁß °è¼Ó ¹Ù²î¹Ç·Î µ¿Àû¹è¿­ Vector »ç¿ë
    // const´Â ÀÎº¥Åä¸® ¸®½ºÆ®ÀÇ ¿øº»À» ¼öÁ¤ÇÏÁö ¸øÇÏµµ·Ï º¸Á¤
    void displayInventory(const vector<Item*>& inventory);


    // °ÔÀÓ ÃÊ±âÈ­
    void initializeGame();

    // °ÔÀÓ Á¾·á
    void endGame();

<<<<<<< Updated upstream
    // ÇÃ·¹ÀÌ¾î »óÅÂ Ç¥½Ã
    void displayPlayerStatus(Character* player);
=======
    // í”Œë ˆì´ì–´ ìƒíƒœ í‘œì‹œ
    //void displayPlayerStatus(Character* player);
>>>>>>> Stashed changes


private:
    // ÇÊ¿äÇÑ °æ¿ì Ãß°¡ÀûÀÎ ¸â¹ö º¯¼ö¸¦ ¼±¾ğ
};

#endif // GAMEMANAGER_H


