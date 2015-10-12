#ifndef BERSERKER_ABILITY_H
#define BERSERKER_ABILITY_H

#include "Ability.h"
#include "../States/DefaultState.h"

class BerserkerAbility : public Ability {
	public:
		BerserkerAbility(Unit* actionUnit);
		virtual ~BerserkerAbility();

		virtual void takeMagicDamage(int dmg);
};

#endif // BERSERKER_ABILITY_H