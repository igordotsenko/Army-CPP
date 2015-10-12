#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* actionUnit)
	: Ability::Ability(actionUnit) {}
RogueAbility::~RogueAbility() {}

void RogueAbility::attack(Unit* enemy) {
	enemy->Unit::takeDamage(actionUnit->getDamage());
}