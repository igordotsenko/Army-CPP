#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../Abilities/PriestAbility.h"
#include "../States/DefaultState.h"

class Priest : public SpellCaster {
	public:
		Priest(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~Priest();
};

#endif // PRIEST_H