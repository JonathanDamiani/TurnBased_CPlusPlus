#include "Werewolf.h"

//Contructor with base stats Werewolf
Werewolf::Werewolf()
{
	unitName = "Werewolf";
	unitSymbol = "WW";
	unitAttack = 120;
	unitDefense = 50;
	unitHealth = 200;
	unitMaxHealth = 200;
	isDead = false;
	criticalHitChance = 30;
}

void Werewolf::Attack(Unit * pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical <= criticalHitChance)
	{
		damageToDeal = damageToDeal * 3/2;
	}

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

void Werewolf::TakeDamage(Unit * pUnitAttacker, int damage)
{
	// Check which unit is attacking and then calculate the damage received
	if (pUnitAttacker->getUnitName() == "Vampire")
	{
		damage = damage * 2;
	}

	// Set to 0 if it less than 0.
	if (damage < 0)
	{
		damage = 0;
	}

	// Do damage of 1/4 of its attack;
	int damageToDealToAttacker = unitAttack / 4;
	pUnitAttacker->SetUnitHealth(damageToDealToAttacker);

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}
