#include "Healer.h"

Healer::Healer(const std::string& name, int hitPoints, int damage, int manaPoints)
	: SpellCaster(name, hitPoints, manaPoints, damage) {
		ability = new HealerAbility(this);
		activeSpell = spellBook["HEAL"];
		this->unitType = HealerT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Healer::~Healer() {
	delete ability;
	delete currentState;
	delete altState;
}