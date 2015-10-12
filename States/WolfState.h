#ifndef WOLFSTATE_H
#define WOLFSTATE_H

#include "State.h"

class Unit;

class WolfState : public State {
	public:
		WolfState(Unit* actionUnit);
		virtual ~WolfState();

		virtual void takeMagicDamage(int dmg);
};

#endif // WOLFSTATE_H