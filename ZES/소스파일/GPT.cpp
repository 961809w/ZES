#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

// Àü¿ª ·£´ý ¿£Áø
static random_device rd;
static mt19937 gen(rd());

// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
// ·Î±×¸¦ ÀúÀåÇÏ±â À§ÇÑ °£´ÜÇÑ ±¸Á¶Ã¼ È¤Àº ¹®ÀÚ¿­ º¤ÅÍ·Î ´ëÃ¼ °¡´É
// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
vector<string> gameLog;

void AddLog(const string& logMessage) {
    cout << logMessage << endl;
    gameLog.push_back(logMessage);
}

// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
// Ä³¸¯ÅÍ ¹× ¸ó½ºÅÍ¸¦ À§ÇÑ Å¬·¡½º
// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
class Character {
public:
    string name;
    int level;
    int exp;
    int maxHP;
    int currentHP;
    int attack;
    int gold;
    // ¾ÆÀÌÅÛ º¸À¯ »óÈ²À» °£´ÜÈ÷ ÀúÀå: HP Áõ°¡ ¾ÆÀÌÅÛ, °ø°Ý·Â Áõ°¡ ¾ÆÀÌÅÛ
    // ½ÇÁ¦ °ÔÀÓ¿¡¼­´Â ¾ÆÀÌÅÛÀ» ¿©·¯ Á¾·ù, ¿©·¯ °³ º¸À¯ÇÏµµ·Ï È®Àå °¡´É
    int itemCountHP;
    int itemCountAtk;

    Character(const string& _name)
        : name(_name), level(1), exp(0), maxHP(200), currentHP(200),
        attack(30), gold(0), itemCountHP(0), itemCountAtk(0) {
    }

    void PrintStatus() {
        cout << "====================================\n";
        cout << "[ " << name << " »óÅÂ ]\n"
            << "·¹º§: " << level
            << " | Ã¼·Â: " << currentHP << "/" << maxHP
            << " | °ø°Ý·Â: " << attack
            << " | °æÇèÄ¡: " << exp << "/100"
            << " | °ñµå: " << gold << "\n"
            << "º¸À¯ ¾ÆÀÌÅÛ(HP+50): " << itemCountHP
            << ", (ATK+10): " << itemCountAtk << "\n";
        cout << "====================================\n";
    }

    void GainExp(int amount) {
        exp += amount;
        AddLog("[¾Ë¸²] " + name + "°¡(ÀÌ) °æÇèÄ¡ " + to_string(amount) + " È¹µæ! (ÇöÀç EXP: " + to_string(exp) + "/100)");
        CheckLevelUp();
    }

    void CheckLevelUp() {
        while (exp >= 100 && level < 10) {
            exp -= 100;
            LevelUp();
        }
    }

    void LevelUp() {
        level++;
        // Ã¼·Â, °ø°Ý·Â »ó½Â
        maxHP = maxHP + (level * 20);
        currentHP = maxHP; // ·¹º§¾÷ ½Ã Ã¼·Â ÀüºÎ È¸º¹
        attack = attack + (level * 5);

        AddLog("[·¹º§¾÷] " + name + "°¡(ÀÌ) " + to_string(level) + "·¹º§ÀÌ µÇ¾ú½À´Ï´Ù!");
        AddLog(" -> Ã¼·Â: " + to_string(maxHP) + ", °ø°Ý·Â: " + to_string(attack));
    }

    bool IsDead() {
        return currentHP <= 0;
    }

    // ¾ÆÀÌÅÛ È¿°ú »ç¿ë
    void UseItemHP() {
        currentHP += 50;
        if (currentHP > maxHP) currentHP = maxHP;
        AddLog("[¾ÆÀÌÅÛ »ç¿ë] Ã¼·Â +50 Àû¿ë! (" + to_string(currentHP) + "/" + to_string(maxHP) + ")");
    }

    void UseItemAtk() {
        attack += 10;
        AddLog("[¾ÆÀÌÅÛ »ç¿ë] °ø°Ý·Â +10 Àû¿ë! (ÇöÀç °ø°Ý·Â: " + to_string(attack) + ")");
    }
};

class Monster {
public:
    string name;
    int hp;
    int atk;

    Monster(const string& _name, int _hp, int _atk)
        : name(_name), hp(_hp), atk(_atk) {
    }

    bool IsDead() {
        return hp <= 0;
    }
};

// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
// ¸ó½ºÅÍ »ý¼º ·ÎÁ÷ (Ä³¸¯ÅÍ ·¹º§¿¡ ºñ·Ê)
// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
Monster GenerateMonster(int playerLevel) {
    // ÀÓÀÇ·Î ¸ó½ºÅÍ ÀÌ¸§ ¸î °³ ÁöÁ¤
    static vector<string> monsterNames = {
        "Goblin", "Slime", "Wolf", "Orc", "Skeleton", "Dragon"
    };

    // ¸ó½ºÅÍ ÀÌ¸§ ·£´ý ¼±ÅÃ
    uniform_int_distribution<> distName(0, monsterNames.size() - 1);
    string mName = monsterNames[distName(gen)];

    // Ã¼·Â: (·¹º§ ¡¿ 20) ~ (·¹º§ ¡¿ 30)
    uniform_int_distribution<> distHP(playerLevel * 20, playerLevel * 30);
    int mHP = distHP(gen);

    // °ø°Ý·Â: (·¹º§ ¡¿ 5) ~ (·¹º§ ¡¿ 10)
    uniform_int_distribution<> distATK(playerLevel * 5, playerLevel * 10);
    int mATK = distATK(gen);

    Monster m(mName, mHP, mATK);
    return m;
}

// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
// ÀüÅõ ÁøÇà
// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
bool Battle(Character& player) {
    // ¸ó½ºÅÍ »ý¼º
    Monster monster = GenerateMonster(player.level);
    AddLog("¸ó½ºÅÍ " + monster.name + " µîÀå! Ã¼·Â: " + to_string(monster.hp) + ", °ø°Ý·Â: " + to_string(monster.atk));

    // ÀüÅõ ·çÇÁ (ÅÏÁ¦)
    bool playerTurn = true;
    while (true) {
        if (playerTurn) {
            // (1) ¾ÆÀÌÅÛ ·£´ý »ç¿ë (30% È®·ü·Î ½Ãµµ)
            //     ¾ÆÀÌÅÛ HP°¡ ÀÖÀ¸¸é HP ¾ÆÀÌÅÛ, ¾øÀ¸¸é °ø°Ý ¾ÆÀÌÅÛ »ç¿ëÇÏ´Â ½ÄÀ¸·Î È®Àå °¡´É.
            //     ¿©±â¼± µÑ Áß ÇÏ³ª¶óµµ ÀÖÀ¸¸é ¾Æ¹«°Å³ª ¾²´Â ½ÄÀÇ ¿¹½Ã.
            if ((rand() % 100) < 30) { // 30% È®·ü
                // º¸À¯ ¾ÆÀÌÅÛ Áß ¹«ÀÛÀ§ »ç¿ë
                bool usedItem = false;
                if (player.itemCountHP > 0 && player.itemCountAtk > 0) {
                    // µÑ ´Ù ÀÖÀ¸¸é 50% È®·ü·Î ¼±ÅÃ
                    if (rand() % 2 == 0) {
                        player.itemCountHP--;
                        player.UseItemHP();
                        usedItem = true;
                    }
                    else {
                        player.itemCountAtk--;
                        player.UseItemAtk();
                        usedItem = true;
                    }
                }
                else if (player.itemCountHP > 0) {
                    player.itemCountHP--;
                    player.UseItemHP();
                    usedItem = true;
                }
                else if (player.itemCountAtk > 0) {
                    player.itemCountAtk--;
                    player.UseItemAtk();
                    usedItem = true;
                }
                // usedItem = false ÀÌ¸é ¾ÆÀÌÅÛÀÌ ¾ø¾î¼­ ¸ø ¾¸
            }

            // (2) ÇÃ·¹ÀÌ¾î °ø°Ý
            monster.hp -= player.attack;
            if (monster.hp < 0) monster.hp = 0;
            AddLog(player.name + "°¡(ÀÌ) " + monster.name + "À»(¸¦) °ø°Ý! "
                + monster.name + " Ã¼·Â: " + to_string(monster.hp));

            if (monster.IsDead()) {
                // ¸ó½ºÅÍ Ã³Ä¡
                AddLog(monster.name + " Ã³Ä¡!");
                // Àü¸®Ç°(°æÇèÄ¡, °ñµå, ¾ÆÀÌÅÛ) È¹µæ Ã³¸®
                int goldGain = rand() % 11 + 10; // 10 ~ 20
                player.gold += goldGain;
                player.GainExp(50);
                AddLog(player.name + "°¡(ÀÌ) " + to_string(goldGain)
                    + " °ñµå¸¦ È¹µæÇß½À´Ï´Ù. (ÇöÀç °ñµå: " + to_string(player.gold) + ")");

                // 30% È®·ü·Î ¾ÆÀÌÅÛ È¹µæ
                if ((rand() % 100) < 30) {
                    // ¾î¶² ¾ÆÀÌÅÛÀ» ÁÙ Áö ¼±ÅÃ (50:50)
                    if (rand() % 2 == 0) {
                        player.itemCountHP++;
                        AddLog("[¾ÆÀÌÅÛ È¹µæ] Ã¼·Â +50 ¾ÆÀÌÅÛÀ» ¾ò¾ú½À´Ï´Ù! (º¸À¯: " + to_string(player.itemCountHP) + ")");
                    }
                    else {
                        player.itemCountAtk++;
                        AddLog("[¾ÆÀÌÅÛ È¹µæ] °ø°Ý·Â +10 ¾ÆÀÌÅÛÀ» ¾ò¾ú½À´Ï´Ù! (º¸À¯: " + to_string(player.itemCountAtk) + ")");
                    }
                }

                return true; // ÀüÅõ ½Â¸®
            }

        }
        else {
            // ¸ó½ºÅÍ °ø°Ý
            player.currentHP -= monster.atk;
            if (player.currentHP < 0) player.currentHP = 0;
            AddLog(monster.name + "ÀÌ(°¡) " + player.name + "¸¦ °ø°Ý! "
                + player.name + " Ã¼·Â: " + to_string(player.currentHP));

            if (player.IsDead()) {
                AddLog(player.name + "°¡(ÀÌ) »ç¸ÁÇß½À´Ï´Ù... °ÔÀÓ ¿À¹ö!");
                return false; // ÇÃ·¹ÀÌ¾î ÆÐ¹è
            }
        }
        // ÅÏ ±³´ë
        playerTurn = !playerTurn;
    }
}

// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
// ¸ÞÀÎ
// ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡
int main() {
    srand((unsigned int)time(NULL));
    cout << "Ä³¸¯ÅÍ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ";
    string charName;
    cin >> charName;

    Character player(charName);
    AddLog("Ä³¸¯ÅÍ " + player.name + " »ý¼º ¿Ï·á! "
        + "(·¹º§: " + to_string(player.level)
        + ", Ã¼·Â: " + to_string(player.currentHP)
        + ", °ø°Ý·Â: " + to_string(player.attack) + ")");

    bool isGameOver = false;

    // °£´ÜÇÑ °ÔÀÓ ·çÇÁ
    while (!isGameOver) {
        // Ä³¸¯ÅÍ »óÅÂ È®ÀÎ
        player.PrintStatus();

        // ÀüÅõ ½ÃÀÛ
        cout << "[1] ÀüÅõÇÏ±â\n"
            << "[2] »óÁ¡(½ºÅµ °¡´É)\n"
            << "[3] °ÔÀÓ Á¾·á\n"
            << "¼±ÅÃ > ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // ÀüÅõ
            if (!Battle(player)) {
                // ÆÐ¹è
                isGameOver = true;
            }
            else {
                // ½Â¸® ÈÄ ·¹º§ 10ÀÌ µÇ¾ú´ÂÁö Ã¼Å©
                if (player.level >= 10) {
                    AddLog(player.name + "°¡(ÀÌ) ¸¸·¾(10)¿¡ µµ´ÞÇß½À´Ï´Ù! °ÔÀÓ Å¬¸®¾î!");
                    isGameOver = true;
                }
            }
            break;
        }
        case 2: {
            // »óÁ¡ ¿¹½Ã (°£´ÜÈ÷ °ñµå·Î ¾ÆÀÌÅÛÀ» ±¸¸ÅÇÏ´Â ½Ä)
            cout << "==== »óÁ¡ ====\n"
                << "[1] Ã¼·Â +50 ¾ÆÀÌÅÛ (°¡°Ý: 30°ñµå)\n"
                << "[2] °ø°Ý·Â +10 ¾ÆÀÌÅÛ (°¡°Ý: 30°ñµå)\n"
                << "[3] »óÁ¡ ³ª°¡±â\n"
                << "¼±ÅÃ > ";
            int shopChoice;
            cin >> shopChoice;
            if (shopChoice == 1) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountHP++;
                    AddLog("[»óÁ¡] Ã¼·Â +50 ¾ÆÀÌÅÛ ±¸¸Å! (º¸À¯ °ñµå: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[»óÁ¡] °ñµå°¡ ºÎÁ·ÇÕ´Ï´Ù!");
                }
            }
            else if (shopChoice == 2) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountAtk++;
                    AddLog("[»óÁ¡] °ø°Ý·Â +10 ¾ÆÀÌÅÛ ±¸¸Å! (º¸À¯ °ñµå: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[»óÁ¡] °ñµå°¡ ºÎÁ·ÇÕ´Ï´Ù!");
                }
            }
            else {
                // »óÁ¡ ³ª°¡±â
            }
            // »óÁ¡ ÀÌÈÄ ÀüÅõ À¯µµ(¹®Á¦ Á¶°Ç ¿¹½Ã)
            cout << "[1] ¹Ù·Î ÀüÅõÇÏ±â\n[2] ³Ñ¾î°¡±â\n¼±ÅÃ > ";
            int postShopChoice;
            cin >> postShopChoice;
            if (postShopChoice == 1) {
                // ÀüÅõ
                if (!Battle(player)) {
                    isGameOver = true;
                }
                else {
                    // ½Â¸® ÈÄ ¸¸·¾ÀÎÁö Ã¼Å©
                    if (player.level >= 10) {
                        AddLog(player.name + "°¡(ÀÌ) ¸¸·¾(10)¿¡ µµ´ÞÇß½À´Ï´Ù! °ÔÀÓ Å¬¸®¾î!");
                        isGameOver = true;
                    }
                }
            }
            else {
                // ÀüÅõ ½ºÅµ
            }
            break;
        }
        case 3:
            AddLog("°ÔÀÓÀ» Á¾·áÇÕ´Ï´Ù.");
            isGameOver = true;
            break;
        default:
            cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù.\n";
            break;
        }

        if (player.IsDead()) {
            // »ç¸Á
            isGameOver = true;
        }
    }

    // °ÔÀÓ ·Î±× Ãâ·Â
    cout << "\n========== °ÔÀÓ ·Î±× ==========\n";
    for (auto& log : gameLog) {
        cout << log << endl;
    }

    return 0;
}