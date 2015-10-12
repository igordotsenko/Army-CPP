#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hitPoints, int damage)
	: Unit(name, hitPoints, damage) {
		this->ability = new WerewolfAbility(this);
		this->unitType = WerewolfT;
		currentState = new DefaultState(this);
		altState = new WolfState(this);
}
Werewolf::~Werewolf() {
	delete ability;
	delete currentState;
	delete altState;
}
