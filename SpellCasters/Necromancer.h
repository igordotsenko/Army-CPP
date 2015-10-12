#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../States/DefaultState.h"

class Necromancer : public SpellCaster {
	public:
		Necromancer(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~Necromancer();
		
		virtual void changeAbility(Ability* newAbility);
		
		virtual void heal(int healPoints);
		virtual void castSpell(Unit* target);
};


#endif // NECROMANCER_H