#ifndef DEFAULT_ABILITY_H
#define DEFAULT_ABILITY_H

#include "Ability.h"
#include "../States/DefaultState.h"


class DefaultAbility : public Ability {
	public:
		DefaultAbility(Unit* actionUnit);
		virtual ~DefaultAbility();
};

#endif // DEFAULT_ABILITY_H
