#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../Abilities/HealerAbility.h"
#include "../States/DefaultState.h"

class Healer : public SpellCaster {
	public:
		Healer(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~Healer();
};

#endif // HEALER_H