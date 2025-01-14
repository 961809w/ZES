#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"

class Shop {
public:
    // ������
    Shop();

    // ������ ��� ���
    void displayItems();

    // ������ ����
    void buyItem(int index, Character* player);

    // ������ �Ǹ�
    void sellItem(int index, Character* player);

private:
    std::vector<Item*> items;   // �������� �Ǹ��ϴ� �����۵�
    std::vector<int> prices;    // �����۵��� ����
};

#endif // SHOP_H. ��� ���� ��ȣ