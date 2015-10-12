#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class BattleCaster;
class SpellCaster;

class Heal : public Spell {
	public:
		Heal();
		virtual ~Heal();
};

#endif // HEAL_H