#ifndef DEMON_H
#define DEMON_H

#include "Unit.h"
#include "Soldier.h"
#include "../Exceptions.h"
#include "../States/DefaultState.h"

class Warlock;

class Demon : public Soldier {
	protected:
		Warlock* master;
		int id;

	public:
		static int lastId;

		Demon(Warlock* master);
		virtual ~Demon();

		virtual void attack(Unit* enemy);
		virtual void ensureIsNotMaster(Unit* enemy);
};

#endif // DEMON_H