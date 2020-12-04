#include "Assassin.h"

//Contructor with base stats Assassin
Assassin::Assassin()
{
	unitName = "Assassin";
	unitSymbol = "AS";
	unitAttack = 100;
	unitDefense = 0;
	unitHealth = 50;
	unitMaxHealth = 50;
	isDead = false;
	criticalHitChance = 20;
}

// Attack
void Assassin::Attack(Unit * pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical <= criticalHitChance)
	{
		damageToDeal = damageToDeal * 10;
	}

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

void Assassin::TakeDamage(Unit * pUnitAttacker, int damage)
{
	// Chance to dodge 
	int dodgeChance = std::rand() % 100 + 1;

	// Set to 0 if it less than 0. 
	if (damage < 0 || dodgeChance < 15)
	{
		damage = 0;
	}

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}

