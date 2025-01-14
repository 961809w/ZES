#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"

using namespace std;

class Shop {
public:
    vector<Item*> items;
    vector<int> prices;

    // 상점에 아이템 종류별 번호, 효과수치, 골드 설정
    Shop::Shop() {
        items.push_back(new HealthPotion(50));  // 0번: 체력 회복 포션, 사용시 50 회복
        prices.push_back(100);  // 체력 회복 포션 가격, 100 골드

        items.push_back(new AttackBoost(10));   // 1번: 공격력 증가 아이템, 사용시 10 증가
        prices.push_back(200);  // 공격력 증가 아이템 가격, 200 골드
    }

    // 상점에서 판매하는 아이템 목록 출력
	// items.size()는 items 벡터의 크기, 즉 상점에 판매하는 아이템의 개수를 반환. 현재 판매 개수 2개 이므로 size()는 2.
    // getName()은 각 아이템의 이름을 반환하는 메서드
    void Shop::displayItems() {
        cout << "상점에서 판매하는 아이템 목록:" << endl;
		for (int i = 0; i < items.size(); i++) // i는 아이템의 인덱스를 나타내며, 0부터 시작하여 items.size() 보다 작은값까지 반복. 현재 size는 2이므로 0, 1번째 아이템 출력.
        {
            cout << i << ". " << items[i]->getName()  // i 번째 아이템 이름 출력
                << " (가격: " << prices[i] << " 골드)"  // i 번째 아이템 가격 출력
                << endl;
        }
    }

    //상점 방문 (구매 -> 판매 -> 종료)
    void Shop::buyItem(int index, Character* player) {
        if (index >= 0 && index < items.size()) {
            int price = prices[index];
            if (player->gold >= price) {
                player->gold -= price;
                cout << items[index]->getName() << " 아이템을 구매했습니다." << endl;
                cout << "남은 골드: " << player->gold << endl;
                items[index]->use(player);  // 아이템 사용
            }
            else {
                cout << "골드가 부족합니다. 구매할 수 없습니다." << endl;
            }
        }
        else {
            cout << "잘못된 아이템 번호입니다." << endl;
        }
    }

    
    void Shop::sellItem(int index, Character* player) {
        if (index >= 0 && index < player->inventory.size()) {
            int price = prices[index] / 2;  // 판매 금액은 원래 가격의 절반
            player->gold += price;
            cout << player->inventory[index]->getName() << " 아이템을 인벤토리에서 판매했습니다." << endl;
            cout << "판매 금액: " << price << " 골드" << endl;
            cout << "현재 골드: " << player->gold << endl;

            // 판매한 아이템 제거
            delete  player->inventory[index];
            player->inventory.erase(player->inventory.begin() + index);
            prices.erase(prices.begin() + index);
        }
        else {
            cout << "잘못된 아이템 번호입니다." << endl;
        }
    }