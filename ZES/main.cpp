#include "GameManager.h"
#include <iostream>

using namespace std;

int main() {
    GameManager gameManager;

    // 게임 초기화
    gameManager.initializeGame();

    // 플레이어 생성 (Singleton)
    cout << "플레이어 이름을 입력하세요: ";
    string playerName;
    cin >> playerName;
    Character* player = Character::getInstance(playerName);

    cout << "게임이 시작됩니다!" << endl;

    bool isRunning = true;

    while (isRunning) {
        cout << "\n=========================" << endl;
        cout << "1. 플레이어 상태 보기" << endl;
        cout << "2. 인벤토리 보기" << endl;
        cout << "3. 전투 시작" << endl;
        cout << "4. 게임 종료" << endl;
        cout << "=========================" << endl;

        int choice;
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // 플레이어 상태 표시
            player->displayStats();

        case 2:
            // 인벤토리 표시
            gameManager.displayInventory(player->inventory);

        case 3:
            // 몬스터와 전투
            gameManager.battle(player);

        case 4:
            // 게임 종료
            gameManager.endGame();
            break;

        default:
            cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
        }
    }

    return 0;
}