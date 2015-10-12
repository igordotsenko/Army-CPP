#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hitPoints, int damage)
	: Unit(name, hitPoints, damage) {
		ability = new BerserkerAbility(this);
		this->unitType = BerserkerT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Berserker::~Berserker() {
	delete ability;
	delete currentState;
	delete altState;
}
void Berserker::takeMagicDamage(int dmg) {
	ability->takeMagicDamage(dmg);
}