#include "State.h"

State::State(Unit* actionUnit) {
	this->actionUnit = actionUnit;
	this->hitPointsLimit = actionUnit->getHitPointsLimit();
	this->damage = actionUnit->getDamage();
}
State::~State() {}
const std::string& State::getName() const {
	return name;
}
const int State::getHitPointsLimit() const {
	return hitPointsLimit;
}
const int State::getDamage() const {
	return damage;
}
void State::takeMagicDamage(int dmg) {
	int hitPoints = actionUnit->getHitPoints();

	if ( dmg > hitPoints ) {
		actionUnit->setHitPoints(0);
		return;
	}
	actionUnit->setHitPoints( hitPoints -= dmg);
}