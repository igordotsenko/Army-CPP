#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../Abilities/DefaultAbility.h"
#include "../Abilities/RogueAbility.h"

class Rogue : public Unit {
	public:
		Rogue(const std::string& name, int hitPoints, int damage);
		virtual ~Rogue();

		virtual void attack(Unit* enemy);
};

#endif // ROGUE_H