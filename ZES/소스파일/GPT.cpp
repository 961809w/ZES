#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

// ���� ���� ����
static random_device rd;
static mt19937 gen(rd());

// ��������������������������������������������������������������������������������������������������������������������������
// �α׸� �����ϱ� ���� ������ ����ü Ȥ�� ���ڿ� ���ͷ� ��ü ����
// ��������������������������������������������������������������������������������������������������������������������������
vector<string> gameLog;

void AddLog(const string& logMessage) {
    cout << logMessage << endl;
    gameLog.push_back(logMessage);
}

// ��������������������������������������������������������������������������������������������������������������������������
// ĳ���� �� ���͸� ���� Ŭ����
// ��������������������������������������������������������������������������������������������������������������������������
class Character {
public:
    string name;
    int level;
    int exp;
    int maxHP;
    int currentHP;
    int attack;
    int gold;
    // ������ ���� ��Ȳ�� ������ ����: HP ���� ������, ���ݷ� ���� ������
    // ���� ���ӿ����� �������� ���� ����, ���� �� �����ϵ��� Ȯ�� ����
    int itemCountHP;
    int itemCountAtk;

    Character(const string& _name)
        : name(_name), level(1), exp(0), maxHP(200), currentHP(200),
        attack(30), gold(0), itemCountHP(0), itemCountAtk(0) {
    }

    void PrintStatus() {
        cout << "====================================\n";
        cout << "[ " << name << " ���� ]\n"
            << "����: " << level
            << " | ü��: " << currentHP << "/" << maxHP
            << " | ���ݷ�: " << attack
            << " | ����ġ: " << exp << "/100"
            << " | ���: " << gold << "\n"
            << "���� ������(HP+50): " << itemCountHP
            << ", (ATK+10): " << itemCountAtk << "\n";
        cout << "====================================\n";
    }

    void GainExp(int amount) {
        exp += amount;
        AddLog("[�˸�] " + name + "��(��) ����ġ " + to_string(amount) + " ȹ��! (���� EXP: " + to_string(exp) + "/100)");
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
        // ü��, ���ݷ� ���
        maxHP = maxHP + (level * 20);
        currentHP = maxHP; // ������ �� ü�� ���� ȸ��
        attack = attack + (level * 5);

        AddLog("[������] " + name + "��(��) " + to_string(level) + "������ �Ǿ����ϴ�!");
        AddLog(" -> ü��: " + to_string(maxHP) + ", ���ݷ�: " + to_string(attack));
    }

    bool IsDead() {
        return currentHP <= 0;
    }

    // ������ ȿ�� ���
    void UseItemHP() {
        currentHP += 50;
        if (currentHP > maxHP) currentHP = maxHP;
        AddLog("[������ ���] ü�� +50 ����! (" + to_string(currentHP) + "/" + to_string(maxHP) + ")");
    }

    void UseItemAtk() {
        attack += 10;
        AddLog("[������ ���] ���ݷ� +10 ����! (���� ���ݷ�: " + to_string(attack) + ")");
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

// ��������������������������������������������������������������������������������������������������������������������������
// ���� ���� ���� (ĳ���� ������ ���)
// ��������������������������������������������������������������������������������������������������������������������������
Monster GenerateMonster(int playerLevel) {
    // ���Ƿ� ���� �̸� �� �� ����
    static vector<string> monsterNames = {
        "Goblin", "Slime", "Wolf", "Orc", "Skeleton", "Dragon"
    };

    // ���� �̸� ���� ����
    uniform_int_distribution<> distName(0, monsterNames.size() - 1);
    string mName = monsterNames[distName(gen)];

    // ü��: (���� �� 20) ~ (���� �� 30)
    uniform_int_distribution<> distHP(playerLevel * 20, playerLevel * 30);
    int mHP = distHP(gen);

    // ���ݷ�: (���� �� 5) ~ (���� �� 10)
    uniform_int_distribution<> distATK(playerLevel * 5, playerLevel * 10);
    int mATK = distATK(gen);

    Monster m(mName, mHP, mATK);
    return m;
}

// ��������������������������������������������������������������������������������������������������������������������������
// ���� ����
// ��������������������������������������������������������������������������������������������������������������������������
bool Battle(Character& player) {
    // ���� ����
    Monster monster = GenerateMonster(player.level);
    AddLog("���� " + monster.name + " ����! ü��: " + to_string(monster.hp) + ", ���ݷ�: " + to_string(monster.atk));

    // ���� ���� (����)
    bool playerTurn = true;
    while (true) {
        if (playerTurn) {
            // (1) ������ ���� ��� (30% Ȯ���� �õ�)
            //     ������ HP�� ������ HP ������, ������ ���� ������ ����ϴ� ������ Ȯ�� ����.
            //     ���⼱ �� �� �ϳ��� ������ �ƹ��ų� ���� ���� ����.
            if ((rand() % 100) < 30) { // 30% Ȯ��
                // ���� ������ �� ������ ���
                bool usedItem = false;
                if (player.itemCountHP > 0 && player.itemCountAtk > 0) {
                    // �� �� ������ 50% Ȯ���� ����
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
                // usedItem = false �̸� �������� ��� �� ��
            }

            // (2) �÷��̾� ����
            monster.hp -= player.attack;
            if (monster.hp < 0) monster.hp = 0;
            AddLog(player.name + "��(��) " + monster.name + "��(��) ����! "
                + monster.name + " ü��: " + to_string(monster.hp));

            if (monster.IsDead()) {
                // ���� óġ
                AddLog(monster.name + " óġ!");
                // ����ǰ(����ġ, ���, ������) ȹ�� ó��
                int goldGain = rand() % 11 + 10; // 10 ~ 20
                player.gold += goldGain;
                player.GainExp(50);
                AddLog(player.name + "��(��) " + to_string(goldGain)
                    + " ��带 ȹ���߽��ϴ�. (���� ���: " + to_string(player.gold) + ")");

                // 30% Ȯ���� ������ ȹ��
                if ((rand() % 100) < 30) {
                    // � �������� �� �� ���� (50:50)
                    if (rand() % 2 == 0) {
                        player.itemCountHP++;
                        AddLog("[������ ȹ��] ü�� +50 �������� ������ϴ�! (����: " + to_string(player.itemCountHP) + ")");
                    }
                    else {
                        player.itemCountAtk++;
                        AddLog("[������ ȹ��] ���ݷ� +10 �������� ������ϴ�! (����: " + to_string(player.itemCountAtk) + ")");
                    }
                }

                return true; // ���� �¸�
            }

        }
        else {
            // ���� ����
            player.currentHP -= monster.atk;
            if (player.currentHP < 0) player.currentHP = 0;
            AddLog(monster.name + "��(��) " + player.name + "�� ����! "
                + player.name + " ü��: " + to_string(player.currentHP));

            if (player.IsDead()) {
                AddLog(player.name + "��(��) ����߽��ϴ�... ���� ����!");
                return false; // �÷��̾� �й�
            }
        }
        // �� ����
        playerTurn = !playerTurn;
    }
}

// ��������������������������������������������������������������������������������������������������������������������������
// ����
// ��������������������������������������������������������������������������������������������������������������������������
int main() {
    srand((unsigned int)time(NULL));
    cout << "ĳ���� �̸��� �Է��ϼ���: ";
    string charName;
    cin >> charName;

    Character player(charName);
    AddLog("ĳ���� " + player.name + " ���� �Ϸ�! "
        + "(����: " + to_string(player.level)
        + ", ü��: " + to_string(player.currentHP)
        + ", ���ݷ�: " + to_string(player.attack) + ")");

    bool isGameOver = false;

    // ������ ���� ����
    while (!isGameOver) {
        // ĳ���� ���� Ȯ��
        player.PrintStatus();

        // ���� ����
        cout << "[1] �����ϱ�\n"
            << "[2] ����(��ŵ ����)\n"
            << "[3] ���� ����\n"
            << "���� > ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // ����
            if (!Battle(player)) {
                // �й�
                isGameOver = true;
            }
            else {
                // �¸� �� ���� 10�� �Ǿ����� üũ
                if (player.level >= 10) {
                    AddLog(player.name + "��(��) ����(10)�� �����߽��ϴ�! ���� Ŭ����!");
                    isGameOver = true;
                }
            }
            break;
        }
        case 2: {
            // ���� ���� (������ ���� �������� �����ϴ� ��)
            cout << "==== ���� ====\n"
                << "[1] ü�� +50 ������ (����: 30���)\n"
                << "[2] ���ݷ� +10 ������ (����: 30���)\n"
                << "[3] ���� ������\n"
                << "���� > ";
            int shopChoice;
            cin >> shopChoice;
            if (shopChoice == 1) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountHP++;
                    AddLog("[����] ü�� +50 ������ ����! (���� ���: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[����] ��尡 �����մϴ�!");
                }
            }
            else if (shopChoice == 2) {
                if (player.gold >= 30) {
                    player.gold -= 30;
                    player.itemCountAtk++;
                    AddLog("[����] ���ݷ� +10 ������ ����! (���� ���: " + to_string(player.gold) + ")");
                }
                else {
                    AddLog("[����] ��尡 �����մϴ�!");
                }
            }
            else {
                // ���� ������
            }
            // ���� ���� ���� ����(���� ���� ����)
            cout << "[1] �ٷ� �����ϱ�\n[2] �Ѿ��\n���� > ";
            int postShopChoice;
            cin >> postShopChoice;
            if (postShopChoice == 1) {
                // ����
                if (!Battle(player)) {
                    isGameOver = true;
                }
                else {
                    // �¸� �� �������� üũ
                    if (player.level >= 10) {
                        AddLog(player.name + "��(��) ����(10)�� �����߽��ϴ�! ���� Ŭ����!");
                        isGameOver = true;
                    }
                }
            }
            else {
                // ���� ��ŵ
            }
            break;
        }
        case 3:
            AddLog("������ �����մϴ�.");
            isGameOver = true;
            break;
        default:
            cout << "�߸��� �Է��Դϴ�.\n";
            break;
        }

        if (player.IsDead()) {
            // ���
            isGameOver = true;
        }
    }

    // ���� �α� ���
    cout << "\n========== ���� �α� ==========\n";
    for (auto& log : gameLog) {
        cout << log << endl;
    }

    return 0;
}