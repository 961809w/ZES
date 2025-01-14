#include "GameManager.h"
#include <iostream>

using namespace std;

int main() {
    GameManager gameManager;

    // ���� �ʱ�ȭ
    gameManager.initializeGame();

    // �÷��̾� ���� (Singleton)
    cout << "�÷��̾� �̸��� �Է��ϼ���: ";
    string playerName;
    cin >> playerName;
    Character* player = Character::getInstance(playerName);

    cout << "������ ���۵˴ϴ�!" << endl;

    bool isRunning = true;

    while (isRunning) {
        cout << "\n=========================" << endl;
        cout << "1. �÷��̾� ���� ����" << endl;
        cout << "2. �κ��丮 ����" << endl;
        cout << "3. ���� ����" << endl;
        cout << "4. ���� ����" << endl;
        cout << "=========================" << endl;

        int choice;
        cout << "����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // �÷��̾� ���� ǥ��
            player->displayStats();

        case 2:
            // �κ��丮 ǥ��
            gameManager.displayInventory(player->inventory);

        case 3:
            // ���Ϳ� ����
            gameManager.battle(player);

        case 4:
            // ���� ����
            gameManager.endGame();
            break;

        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    }

    return 0;
}