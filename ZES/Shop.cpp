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


			break;

		case 2:
			if (player.inventory.empty()) {

				cout << "Your inventory is empty. Nothing to sell!" << endl;

				gm.buffer();
				gm.ClearConsole();
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
					cout << "Cancelled selling items." << endl;
					gm.buffer();
					gm.ClearConsole();
				}
				else {
					gm.ClearConsole();
					sellItem(sellIndex, &player);
					gm.buffer();
					gm.ClearConsole();
				}
			}


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
	if (index >= 1 && index <= items.size()) {
		int price = prices[index - 1];
		if (player->gold >= price) {
			player->gold -= price;
			cout << "You bought " << items[index - 1]->getName() << " from the shop." << endl;
			cout << "Remaining gold: " << player->gold << endl;

			// �������� ĳ���� �κ��丮 ���Ϳ� 'push_back()'���� �߰� - push_back()�� ������ ���� ��Ҹ� �߰��ϴ� �Լ�
			player->inventory.push_back(items[index - 1]);

			// ������ ���
			items[index - 1]->use(player);
		}
		else {
			gm.ClearConsole();
			cout << "Not enough gold to make the purchase." << endl;
			gm.buffer();
			gm.ClearConsole();
		}
	}
	else {
		gm.ClearConsole();
		cout << "Invalid item number." << endl;
		gm.buffer();
		gm.ClearConsole();
	}
}

void Shop::sellItem(int index, Character* player) {
	if (index >= 1 && index <= player->inventory.size()) {
		int price = prices[index - 1] / 2;  // �Ǹ� �ݾ��� ���� ������ ����
		player->gold += price;
		cout << "You sold " << player->inventory[index - 1]->getName() << " from your inventory." << endl;
		cout << "Selling price: " << price << " gold" << endl;
		cout << "Current gold: " << player->gold << endl;

		// �Ǹ��� ������ ����
		delete player->inventory[index - 1];
		player->inventory.erase(player->inventory.begin() + index - 1);

		// ������ ���� ������ ����
		prices.erase(prices.begin() + index - 1);
	}
	else {
		cout << "Invalid item number." << endl;
	}
}

