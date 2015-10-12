#include "Warlock.h"

Warlock::Warlock(const std::string& name, int hitPoints, int damage, int manaPoints)
	: SpellCaster(name, hitPoints, manaPoints, damage) {
		ability = new BattleCasterAbility(this);
		activeSpell = spellBook["FIREBALL"];
		slave = NULL;
		this->unitType = WarlockT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Warlock::~Warlock() {
	if (slave != NULL ) {
		delete slave;
	}
	delete ability;
	delete currentState;
	delete altState;

}
Demon* Warlock::getSlave() const {
	return slave;
}
Demon* Warlock::summonSlave() {
	if ( slave != NULL ) {
		throw SlaveAlreadySummonedException();
	}
	if ( manaPoints < demonCost ) {
		throw NotEnoughManaException();
	}
	slave = new Demon(this);
	manaPoints -= demonCost;
	return slave;
}
void Warlock::freeSlave() {
	if (slave != NULL ) {
		delete slave;
	}
	slave = NULL;
}
std::ostream& operator<<(std::ostream& out, const Warlock& wrlk) {
	out << *((SpellCaster*)&wrlk);
	if ( wrlk.getSlave() != NULL ) {
		out << ", has slave";
	}

	return out;
}

int Warlock::demonCost = 20;
