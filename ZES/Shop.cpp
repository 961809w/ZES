#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"

using namespace std;

// ���� ����
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
        cout << i << ". " << items[i]->getName()  // ������ �̸�
            << " (Price: " << prices[i] << " gold)"  // ������ ����
            << endl;
    }
}

// ���� �湮 (���� -> �Ǹ� -> ����)
void Shop::buyItem(int index, Character* player) {
    if (index >= 0 && index < items.size()) {
        int price = prices[index];
        if (player->gold >= price) {
            player->gold -= price;
            cout << "You bought " << items[index]->getName() << " from the shop." << endl;
            cout << "Remaining gold: " << player->gold << endl;

            // �������� ĳ���� �κ��丮 ���Ϳ� 'push_back()'���� �߰� - push_back()�� ������ ���� ��Ҹ� �߰��ϴ� �Լ�
            player->inventory.push_back(items[index]);

            // ������ ���
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
        int price = prices[index] / 2;  // �Ǹ� �ݾ��� ���� ������ ����
        player->gold += price;
        cout << "You sold " << player->inventory[index]->getName() << " from your inventory." << endl;
        cout << "Selling price: " << price << " gold" << endl;
        cout << "Current gold: " << player->gold << endl;

        // �Ǹ��� ������ ����
        delete player->inventory[index];
        player->inventory.erase(player->inventory.begin() + index);

        // ������ ���� ������ ����
        prices.erase(prices.begin() + index);
    }
    else {
        cout << "Invalid item number." << endl;
    }
}

