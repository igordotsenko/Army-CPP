#ifndef OBSERVABLES_H
#define OBSERVABLES_H

#include <set>
#include "Observer.h"

class Observer;

class Observable {
	protected:
		std::set<Observer*> observers;
	public:
		Observable();
		virtual ~Observable() = 0;

		virtual void addObserver(Observer* observer);
		virtual void removeObserver(Observer* observer);
};

#endif // OBSERVABLES_H