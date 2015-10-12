#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../Abilities/WerewolfAbility.h"
#include "../States/DefaultState.h"
#include "../States/WolfState.h"

class Werewolf : public Unit {
	public:
		Werewolf(const std::string& name, int hitPoints, int damage);
		virtual ~Werewolf();
};

#endif // WEREWOLF_H