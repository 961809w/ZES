#include "Character.h"
#include "Item.h"
#include "GameManager.h"
#include "Monster.h"

int main() {
    Character player("ZEZE");
    player.displayStatus();

    player.addItem(std::make_shared<HealthPotion>(50));
    player.addItem(std::make_shared<AttackBoost>(10));

    auto monster = GameManager::generateMonster(1);
    GameManager::battle(player, monster);

    player.displayStatus();
    return 0;
}