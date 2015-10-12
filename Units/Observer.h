#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include "Observable.h"

class Observable;

class Observer {
	protected:
		std::set<Observable*> observables;

	public:
		Observer();
		virtual ~Observer() = 0;

		virtual const std::set<Observable*>& getObservables() const;

		virtual void addObservable(Observable* observable);
		virtual void removeObservable(Observable* observable);
};

#endif // OBSERVER_H