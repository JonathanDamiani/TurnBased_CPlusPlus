#include "Archer.h"

// Archer Contructor
Archer::Archer()
{
	unitName = "Archer";
	unitSymbol = "AR";
	unitAttack = 80;
	unitDefense = 30;
	unitHealth = 120;
	unitMaxHealth = 120;
	isDead = false;
	criticalHitChance = 35;
}

// Archer attack
void Archer::Attack(Unit * pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical < criticalHitChance)
	{
		damageToDeal = damageToDeal * 3;
	}

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

// Archer take damege
// Archer is weak against warrior and strong against mage
// Also has a chance to dodge atacks
void Archer::TakeDamage(Unit * pUnitAttacker, int damage)
{
	if (pUnitAttacker->getUnitName() == "Warrior")
	{
		damage = damage * 2;
	}
	else if (pUnitAttacker->getUnitName() == "Mage")
	{
		damage = damage / 3;
	}

	// Chance to dodge 
	int dodgeChance = std::rand() % 100 + 1;


	// Set to 0 if it less than 0 or it dogde value is less than 20
	// Giving it 20 % of chance to dodge
	if (damage < 0 || dodgeChance < 35)
	{
		damage = 0;
	}

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}


