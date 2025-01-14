#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"
#include "Character.h"

class Shop {
public:
    // 상점의 아이템 목록과 가격 목록
    std::vector<Item*> items;
    std::vector<int> prices;

    // 상점 생성자: 아이템과 가격을 설정
    Shop();

    // 상점에서 판매하는 아이템 목록을 출력
    void displayItems();

    // 상점에서 아이템을 구매하는 함수
    void buyItem(int index, Character* player);

    // 상점에서 아이템을 판매하는 함수
    void sellItem(int index, Character* player);
};

#endif // SHOP_H
