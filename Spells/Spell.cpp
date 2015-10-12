#include "Spell.h"

Spell::Spell() {}
Spell::~Spell() {}

const std::string& Spell::getName() const {
	return name;
}
int Spell::getActionPoints() {
	return actionPoints;
}
int Spell::getCost() {
	return cost;
}
bool Spell::isBattleSpell() {
	return battleSpell;
}
