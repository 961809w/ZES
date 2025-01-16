#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"
#include "Character.h"

class Shop {
public:
	// 상점 아이템 목록, 가격을 담는 벡터
	std::vector<Item*> items;
	std::vector<int> prices;

	// 상점 생성자
	Shop();

	// 상점에서 판매하는 아이템 목록 출력
	void displayItems();

	// 아이템 구매
	void buyItem(int index, Character* player);

	// 아이템 판매
	void sellItem(int index, Character* player);

	// 상점 입장
	void enter(Character& player);

};

#endif // SHOP_H

