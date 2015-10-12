#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hitPoints, int damage)
	: Unit(name, hitPoints, damage) {
		ability = new VampireAbility(this);
		this->undead = true;
		this->unitType = VampireT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Vampire::~Vampire() {
	delete ability;
	delete currentState;
	delete altState;
}

void Vampire::heal(int healPoints) {}
