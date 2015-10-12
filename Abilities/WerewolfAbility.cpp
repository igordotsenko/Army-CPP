#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* actionUnit) 
	: Ability(actionUnit) {}
WerewolfAbility::~WerewolfAbility() {}

void WerewolfAbility::attack(Unit* enemy) {
	enemy->takeDamage(actionUnit->getDamage());
	if ( std::rand() % 5 == 0 ) {
		infect(enemy);
		return;
	}
	enemy->counterAttack(actionUnit);
}
void WerewolfAbility::infect(Unit* victim) {
	if (victim->getUnitType() == VampireT || victim->getUnitType() == WerewolfT ) {
		return;
	}
	std::cout << victim->getName() << " is infected by " << actionUnit->getName() << std::endl;
	victim->changeAbility(new WerewolfAbility(victim));
	delete victim->getAltState();
	victim->setAltState(new WolfState(victim));
	victim->setUnitType(WerewolfT);
}
void WerewolfAbility::changeState() {
	State* currentState = actionUnit->getCurrentState();
	State* altState = actionUnit->getAltState();
	State* temp = currentState;
	int newHitPoints;
	double coef = (double)actionUnit->getHitPoints() / (double)currentState->getHitPointsLimit();

	actionUnit->setCurrentState(altState);
	actionUnit->setAltState(temp);
	currentState = altState;

	newHitPoints = (int)(coef * (double)currentState->getHitPointsLimit());
	
	actionUnit->setHitPoints(newHitPoints);
	actionUnit->setHitPointsLimit(currentState->getHitPointsLimit());
	actionUnit->setDamage(currentState->getDamage());
}
