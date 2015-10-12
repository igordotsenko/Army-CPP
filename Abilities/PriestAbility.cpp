#include "PriestAbility.h"

PriestAbility::PriestAbility(Unit* actionUnit) 
	: Ability(actionUnit) {
}
PriestAbility::~PriestAbility() {}

void PriestAbility::castSpell(Unit* target, Spell* spell) {
	if ( spell->isBattleSpell() ) {
		if ( target->isUndead() ) {
			target->takeMagicDamage(spell->getActionPoints());
			return;
		}
		target->takeMagicDamage(spell->getActionPoints()/2);
		return;
	}
	if ( target->isUndead() ) {
		return;
	}
	target->heal(spell->getActionPoints());
}