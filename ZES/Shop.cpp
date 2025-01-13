#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"

using namespace std;

class Shop {
public:
    vector<Item*> items;
    vector<int> prices;

    // ������ ������ ������ ��ȣ, ȿ����ġ, ��� ����
    Shop::Shop() {
        items.push_back(new HealthPotion(50));  // 0��: ü�� ȸ�� ����, ���� 50 ȸ��
        prices.push_back(100);  // ü�� ȸ�� ���� ����, 100 ���

        items.push_back(new AttackBoost(10));   // 1��: ���ݷ� ���� ������, ���� 10 ����
        prices.push_back(200);  // ���ݷ� ���� ������ ����, 200 ���
    }

    // �������� �Ǹ��ϴ� ������ ��� ���
    void Shop::displayItems() {
        cout << "�������� �Ǹ��ϴ� ������ ���:" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << i << ". " << items[i]->getName()  // ������ �̸�
                << " (����: " << prices[i] << " ���)"  // ������ ����
                << endl;
        }
    }

    //���� �湮 (���� -> �Ǹ� -> ����)
    void Shop::buyItem(int index, Character* player) {
        if (index >= 0 && index < items.size()) {
            int price = prices[index];
            if (player->gold >= price) {
                player->gold -= price;
                cout << items[index]->getName() << " �������� �����߽��ϴ�." << endl;
                cout << "���� ���: " << player->gold << endl;
                items[index]->use(player);  // ������ ���
            }
            else {
                cout << "��尡 �����մϴ�. ������ �� �����ϴ�." << endl;
            }
        }
        else {
            cout << "�߸��� ������ ��ȣ�Դϴ�." << endl;
        }
    }

    void Shop::sellItem(int index, Character* player) {
        if (index >= 0 && index < items.size()) {
            int price = prices[index] / 2;  // �Ǹ� �ݾ��� ���� ������ ����
            player->gold += price;
            cout << items[index]->getName() << " �������� �Ǹ��߽��ϴ�." << endl;
            cout << "�Ǹ� �ݾ�: " << price << " ���" << endl;
            cout << "���� ���: " << player->gold << endl;

            // �Ǹ��� ������ ����
            delete items[index];
            items.erase(items.begin() + index);
            prices.erase(prices.begin() + index);
        }
        else {
            cout << "�߸��� ������ ��ȣ�Դϴ�." << endl;
        }
    }
