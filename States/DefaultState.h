#ifndef DEFAULT_STATE_H
#define DEFAULT_STATE_H

#include "State.h"

class Unit;

class DefaultState : public State {
	public:
		DefaultState(Unit* actionUnit);
		virtual ~DefaultState();
};

#endif // DEFAULT_STATE_H