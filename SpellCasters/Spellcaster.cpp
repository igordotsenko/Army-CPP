#include "Spellcaster.h"

SpellCaster::SpellCaster(const std::string& name, int hitPoints, int damage, int manaPoints)
	: Unit(name, hitPoints, damage) {
		this->manaPoints = manaPoints;
		this->manaPointsLimit = manaPoints;
		ability = new BattleCasterAbility(this);
		addSpell(new Fireball());
		addSpell(new Heal());
}
SpellCaster::~SpellCaster() {
	std::map<std::string, Spell*>::iterator it = spellBook.begin();

	for (; it != spellBook.end(); it++ ) { 
		delete it->second;
	}
	spellBook.erase(spellBook.begin(), spellBook.end());
}

int SpellCaster::getManaPoints() const {
	return manaPoints;
}
int SpellCaster::getManaPointsLimit() const {
	return manaPointsLimit;
}
Spell* SpellCaster::getActiveSpell() const {
	return activeSpell;
}
void SpellCaster::addManaPoints(int manaPoints) {
	int newManaPoints = this->manaPoints + manaPoints;

	if ( newManaPoints >= manaPointsLimit ) {
		this->manaPoints = manaPointsLimit;
		return;
	}

	this->manaPoints = newManaPoints;
}
void SpellCaster::castSpell(Unit* target) {
	ensureIsAlive();
	if ( manaPoints < activeSpell-> getCost() ) {
		throw NotEnoughManaException();
	}
	ability->castSpell(target, activeSpell);
	manaPoints -= activeSpell->getCost();
}
void SpellCaster::changeSpell(const std::string& newActiveSpell) {
	activeSpell = spellBook[newActiveSpell];
}
void SpellCaster::addSpell(Spell* newSpell) {
	spellBook[newSpell->getName()] = newSpell;
}
std::ostream& operator<<(std::ostream& out, const SpellCaster& sc) {
	out << *((Unit*)(&sc));
	if ( sc.getHitPoints() == 0 ) {
		return out;
	}
	out << ", mana(" << sc.getManaPoints() << "/" << sc.getManaPointsLimit() << ")";
	out << ", active spell is " << sc.getActiveSpell()->getName();

	return out;
}
