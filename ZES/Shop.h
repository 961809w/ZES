#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"
#include "Character.h"

class Shop {
public:
    // ������ ������ ��ϰ� ���� ���
    std::vector<Item*> items;
    std::vector<int> prices;

    // ���� ������: �����۰� ������ ����
    Shop();

    // �������� �Ǹ��ϴ� ������ ����� ���
    void displayItems();

    // �������� �������� �����ϴ� �Լ�
    void buyItem(int index, Character* player);

    // �������� �������� �Ǹ��ϴ� �Լ�
    void sellItem(int index, Character* player);
};

#endif // SHOP_H
