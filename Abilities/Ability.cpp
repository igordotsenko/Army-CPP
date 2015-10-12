#include "Ability.h"

Ability::Ability(Unit* actionUnit): actionUnit(actionUnit) {}
Ability::~Ability() {}
void Ability::attack(Unit* enemy) {
	enemy->Unit::takeDamage(actionUnit->getDamage());
	enemy->Unit::counterAttack(actionUnit);
}
void Ability::takeMagicDamage(int dmg) {
	actionUnit->getCurrentState()->takeMagicDamage(dmg);
}
void Ability::counterAttack(Unit* enemy) {
	actionUnit->takeDamage(enemy->getDamage() / 2);
}
void Ability::castSpell(Unit* target, Spell* spell) {}
void Ability::changeState() {}
