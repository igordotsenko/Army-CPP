#include "BattleCasterAbility.h"

BattleCasterAbility::BattleCasterAbility(Unit* actionUnit) 
	: Ability(actionUnit) {}
BattleCasterAbility::~BattleCasterAbility() {}

void BattleCasterAbility::castSpell(Unit* target, Spell* spell) {
	if ( spell->isBattleSpell() ) {
		target->takeMagicDamage(spell->getActionPoints());
		return;
	}
	if ( target->isUndead() ) {
		return;
	}
	target->heal(spell->getActionPoints()/2);
}