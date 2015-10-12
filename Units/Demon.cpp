#include "Demon.h"

Demon::Demon(Warlock* master) 
	: Soldier("Demon", 100, 10) {
	this->master = master;
	this->id = lastId;
	this->unitType = DemonT;
	lastId += 1;
}
Demon::~Demon() {
	lastId -= 1;
}

void Demon::attack(Unit* enemy) {
	ensureIsAlive();
	ensureIsNotSelfAttack(enemy);
	ensureIsNotMaster(enemy);
	ability->attack(enemy);
}

void Demon::ensureIsNotMaster(Unit* enemy) {
	if ( enemy == (Unit*)master ) {
		throw MasterAttackException();
	}
}

int Demon::lastId = 1;