#ifndef VAMPIRE_ABILITY
#define VAMPIRE_ABILITY

#include <cstdlib>
#include "../Units/Unit.h"
#include "Ability.h"

class VampireAbility : public Ability {
	public:
		VampireAbility(Unit* actionUnit);
		virtual ~VampireAbility();

		virtual void attack(Unit* enemy);
		void drain(Unit* enemy);
		void infect(Unit* victim);
};

#endif // VAMPIRE_ABILITY