#include "Player.h"

void Player::Create(std::unique_ptr<Npc> npc) {
    character = std::move(npc);
    if (character) character->GetInfo();
}

Npc* Player::GetCurrentCharacter() {
    return character.get();
}
