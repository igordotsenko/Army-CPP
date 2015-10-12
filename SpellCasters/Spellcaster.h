#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include <string>
#include <map>
#include "../Abilities/BattleCasterAbility.h"
#include "../Units/Unit.h"
#include "../Spells/Fireball.h"
#include "../Spells/Heal.h"
#include "../Exceptions.h"

class Spell;

class SpellCaster : public Unit {
	protected:
		int manaPoints;
		int manaPointsLimit;
		std::map<std::string, Spell*> spellBook;
		Spell* activeSpell;

	public:
		SpellCaster(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~SpellCaster() = 0;

		virtual int getManaPoints() const;
		virtual int getManaPointsLimit() const;
		virtual Spell* getActiveSpell() const;

		virtual void addManaPoints(int manaPoints);

		virtual void castSpell(Unit* target);
		virtual void changeSpell(const std::string& newActiveSpell);
		virtual void addSpell(Spell* newSpell);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sc);

#endif // SPELLCASTER_H
