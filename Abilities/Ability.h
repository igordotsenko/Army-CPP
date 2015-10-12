#ifndef ABILITY_H
#define ABILITY_H

#include "../Units/Unit.h"
#include "../States/State.h"

class Unit;
class Spell;

class Ability {
	protected:
		Unit* actionUnit;
	public:
		Ability(Unit* actionUnit);
		virtual ~Ability() = 0;

		virtual void attack(Unit* actionUnit);
		virtual void counterAttack(Unit* actionUnit);
		virtual void takeMagicDamage(int dmg);
		virtual void castSpell(Unit* target, Spell* spell);
		virtual void changeState();
};

#endif // ABILITY_H
