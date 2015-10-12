#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "Observer.h"
#include "Observable.h"
#include "../exceptions.h"
#include "../Abilities/Ability.h"

class Ability;
class State;

enum UnitType {
	SoldierT,
	RogueT,
	BerserkerT,
	VampireT,
	WerewolfT,
	WizardT,
	HealerT,
	PriestT,
	WarlockT,
	NecromancerT,
	DemonT
};

class Unit : public Observer, public Observable {
	protected:
		std::string name;
		int hitPoints;
		int hitPointsLimit;
		int damage;
		int unitType;
		bool undead;
		Ability* ability;
		State* currentState;
		State* altState;

		virtual void ensureIsAlive();
		virtual void ensureIsNotSelfAttack(Unit* enemy);

	public:
		Unit(const std::string& name, int hitPoints, int damage);
		virtual ~Unit() = 0;

		virtual const std::string& getName() const;
		virtual int getHitPoints() const;
		virtual int getHitPointsLimit() const;
		virtual int getDamage() const;
		virtual const int getUnitType() const;
		virtual bool isUndead() const;
		virtual const std::set<Observer*>& getObservers() const;
		virtual const std::set<Observable*>& getObservables() const;
		virtual State* getCurrentState() const;
		virtual State* getAltState() const;

		virtual void setName(const std::string& newName);
		virtual void setHitPoints(int newHitPoints);
		virtual void setHitPointsLimit(int newHitPointsLimit);
		virtual void setDamage(int newDamage);
		virtual void setUnitType(enum UnitType unitType);
		virtual void setIsUndead();
		virtual void setCurrentState(State* newCurrentState);
		virtual void setAltState(State* newAltState);

		virtual void changeAbility(Ability* newAbility);

		virtual void attack(Unit* enemy);
		virtual void counterAttack(Unit* enemy);

		virtual void takeDamage(int dmg);
		virtual void takeMagicDamage(int dmg);
		virtual void heal(int healPoints);
		virtual void addHitPoints(int hitPoints);

		virtual void notifyObservers();
		virtual void notifyObservables();

		virtual void transform();
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
