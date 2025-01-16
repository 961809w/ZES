#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
#include "GameManager.h"

using namespace std;

GameManager gm;
// ���� ����
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


// ������ ������ ������ ��ȣ, ��� ����
Shop::Shop() {
	items.push_back(new HealthPotion);  // 0��: ü�� ȸ�� ����
	prices.push_back(100);  // ü�� ȸ�� ���� ����, 100 ���

	items.push_back(new AttackBoost);    // 1��: ���ݷ� ���� ������
	prices.push_back(200);  // ���ݷ� ���� ������ ����, 200 ���
}

// �������� �Ǹ��ϴ� ������ ��� ���
void Shop::displayItems() {
	cout << "Items available in the shop:" << endl;
	for (int i = 0; i < items.size(); i++) {
		cout << i + 1 << ". " << items[i]->getName()  // ������ �̸�
			<< " (Price: " << prices[i] << " gold)"  // ������ ����
			<< endl;
	}
}

// ���� �湮 (���� -> �Ǹ� -> ����)
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

	// ���� �������� �״�� �ѱ��� �ʰ� ���� new �ؼ� ����
	Item* original = items[index - 1];
	Item* clonedItem = nullptr;
	if (dynamic_cast<HealthPotion*>(original)) {
		clonedItem = new HealthPotion();
	}
	else if (dynamic_cast<AttackBoost*>(original)) {
		clonedItem = new AttackBoost();
	}
	// �ʿ��� �ٸ� �������� ������ else if �߰�

	if (clonedItem) {
		player->inventory.push_back(clonedItem);

		cout << "You bought " << clonedItem->getName() << " for "
			<< price << " gold." << endl;
		cout << "Remaining gold: " << player->gold << endl;
	}
}

void Shop::sellItem(int index, Character* player) {
	// ��ȿ �ε��� üũ
	if (index < 1 || index > player->inventory.size()) {
		cout << "Invalid item number." << endl;
		return;
	}

	// ���� �Ǹ� ó��
	Item* itemToSell = player->inventory[index - 1];

	// ��: ������ Ÿ��(�̸�)�� ���� �ǸŰ� ����
	int sellPrice = 0;
	if (itemToSell->getName() == "HP potion") {
		sellPrice = 50; // 100���¥�� �������̾��ٰ� ġ�� ������ 50
	}
	else if (itemToSell->getName() == "AD potion") {
		sellPrice = 100; // 200���¥�� �������̾��ٰ� ġ�� ������ 100
	}
	else {
		// �� �ܴ� 0�� Ȥ�� ���� ���
		sellPrice = 0;
	}

	// ��� ���� �� �޽��� ���
	player->gold += sellPrice;
	cout << "You sold " << itemToSell->getName() << " for " << sellPrice << " gold." << endl;
	cout << "Current gold: " << player->gold << endl;

	// �κ��丮���� ���� (���� ������ ������ delete ���δ� ������ ���� ����)
	delete itemToSell;
	player->inventory.erase(player->inventory.begin() + (index - 1));

	// *** ������ prices.erase(...) �̷� �� ���� �ʴ´�! ***
}

