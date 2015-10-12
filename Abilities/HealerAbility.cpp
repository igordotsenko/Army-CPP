#include "HealerAbility.h"

HealerAbility::HealerAbility(Unit* actionUnit) 
	: Ability(actionUnit) {
}
HealerAbility::~HealerAbility() {}

void HealerAbility::castSpell(Unit* target, Spell* spell) {
	if ( spell->isBattleSpell() ) {
		target->takeMagicDamage(spell->getActionPoints()/2);
		return;
	}
	if ( target->isUndead() ) {
		return;
	}
	target->heal(spell->getActionPoints());
}