#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"

using namespace std;

// 상점 입장
void Shop::enter(Character& player) {
    bool shopping = true;
    while (shopping) {
        cout << "\nWelcome to the Shop!" << endl;
        cout << "1. Buy Items" << endl;
        cout << "2. Sell Items" << endl;
        cout << "3. Exit Shop" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            displayItems();
            cout << "Enter the item number to buy (or -1 to cancel): ";
            int buyIndex;
            cin >> buyIndex;
            if (buyIndex == -1) {
                cout << "Cancelled buying items." << endl;
            }
            else {
                buyItem(buyIndex, &player);
            }
            break;

        case 2:
            if (player.inventory.empty()) {
                cout << "Your inventory is empty. Nothing to sell!" << endl;
            }
            else {
                cout << "Your Inventory:" << endl;
                for (int i = 0; i < player.inventory.size(); ++i) {
                    cout << i << ". " << player.inventory[i]->getName() << endl;
                }
                cout << "Enter the item number to sell (or -1 to cancel): ";
                int sellIndex;
                cin >> sellIndex;
                if (sellIndex == -1) {
                    cout << "Cancelled selling items." << endl;
                }
                else {
                    sellItem(sellIndex, &player);
                }
            }
            break;

        case 3:
            cout << "Thank you for visiting the shop. Goodbye!" << endl;
            shopping = false;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


// 상점에 아이템 종류별 번호, 골드 설정
Shop::Shop() {
    items.push_back(new HealthPotion);  // 0번: 체력 회복 포션
    prices.push_back(100);  // 체력 회복 포션 가격, 100 골드

    items.push_back(new AttackBoost);    // 1번: 공격력 증가 아이템
    prices.push_back(200);  // 공격력 증가 아이템 가격, 200 골드
}

// 상점에서 판매하는 아이템 목록 출력
void Shop::displayItems() {
    cout << "Items available in the shop:" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << i << ". " << items[i]->getName()  // 아이템 이름
            << " (Price: " << prices[i] << " gold)"  // 아이템 가격
            << endl;
    }
}

// 상점 방문 (구매 -> 판매 -> 종료)
void Shop::buyItem(int index, Character* player) {
    if (index >= 0 && index < items.size()) {
        int price = prices[index];
        if (player->gold >= price) {
            player->gold -= price;
            cout << "You bought " << items[index]->getName() << " from the shop." << endl;
            cout << "Remaining gold: " << player->gold << endl;

            // 아이템을 캐릭터 인벤토리 벡터에 'push_back()'으로 추가 - push_back()은 벡터의 끝에 요소를 추가하는 함수
            player->inventory.push_back(items[index]);

            // 아이템 사용
            items[index]->use(player);
        }
        else {
            cout << "Not enough gold to make the purchase." << endl;
        }
    }
    else {
        cout << "Invalid item number." << endl;
    }
}

void Shop::sellItem(int index, Character* player) {
    if (index >= 0 && index < player->inventory.size()) {
        int price = prices[index] / 2;  // 판매 금액은 원래 가격의 절반
        player->gold += price;
        cout << "You sold " << player->inventory[index]->getName() << " from your inventory." << endl;
        cout << "Selling price: " << price << " gold" << endl;
        cout << "Current gold: " << player->gold << endl;

        // 판매한 아이템 삭제
        delete player->inventory[index];
        player->inventory.erase(player->inventory.begin() + index);

        // 상점의 가격 정보도 삭제
        prices.erase(prices.begin() + index);
    }
    else {
        cout << "Invalid item number." << endl;
    }
}

