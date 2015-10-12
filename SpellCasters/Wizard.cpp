#include "Wizard.h"

Wizard::Wizard(const std::string& name, int hitPoints, int damage, int manaPoints)
	: SpellCaster(name, hitPoints, manaPoints, damage) {
		ability = new BattleCasterAbility(this);
		activeSpell = spellBook["FIREBALL"];
		this->unitType = WizardT;
		currentState = new DefaultState(this);
		altState = new DefaultState(this);
	}
Wizard::~Wizard() {}
