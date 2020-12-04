#include "Vampire.h"

//Contructor with base stats Vampire
Vampire::Vampire()
{
	unitName = "Vampire";
	unitSymbol = "V";
	unitAttack = 100;
	unitDefense = 40;
	unitHealth = 180;
	unitMaxHealth = 180;
	isDead = false;
	criticalHitChance = 40;
}
// Atack Vampire
void Vampire::Attack(Unit * pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical <= criticalHitChance)
	{
		damageToDeal = damageToDeal * 2;
	}

	// Recover its unit life for half of the damage dealt
	unitHealth += damageToDeal / 2;

	if (unitHealth >= unitMaxHealth)
	{
		unitHealth = unitMaxHealth;
	}

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

void Vampire::TakeDamage(Unit * pUnitAttacker, int damage)
{
	// Check which unit is attacking and then calculate the damage received
	if (pUnitAttacker->getUnitName() == "Werewolf")
	{
		damage = damage * 2;
	}

	// Set to 0 if it less than 0.
	if (damage < 0)
	{
		damage = 0;
	}

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}

