#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
#include "GameManager.h"

using namespace std;

GameManager gm;
// 상점 입장
void Shop::enter(Character& player) {
	bool shopping = true;
	while (shopping) {
		gm.ClearConsole();

		cout << "\nWelcome to the Shop!" << endl;
		cout << "1. Buy Items" << endl;
		cout << "2. Sell Items" << endl;
		cout << "3. Exit Shop" << endl;
		cout << "Choose an option: ";
		int choice;
		cin >> choice;
		gm.ClearConsole();

		switch (choice) {
		case 1:
			displayItems();
			cout << "Enter the item number to buy (or 0 to cancel): ";
			int buyIndex;
			cin >> buyIndex;

			if (buyIndex == 0) {
				gm.ClearConsole();
				cout << "Cancelled buying items." << endl;
				gm.buffer();
			}
			else {
				gm.ClearConsole();
				buyItem(buyIndex, &player);
				gm.buffer();
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			break;

		case 2:
			if (player.inventory.empty()) {

				cout << "Your inventory is empty. Nothing to sell!" << endl;

				gm.buffer();
			}
			else {
				cout << "Your Inventory:" << endl;
				for (int i = 1; i <= player.inventory.size(); ++i) {
					cout << i << ". " << player.inventory[i - 1]->getName() << endl;
				}
				cout << "Enter the item number to sell (or 0 to cancel): ";
				int sellIndex;
				cin >> sellIndex;
				if (sellIndex == 0) {
					gm.ClearConsole();
					cout << "Cancelled selling items." << endl;
					gm.buffer();
				}
				else {
					gm.ClearConsole();
					sellItem(sellIndex, &player);
					gm.buffer();
				}
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			break;

		case 3:
			cout << "Thank you for visiting the shop. Goodbye!" << endl;
			shopping = false;

			break;

		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please try again" << endl;

			gm.buffer();
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
		cout << i + 1 << ". " << items[i]->getName()  // 아이템 이름
			<< " (Price: " << prices[i] << " gold)"  // 아이템 가격
			<< endl;
	}
}

// 상점 방문 (구매 -> 판매 -> 종료)
void Shop::buyItem(int index, Character* player) {
	if (index < 1 || index >(int)items.size()) {
		cout << "Invalid item number." << endl;
		gm.buffer();
		return;
	}

	int price = prices[index - 1];
	if (player->gold < price) {
		gm.ClearConsole();
		cout << "Not enough gold to make the purchase." << endl;
		return;
	}

	player->gold -= price;

	// 상점 아이템을 그대로 넘기지 않고 새로 new 해서 복제
	Item* original = items[index - 1];
	Item* clonedItem = nullptr;
	if (dynamic_cast<HealthPotion*>(original)) {
		clonedItem = new HealthPotion();
	}
	else if (dynamic_cast<AttackBoost*>(original)) {
		clonedItem = new AttackBoost();
	}
	// 필요한 다른 아이템이 있으면 else if 추가

	if (clonedItem) {
		player->inventory.push_back(clonedItem);

		cout << "You bought " << clonedItem->getName() << " for "
			<< price << " gold." << endl;
		cout << "Remaining gold: " << player->gold << endl;
	}
}

void Shop::sellItem(int index, Character* player) {
	// 유효 인덱스 체크
	if (index < 1 || index > player->inventory.size()) {
		cout << "Invalid item number." << endl;
		return;
	}

	// 실제 판매 처리
	Item* itemToSell = player->inventory[index - 1];

	// 예: 아이템 타입(이름)에 따라 판매가 결정
	int sellPrice = 0;
	if (itemToSell->getName() == "HP potion") {
		sellPrice = 50; // 100골드짜리 아이템이었다고 치고 절반은 50
	}
	else if (itemToSell->getName() == "AD potion") {
		sellPrice = 100; // 200골드짜리 아이템이었다고 치고 절반은 100
	}
	else {
		// 그 외는 0원 혹은 별도 계산
		sellPrice = 0;
	}

	// 골드 증액 및 메시지 출력
	player->gold += sellPrice;
	cout << "You sold " << itemToSell->getName() << " for " << sellPrice << " gold." << endl;
	cout << "Current gold: " << player->gold << endl;

	// 인벤토리에서 제거 (실제 아이템 포인터 delete 여부는 구조에 따라 결정)
	delete itemToSell;
	player->inventory.erase(player->inventory.begin() + (index - 1));

	// *** 상점의 prices.erase(...) 이런 건 하지 않는다! ***
}

