#ifndef ROGUE_ABILITY_H
#define ROGUE_ABILITY_H

#include "Ability.h"
#include "../Units/Unit.h"

class RogueAbility : public Ability {
	public:
		RogueAbility(Unit* actionUnit);
		virtual ~RogueAbility();

		virtual void attack(Unit* enemy);
};

#endif // ROGUE_ABILITY_H