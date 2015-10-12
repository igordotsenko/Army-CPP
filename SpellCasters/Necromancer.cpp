#include "Necromancer.h"


Necromancer::Necromancer(const std::string& name, int hitPoints, int damage, int manaPoints)
	: SpellCaster(name, hitPoints, manaPoints, damage) {
		activeSpell = spellBook["FIREBALL"];
		undead = true;
		this->unitType = NecromancerT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Necromancer::~Necromancer() {
	delete ability;
	delete currentState;
	delete altState;
}
void Necromancer::changeAbility(Ability* newAbility) {
	notifyObservables();
	Unit::changeAbility(newAbility);
	observables.clear();
}
void Necromancer::heal(int healPoints) {}
void Necromancer::castSpell(Unit* target) {
	SpellCaster::castSpell(target);
	addObservable(target);
}