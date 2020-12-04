#pragma once
#include "Unit.h"
// Warrior unit
// Strong against archers
// Weak against mages
// Has the greatest defense
class Warrior : public Unit
{
public:
	// Contructor
	Warrior();

	// Attack method for warrior
	virtual void Attack (Unit* pUnitToAttack) override;

	// Take Damage method for warrior
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

