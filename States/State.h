#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Units/Unit.h"

class Unit;

class State {
	protected:
		Unit* actionUnit;
		std::string name;
		int hitPointsLimit;
		int damage;

	public:
		State(Unit* actionUnit);
		virtual ~State() = 0;

		virtual const std::string& getName() const;
		virtual const int getHitPointsLimit() const;
		virtual const int getDamage() const;

		virtual void takeMagicDamage(int dmg);
};


#endif // STATE_H