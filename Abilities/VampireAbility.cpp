#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* actionUnit)
	: Ability(actionUnit) {}
VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
	drain(enemy);
	enemy->takeDamage(actionUnit->getDamage());
	if ( std::rand() % 5 == 0 ) {
		infect(enemy);
		return;
	}
	enemy->counterAttack(actionUnit);
}
void VampireAbility::drain(Unit* enemy) {
	int newHitPoints = actionUnit->getHitPoints() + enemy->getHitPoints() / 10;

	enemy->takeDamage(enemy->getHitPoints() / 10);
	if ( newHitPoints > actionUnit->getHitPointsLimit() ) {
		int hitPointsLimit = actionUnit->getHitPointsLimit();
		actionUnit->setHitPoints(hitPointsLimit);
		return;
	}
	actionUnit->setHitPoints(newHitPoints);
}
void VampireAbility::infect(Unit* victim) {
	if (victim->getUnitType() == VampireT || victim->getUnitType() == WerewolfT ) {
		return;
	}
	victim->changeAbility(new VampireAbility(victim));
	victim->setUnitType(VampireT);
	victim->setIsUndead();
	std::cout << victim->getName() << " is infected by " << actionUnit->getName() << std::endl;
}