#include "Warrior.h"

//Contructor with base stats Warrior
Warrior::Warrior()
{
	unitName = "Warrior";
	unitSymbol = "W";
	unitAttack = 80;
	unitDefense = 40;
	unitHealth = 150;
	unitMaxHealth = 150;
	isDead = false;
	criticalHitChance = 10;
}

// Attack
void Warrior::Attack(Unit* pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Calculating the change of a critical hit
	int critical = std::rand() % 100 + 1;

	if (critical < criticalHitChance)
	{
		damageToDeal = damageToDeal * 2;
	}
	

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

// Warrior is weak against Mage and strong against archer
// It also receives just half of damage from other units
void Warrior::TakeDamage(Unit* pUnitAttacker, int damage)
{
	// Check which unit is attacking and then calculate the damage received
	if (pUnitAttacker->getUnitName() == "Mage")
	{
		damage = damage * 2;
	}
	else if (pUnitAttacker->getUnitName() == "Archer")
	{
		damage = damage / 3;
	}
	else
	{
		damage = damage / 2;
	}


	if (damage < 0)
	{
		damage = 0;
	}

	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}