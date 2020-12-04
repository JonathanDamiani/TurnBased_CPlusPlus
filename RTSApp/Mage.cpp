#include "Mage.h"

//Contructor with base stats Mage
Mage::Mage()
{
	unitName = "Mage";
	unitSymbol = "M";
	unitAttack = 100;
	unitDefense = 20;
	unitHealth = 120;
	unitMaxHealth = 120;
	isDead = false;
	criticalHitChance = 5;
}
//
// Base Attack
void Mage::Attack(Unit* pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical < criticalHitChance)
	{
		damageToDeal = damageToDeal * 3/2;
	}

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

// Mage take damage
// Mage is weak againt archer and strong against warrior
void Mage::TakeDamage(Unit* pUnitAttacker, int damage)
{
	if (pUnitAttacker->getUnitName() == "Archer")
	{
		damage = damage * 2;
	}
	else if (pUnitAttacker->getUnitName() == "Warrior")
	{
		damage = damage / 3;
	}

	// Set to 0 if it less than 0. 
	if (damage < 0)
	{
		damage = 0;
	}

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}