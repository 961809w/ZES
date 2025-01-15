#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"

using namespace std;

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

