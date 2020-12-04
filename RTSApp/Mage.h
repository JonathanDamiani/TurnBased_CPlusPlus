#pragma once
#include "Unit.h"

// Mage class child of Unit
class Mage : public Unit
{
public:
	// Contructor
	Mage();

	// Attack method for warrior
	virtual void Attack(Unit* pUnitToAttack) override;

	// Take Damage method for warrior
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

