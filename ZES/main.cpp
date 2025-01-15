#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    GameManager gameManager;

    // ���� �ʱ�ȭ
    gameManager.initializeGame();

    // �÷��̾� ���� (Singleton)
    cout << "Please enter a player name: ";
    string playerName;
    cin >> playerName;
    Character* player = Character::getInstance(playerName);

    cout << "The game begins!" << endl;

    bool isRunning = true;

    while (isRunning) {

        if (player->level == 10)
        {
			cout << "Congratulations! You've reached the highest level!" << endl;
			isRunning = false;
			Monster* boss = new rainbowwatt();

			cout << "The final boss, " << boss->getName() << " is here! Battle begins!" << endl;



			delete boss;
			break;
        }

        cout << "\n=========================" << endl;
        cout << "1. View Player Status" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. Start a battle" << endl;
        cout << "4. End the game" << endl;
        cout << "=========================" << endl;

        int choice;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // �÷��̾� ���� ǥ��
            player->displayStats();
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
            gameManager.endGame();
            isRunning = false;
            break;

        default:
            cout << "Invalid input, please re-select." << endl;
        }
		if (player->currentHealth <= 0)
		{
			cout << "You are dead. Game Over." << endl;
			isRunning = false;
		}
    }

    return 0;
}