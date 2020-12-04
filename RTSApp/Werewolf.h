#pragma once
#include "Unit.h"

// Werewolf unit
// Strong against vampire
// Weak against vampire
// Strong but expensive
// Every time is attacked give 1/4 of its as damage to the attacker
class Werewolf :
	public Unit
{
public:
	Werewolf();

	// Attack method for Werewolf
	virtual void Attack(Unit* pUnitToAttack) override;

	// Take Damage method for Werewolf
	void TakeDamage(Unit* pUnitAttacker, int damage) override;
};

