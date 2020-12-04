#pragma once
#include "Unit.h"

// Vampire unit
// Strong against werewolf
// Weak against werewolf
// Strong but expensive
// Every attack can recover 1/2 of the damage dealt
class Vampire :
	public Unit
{
public:
	Vampire();
	
	// Attack method for Vampire
	virtual void Attack(Unit* pUnitToAttack) override;

	// Take Damage method for Vampire
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

