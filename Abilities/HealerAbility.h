#ifndef HEALER_ABILITY_H
#define HEALER_ABILITY_H

#include "Ability.h"
#include "../Units/Unit.h"
#include "../Spells/Spell.h"

class HealerAbility : public Ability {
	Unit* actionUnit;
	public:
		HealerAbility(Unit* actionUnit);
		virtual ~HealerAbility();

		virtual void castSpell(Unit* target, Spell* spell);
};

#endif // HEALER_ABILITY_H