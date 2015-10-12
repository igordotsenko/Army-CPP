#include "WolfState.h"

WolfState::WolfState(Unit* actionUnit)
	: State(actionUnit) {
		this->name = "(Wolf state)";
		this->hitPointsLimit = actionUnit->getHitPointsLimit() * 2;
		this->damage = actionUnit->getDamage() * 2;
	}
WolfState::~WolfState() {}
void WolfState::takeMagicDamage(int dmg) {
	int hitPoints = actionUnit->getHitPoints();
	int newDmg = dmg * 2;

	if ( newDmg > hitPoints ) {
		actionUnit->setHitPoints(0);
		return;
	}
	actionUnit->setHitPoints( hitPoints -= newDmg);
}
