#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../Abilities/BerserkerAbility.h"
#include "../States/DefaultState.h"

class Berserker : public Unit {
	public:
		Berserker(const std::string& name, int hitPoints, int damage);
		virtual ~Berserker();

		virtual void takeMagicDamage(int dmg);
};

#endif // BERSERKER_H