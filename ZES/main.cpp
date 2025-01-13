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
            gameManager.displayPlayerStatus(player);
            break;

        case 2:
            // �κ��丮 ǥ��
            gameManager.displayInventory(player->inventory);
            break;

        case 3:
            // ���Ϳ� ����
            gameManager.battle(player);
            break;

        case 4:
            // ���� ����
            isRunning = false;
            gameManager.endGame();
            break;

        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
            break;
        }
    }

    return 0;
}
