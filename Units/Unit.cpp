#include "Unit.h"

void Unit::ensureIsAlive() {
	if ( hitPoints == 0 ) {
		throw UnitIsDeadException{};
	}
}
void Unit::ensureIsNotSelfAttack(Unit* enemy) {
	if ( this == enemy ) {
		throw SelfAttackException();
	}
}
Unit::Unit(const std::string& name, int hitPoints, int damage): hitPoints(hitPoints), hitPointsLimit(hitPoints), damage(damage) {
	this->name = name;
	this->undead = false;
}
Unit::~Unit() {}
const std::string& Unit::getName() const {
	return name;
}
int Unit::getHitPoints() const {
	return hitPoints;
}
int Unit::getHitPointsLimit() const {
	return hitPointsLimit;
}
int Unit::getDamage() const {
	return damage;
}

const int Unit::getUnitType() const {
	return unitType;
}

bool Unit::isUndead() const {
	return undead;
}
const std::set<Observer*>& Unit::getObservers() const {
	return observers;
}
const std::set<Observable*>& Unit::getObservables() const {
	return observables;
}
State* Unit::getCurrentState() const {
	return currentState;
}
State* Unit::getAltState() const {
	return altState;
}
void Unit::setName(const std::string& newName) {

	name = newName;
}
void Unit::setHitPoints(int newHitPoints) {
	hitPoints = newHitPoints;
}
void Unit::setHitPointsLimit(int newHitPointsLimit) {
	hitPointsLimit = newHitPointsLimit;
}
void Unit::setDamage(int newDamage) {
	damage = newDamage;
}

void Unit::setUnitType(enum UnitType unitType) {
	this->unitType = unitType;
}

void Unit::setIsUndead() {
	undead = !undead;
}
void Unit::setCurrentState(State* newCurrentState) {
	this->currentState = newCurrentState;
}
void Unit::setAltState(State* newAltState) {
	this->altState = newAltState;
}

void Unit::changeAbility(Ability* newAbility) {
	delete ability;
	ability = newAbility;
}
void Unit::attack(Unit* enemy) {
	ensureIsAlive();
	ensureIsNotSelfAttack(enemy);
	ability->attack(enemy);
}
void Unit::counterAttack(Unit* enemy) {
	try {
		ensureIsAlive();
	} catch ( UnitIsDeadException ) {
		return;
	}
	enemy->ability->counterAttack(this);
}
void Unit::takeDamage(int dmg) {
	if ( dmg > hitPoints) {
		hitPoints = 0;
		notifyObservers();
		notifyObservables();
		return;
	}
	hitPoints -= dmg;
}
void Unit::takeMagicDamage(int dmg) {
	ability->takeMagicDamage(dmg);
}

void Unit::heal(int healPoints) {
	ensureIsAlive();

	int newHitPoints = hitPoints + healPoints;

	if ( newHitPoints > hitPointsLimit) {
		hitPoints = hitPointsLimit;
		return;
	}
	hitPoints = newHitPoints;
}
void Unit::addHitPoints(int hitPoints) {
	ensureIsAlive();

	int newHitPoints = this->hitPoints + hitPoints;

	if ( newHitPoints > hitPointsLimit) {
		this->hitPoints = hitPointsLimit;
		return;
	}
	this->hitPoints = newHitPoints;
}
void Unit::notifyObservers() {
	std::set<Observer*>::iterator it = observers.begin();

	for ( ; it != observers.end(); it++ ) {
		((Unit*)(*it))->addHitPoints(((Unit*)(*it))->getHitPointsLimit()/10);
		(*it)->removeObservable(this);
	}
	observers.clear();
}
void Unit::notifyObservables() {
	std::set<Observable*>::iterator it = observables.begin();

	for ( ; it != observables.end(); it++ ) {
		(*it)->removeObserver(this);
	}
}
void Unit::transform() {
	ability->changeState();
}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
	out << unit.getName() << " ";
	if ( unit.getUnitType() == WerewolfT ) {
		out << unit.getCurrentState()->getName();
	}
	out << ": ";
	if ( unit.getHitPoints() == 0 ) {
		out << "is dead";
		return out;
	}
	out << "hp(" << unit.getHitPoints() << "/" << unit.getHitPointsLimit() << "), dmg(" << unit.getDamage() << ")";

	if ( !unit.getObservers().empty() ) {
		std::set<Observer*>::iterator observersIt;

		out << ", observers: [ ";
		for ( observersIt = unit.getObservers().begin() ; observersIt != unit.getObservers().end(); observersIt++ ){
			out << ((Unit*)(*observersIt))->getName() << " ";
		}
		out << "]";
	}

	if ( !unit.getObservables().empty() ) {
		std::set<Observable*>::iterator observablesIt;

		out << ", observables: [ ";
		for ( observablesIt = unit.getObservables().begin() ; observablesIt != unit.getObservables().end(); observablesIt++ ) {
			out << ((Unit*)(*observablesIt))->getName() << " ";
		}
		out << "]";
	}

	return out;
}
