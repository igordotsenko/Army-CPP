#include "DefaultState.h"

DefaultState::DefaultState(Unit* actionUnit) 
	: State(actionUnit) {
		this->name = "(Default state)";
	}
DefaultState::~DefaultState() {}
