#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../Units/Demon.h"
#include "../Abilities/BattleCasterAbility.h"
#include "../Exceptions.h"
#include "../States/DefaultState.h"

class Warlock : public SpellCaster {
	protected:
		Demon* slave;
	public:
		static int demonCost; 

		Warlock(const std::string& name, int hitPoints, int damage, int manaPoints);
		virtual ~Warlock();

		virtual Demon* getSlave() const;

		virtual Demon* summonSlave();
		virtual void freeSlave();
};

std::ostream& operator<<(std::ostream& out, const Warlock& wrlk);

#endif // WARLOCK_H