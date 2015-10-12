#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hitPoints, int damage)
	: Unit(name, hitPoints, damage) {
		this->ability = new RogueAbility(this);
		this->unitType = RogueT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
}
Rogue::~Rogue() {
	delete ability;
	delete currentState;
	delete altState;
}

void Rogue::attack(Unit* enemy)  {
	Unit::attack(enemy);
}