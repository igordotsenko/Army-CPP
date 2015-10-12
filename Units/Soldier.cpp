#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hitPoints, int damage)
	: Unit(name, hitPoints, damage) {
		this->ability = new DefaultAbility(this);
		this->unitType = SoldierT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
}
Soldier::~Soldier() {
	delete ability;
	delete currentState;
	delete altState;
}
