#include "Character.h"
#include "Monster.h"
#include "item.h"
#include <vector>

class GameManager {
public:
    // 몬스터 생성
    Monster* generateMonster();

    // 배틀 로직
    void battle(Character* player);

    // 몬스터와 상호작용 로직 
    void handleMonsterInteraction(Monster* monster, Character* player);

    // + 아래 추가적인 요소들

    // 플레이어의 인벤토리(아이템 리스트) 표시
    // 아이템 개수는 게임중 계속 바뀌므로 동적배열 Vector 사용
    // const는 인벤토리 리스트의 원본을 수정하지 못하도록 보정
    void displayInventory(const vector<Item*>& inventory);


    // 게임 초기화
    void initializeGame();

    // 게임 종료
    void endGame();

    // 플레이어 상태 표시
    void displayPlayerStatus(Character* player);


private:
    // 필요한 경우 추가적인 멤버 변수를 선언
};

#endif // GAMEMANAGER_H
