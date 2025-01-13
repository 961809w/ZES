#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

// 瞪羲 楠渾 縛霞
static random_device rd;
static mt19937 gen(rd());

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// 煎斜蒂 盪濰ж晦 嬪и 除欽и 掘褻羹 �分� 僥濠翮 漱攪煎 渠羹 陛棟
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
vector<string> gameLog;

void AddLog(const string& logMessage) {
    cout << logMessage << endl;
    gameLog.push_back(logMessage);
}

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// 議葛攪 塽 跨蝶攪蒂 嬪и 贗楚蝶
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
class Character {
public:
    string name;
    int level;
    int exp;
    int maxHP;
    int currentHP;
    int attack;
    int gold;
    // 嬴檜蠱 爾嶸 鼻�窕� 除欽�� 盪濰: HP 隸陛 嬴檜蠱, 奢問溘 隸陛 嬴檜蠱
    // 褒薯 啪歜縑憮朝 嬴檜蠱擊 罹楝 謙盟, 罹楝 偃 爾嶸ж紫煙 �挫� 陛棟
    int itemCountHP;
    int itemCountAtk;

    Character(const string& _name)
        : name(_name), level(1), exp(0), maxHP(200), currentHP(200),
        attack(30), gold(0), itemCountHP(0), itemCountAtk(0) {
    }

    void PrintStatus() {
        cout << "====================================\n";
        cout << "[ " << name << " 鼻鷓 ]\n"
            << "溯漣: " << level
            << " | 羹溘: " << currentHP << "/" << maxHP
            << " | 奢問溘: " << attack
            << " | 唳я纂: " << exp << "/100"
            << " | 埤萄: " << gold << "\n"
            << "爾嶸 嬴檜蠱(HP+50): " << itemCountHP
            << ", (ATK+10): " << itemCountAtk << "\n";
        cout << "====================================\n";
    }

    void GainExp(int amount) {
        exp += amount;
        AddLog("[憲葡] " + name + "陛(檜) 唳я纂 " + to_string(amount) + " �僱�! (⑷營 EXP: " + to_string(exp) + "/100)");
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
        // 羹溘, 奢問溘 鼻蝓
        maxHP = maxHP + (level * 20);
        currentHP = maxHP; // 溯漣機 衛 羹溘 瞪睡 �蛹�
        attack = attack + (level * 5);

        AddLog("[溯漣機] " + name + "陛(檜) " + to_string(level) + "溯漣檜 腎歷蝗棲棻!");
        AddLog(" -> 羹溘: " + to_string(maxHP) + ", 奢問溘: " + to_string(attack));
    }

    bool IsDead() {
        return currentHP <= 0;
    }

    // 嬴檜蠱 �膩� 餌辨
    void UseItemHP() {
        currentHP += 50;
        if (currentHP > maxHP) currentHP = maxHP;
        AddLog("[嬴檜蠱 餌辨] 羹溘 +50 瞳辨! (" + to_string(currentHP) + "/" + to_string(maxHP) + ")");
    }

    void UseItemAtk() {
        attack += 10;
        AddLog("[嬴檜蠱 餌辨] 奢問溘 +10 瞳辨! (⑷營 奢問溘: " + to_string(attack) + ")");
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

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// 跨蝶攪 儅撩 煎霜 (議葛攪 溯漣縑 綠滔)
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
Monster GenerateMonster(int playerLevel) {
    // 歜曖煎 跨蝶攪 檜葷 賃 偃 雖薑
    static vector<string> monsterNames = {
        "Goblin", "Slime", "Wolf", "Orc", "Skeleton", "Dragon"
    };

    // 跨蝶攪 檜葷 楠渾 摹鷗
    uniform_int_distribution<> distName(0, monsterNames.size() - 1);
    string mName = monsterNames[distName(gen)];

    // 羹溘: (溯漣 ▼ 20) ~ (溯漣 ▼ 30)
    uniform_int_distribution<> distHP(playerLevel * 20, playerLevel * 30);
    int mHP = distHP(gen);

    // 奢問溘: (溯漣 ▼ 5) ~ (溯漣 ▼ 10)
    uniform_int_distribution<> distATK(playerLevel * 5, playerLevel * 10);
    int mATK = distATK(gen);

    Monster m(mName, mHP, mATK);
    return m;
}

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// 瞪癱 霞ч
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
bool Battle(Character& player) {
    // 跨蝶攪 儅撩
    Monster monster = GenerateMonster(player.level);
    AddLog("跨蝶攪 " + monster.name + " 蛔濰! 羹溘: " + to_string(monster.hp) + ", 奢問溘: " + to_string(monster.atk));

    // 瞪癱 瑞Щ (欐薯)
    bool playerTurn = true;
    while (true) {
        if (playerTurn) {
            // (1) 嬴檜蠱 楠渾 餌辨 (30% �捕�煎 衛紫)
            //     嬴檜蠱 HP陛 氈戲賊 HP 嬴檜蠱, 橈戲賊 奢問 嬴檜蠱 餌辨ж朝 衝戲煎 �挫� 陛棟.
            //     罹晦摹 萃 醞 ж釭塭紫 氈戲賊 嬴鼠剪釭 噙朝 衝曖 蕨衛.
            if ((rand() % 100) < 30) { // 30% �捕�
                // 爾嶸 嬴檜蠱 醞 鼠濛嬪 餌辨
                bool usedItem = false;
                if (player.itemCountHP > 0 && player.itemCountAtk > 0) {
                    // 萃 棻 氈戲賊 50% �捕�煎 摹鷗
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
                // usedItem = false 檜賊 嬴檜蠱檜 橈橫憮 跤 噪
            }

            // (2) Ы溯檜橫 奢問
            monster.hp -= player.attack;
            if (monster.hp < 0) monster.hp = 0;
            AddLog(player.name + "陛(檜) " + monster.name + "擊(蒂) 奢問! "
                + monster.name + " 羹溘: " + to_string(monster.hp));

            if (monster.IsDead()) {
                // 跨蝶攪 籀纂
                AddLog(monster.name + " 籀纂!");
                // 瞪葬ヶ(唳я纂, 埤萄, 嬴檜蠱) �僱� 籀葬
                int goldGain = rand() % 11 + 10; // 10 ~ 20
                player.gold += goldGain;
                player.GainExp(50);
                AddLog(player.name + "陛(檜) " + to_string(goldGain)
                    + " 埤萄蒂 �僱磈蔇懂炴�. (⑷營 埤萄: " + to_string(player.gold) + ")");

                // 30% �捕�煎 嬴檜蠱 �僱�
                if ((rand() % 100) < 30) {
                    // 橫雯 嬴檜蠱擊 還 雖 摹鷗 (50:50)
                    if (rand() % 2 == 0) {
                        player.itemCountHP++;
                        AddLog("[嬴檜蠱 �僱澕 羹溘 +50 嬴檜蠱擊 橢歷蝗棲棻! (爾嶸: " + to_string(player.itemCountHP) + ")");
                    }
                    else {
                        player.itemCountAtk++;
                        AddLog("[嬴檜蠱 �僱澕 奢問溘 +10 嬴檜蠱擊 橢歷蝗棲棻! (爾嶸: " + to_string(player.itemCountAtk) + ")");
                    }
                }

                return true; // 瞪癱 蝓葬
            }

        }
        else {
            // 跨蝶攪 奢問
            player.currentHP -= monster.atk;
            if (player.currentHP < 0) player.currentHP = 0;
            AddLog(monster.name + "檜(陛) " + player.name + "蒂 奢問! "
                + player.name + " 羹溘: " + to_string(player.currentHP));

            if (player.IsDead()) {
                AddLog(player.name + "陛(檜) 餌蜂ц蝗棲棻... 啪歜 螃幗!");
                return false; // Ы溯檜橫 ぬ寡
            }
        }
        // 欐 掖渠
        playerTurn = !playerTurn;
    }
}

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// 詭檣
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
int main() {
    srand((unsigned int)time(NULL));
    cout << "議葛攪 檜葷擊 殮溘ж撮蹂: ";
    string charName;
    cin >> charName;

    Character player(charName);
    AddLog("議葛攪 " + player.name + " 儅撩 諫猿! "
        + "(溯漣: " + to_string(player.level)
        + ", 羹溘: " + to_string(player.currentHP)
        + ", 奢問溘: " + to_string(player.attack) + ")");

    bool isGameOver = false;

    // 除欽и 啪歜 瑞Щ
    while (!isGameOver) {
        // 議葛攪 鼻鷓 �挫�
        player.PrintStatus();

        // 瞪癱 衛濛
        cout << "[1] 瞪癱ж晦\n"
            << "[2] 鼻薄(蝶霾 陛棟)\n"
            << "[3] 啪歜 謙猿\n"
            << "摹鷗 > ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // 瞪癱
            if (!Battle(player)) {
                // ぬ寡
                isGameOver = true;
            }
            else {
                // 蝓葬 �� 溯漣 10檜 腎歷朝雖 羹觼
                if (player.level >= 10) {
                    AddLog(player.name + "陛(檜) 虜溝(10)縑 紫殖ц蝗棲棻! 啪歜 贗葬橫!");
                    isGameOver = true;
                }
            }
            break;
        }
        case 2: {
            // 鼻薄 蕨衛 (除欽�� 埤萄煎 嬴檜蠱擊 掘衙ж朝 衝)
            cout << "==== 鼻薄 ====\n"
                << "[1] 羹溘 +50 嬴檜蠱 (陛問: 30埤萄)\n"
                << "[2] 奢問溘 +10 嬴檜蠱 (陛問: 30埤萄)\n"
                << "[3] 鼻薄 釭陛晦\n"
                << "摹鷗 > ";
            int shopChoice;
            cin >> shopChoice;
            if (shopChoice == 1) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountHP++;
                    AddLog("[鼻薄] 羹溘 +50 嬴檜蠱 掘衙! (爾嶸 埤萄: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[鼻薄] 埤萄陛 睡褶м棲棻!");
                }
            }
            else if (shopChoice == 2) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountAtk++;
                    AddLog("[鼻薄] 奢問溘 +10 嬴檜蠱 掘衙! (爾嶸 埤萄: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[鼻薄] 埤萄陛 睡褶м棲棻!");
                }
            }
            else {
                // 鼻薄 釭陛晦
            }
            // 鼻薄 檜�� 瞪癱 嶸紫(僥薯 褻勒 蕨衛)
            cout << "[1] 夥煎 瞪癱ж晦\n[2] 剩橫陛晦\n摹鷗 > ";
            int postShopChoice;
            cin >> postShopChoice;
            if (postShopChoice == 1) {
                // 瞪癱
                if (!Battle(player)) {
                    isGameOver = true;
                }
                else {
                    // 蝓葬 �� 虜溝檣雖 羹觼
                    if (player.level >= 10) {
                        AddLog(player.name + "陛(檜) 虜溝(10)縑 紫殖ц蝗棲棻! 啪歜 贗葬橫!");
                        isGameOver = true;
                    }
                }
            }
            else {
                // 瞪癱 蝶霾
            }
            break;
        }
        case 3:
            AddLog("啪歜擊 謙猿м棲棻.");
            isGameOver = true;
            break;
        default:
            cout << "澀跤脹 殮溘殮棲棻.\n";
            break;
        }

        if (player.IsDead()) {
            // 餌蜂
            isGameOver = true;
        }
    }

    // 啪歜 煎斜 轎溘
    cout << "\n========== 啪歜 煎斜 ==========\n";
    for (auto& log : gameLog) {
        cout << log << endl;
    }

    return 0;
}