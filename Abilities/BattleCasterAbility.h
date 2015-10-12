#ifndef BATTLE_CASTER_ABILITY_H
#define BATTLE_CASTER_ABILITY_H

#include "Ability.h"
#include "../Units/Unit.h"
#include "../Spells/Spell.h"

class BattleCasterAbility : public Ability {
	Unit* actionUnit;
	public:
		BattleCasterAbility(Unit* actionUnit);
		virtual ~BattleCasterAbility();

		virtual void castSpell(Unit* target, Spell* spell);
};

#endif // BATTLE_CASTER_ABILITY_H