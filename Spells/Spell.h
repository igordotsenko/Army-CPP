#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../Units/Unit.h"

class BattleCaster;
class SpellCaster;

class Spell {
	protected:
		std::string name;
		int actionPoints;
		int cost;
		bool battleSpell;

	public:
		Spell();
		virtual ~Spell() = 0;

		virtual const std::string& getName() const;
		virtual int getActionPoints();
		virtual int getCost();
		virtual bool isBattleSpell();
};

#endif // SPELL_H