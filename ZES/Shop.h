#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Item.h"

class Shop {
public:
    // 생성자
    Shop();

    // 아이템 목록 출력
    void displayItems();

    // 아이템 구매
    void buyItem(int index, Character* player);

    // 아이템 판매
    void sellItem(int index, Character* player);

private:
    std::vector<Item*> items;   // 상점에서 판매하는 아이템들
    std::vector<int> prices;    // 아이템들의 가격
};

#endif // SHOP_H. 헤더 파일 보호