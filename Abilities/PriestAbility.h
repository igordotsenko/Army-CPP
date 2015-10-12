#ifndef PRIEST_ABILITY_H
#define PRIEST_ABILITY_H

#include "Ability.h"
#include "../Units/Unit.h"
#include "../Spells/Spell.h"

class PriestAbility : public Ability {
	Unit* actionUnit;
	public:
		PriestAbility(Unit* actionUnit);
		virtual ~PriestAbility();

		virtual void castSpell(Unit* target, Spell* spell);
};

#endif // PRIEST_ABILITY_H