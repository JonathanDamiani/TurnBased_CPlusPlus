#pragma once
#include "Unit.h"
// Archer unit
// Strong against mage
// Weak against warrior
// Has high chance to have a critical hit and have a chance to dogde
class Archer : public Unit
{
public:
	// Archer
	Archer();

	// Attack method for warrior
	virtual void Attack(Unit* pUnitToAttack) override;

	// Take Damage method for warrior
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

