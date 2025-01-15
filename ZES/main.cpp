#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    GameManager gameManager;

    // 게임 초기화
    gameManager.initializeGame();

    // 플레이어 생성 (Singleton)
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
            // 플레이어 상태 표시
            player->displayStats();
            break;
        case 2:
            // 인벤토리 표시
            gameManager.displayInventory(player->inventory);
            break;
        case 3:
            // 몬스터와 전투
            gameManager.battle(player);
            break;
        case 4:
            // 게임 종료
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