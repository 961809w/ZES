#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "item.h"
#include "shop.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	// 게임 매니저 생성
	GameManager gameManager;

	// 게임 초기화
	gameManager.initializeGame();

	// 플레이어 생성 (Singleton)
	cout << "Please enter a player name: ";
	string playerName;
	cin >> playerName;
	Character* player = Character::getInstance(playerName);

	cout << "The game begins!" << endl;

	//bool isRunning = true;

	while (!gameManager.isGameOver) {

		if (player->level == 10)
		{


			cout << "Congratulations! You've reached the highest level!" << endl;

			gameManager.generateBoss(player);
		}

		if (gameManager.isGameOver) {
			break;// 게임 종료
		}

		cout << "\n=========================" << endl;
		cout << "1. View Player Status" << endl;
		cout << "2. View Inventory" << endl;\
			cout << "3. Shop" << endl;
		cout << "4. Start a battle" << endl;
		cout << "5. End the game" << endl;
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
			// 상점
			gameManager.shop(player);
			break;
		case 4:
			// 몬스터와 전투
			gameManager.battle(player);
			break;
		case 5:
			// 게임 종료
			gameManager.endGame();
			return 0;

		default:
			cout << "Invalid input, please re-select." << endl;
		}
		if (player->currentHealth <= 0)
		{
			cout << "You are dead. Game Over." << endl;
			break;
		}
	}

	// 게임 종료 메시지 출력
	if (gameManager.isGameOver) {
		cout << "\n=========================" << endl;
		cout << "  Congratulations!" << endl;
		cout << "  You've completed the game!" << endl;
		cout << "=========================" << endl;
		cout << "Press ENTER to exit...";
		cin.ignore(); // 이전 입력 무시
		cin.get();    // ENTER 입력 대기
	}

	return 0;
}



