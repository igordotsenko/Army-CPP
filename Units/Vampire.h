#ifndef VAMPRIRE_H
#define VAMPRIRE_H

#include "Unit.h"
#include "../Abilities/VampireAbility.h"
#include "../States/DefaultState.h"

class Vampire : public Unit {
	public:
		Vampire(const std::string& name, int hitPoints, int damage);
		virtual ~Vampire();

		virtual void heal(int healPoints);
};

#endif // VAMPRIRE_H