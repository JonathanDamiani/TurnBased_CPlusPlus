#pragma once
#include "Unit.h"

// Assassing unit
// Strong against none
// Weak against none
// Weak defense and normal attack
// But has 50% chance to instant kill
class Assassin :
	public Unit
{
public:
	Assassin();

	// Attack method for Assassin
	virtual void Attack(Unit* pUnitToAttack) override;

	// Take Damage method for Assassin
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

