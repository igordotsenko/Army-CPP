#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../Abilities/BattleCasterAbility.h"
#include "../States/DefaultState.h"

class Wizard : public SpellCaster {
	public:
		Wizard(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~Wizard();
};

#endif // WIZARD_H