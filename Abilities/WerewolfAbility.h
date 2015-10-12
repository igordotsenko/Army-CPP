#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include <cstdlib>
#include "../Units/Unit.h"
#include "Ability.h"
#include "../States/WolfState.h"
// #include "../States/State.h"

class WerewolfAbility : public Ability {
	public:
		WerewolfAbility(Unit* enemy);
		virtual ~WerewolfAbility();

		virtual void attack(Unit* actionUnit);
		void infect(Unit* victim);
		virtual void changeState();
};

#endif // WEREWOLF_ABILITY_H