#include "Priest.h"

Priest::Priest(const std::string& name, int hitPoints, int damage, int manaPoints)
	: SpellCaster(name, hitPoints, manaPoints, damage) {
		ability = new PriestAbility(this);
		activeSpell = spellBook["HEAL"];
		this->unitType = PriestT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Priest::~Priest() {
	delete ability;
	delete currentState;
	delete altState;
}