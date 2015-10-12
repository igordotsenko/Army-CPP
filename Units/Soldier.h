#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../Abilities/DefaultAbility.h"
#include "../States/DefaultState.h"

class Soldier : public Unit {
	public:
		Soldier(const std::string& name, int hitPoints, int damage);
		virtual ~Soldier();
};

#endif // SOLDIER_H