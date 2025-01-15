#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"
#include "Character.h"

class Shop {
public:
	// ���� ������ ���, ������ ��� ����
	std::vector<Item*> items;
	std::vector<int> prices;

	// ���� ������
	Shop();

	// �������� �Ǹ��ϴ� ������ ��� ���
	void displayItems();

	// ������ ����
	void buyItem(int index, Character* player);

	// ������ �Ǹ�
	void sellItem(int index, Character* player);

	// ���� ����
	void enter(Character& player);

};

#endif // SHOP_H

