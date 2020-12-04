#include "Unit.h"

// Implementing unit methods

//Contructor with base stats
Unit::Unit() 
{
	unitName = "Unit";
	unitSymbol = "U";
	unitAttack = 30;
	unitDefense = 10;
	unitHealth = 100;
	unitMaxHealth = 100;
	isDead = false;
}

// Contructor with custom stats
Unit::Unit(int atk, int def, int hp)
{
	unitAttack = atk;
	unitDefense = def;
	unitHealth = hp;
}

// Creating array with name of the units
std::string* Unit::GetTypesOfUnits()
{
	static std::string str[(int)UnitType::MAX - 1];

	str[0] = "Warrior";
	str[1] = "Mage";
	str[2] = "Vampire";
	str[3] = "Werewolf";
	str[4] = "Assassin";
	str[5] = "Archer";

	return str;
}

// Unit Destructor 
Unit::~Unit(){}

// Implementing getters and setters 
int Unit::GetUnitAttack()
{
	return unitAttack;
}

int Unit::GetUnitDefense()
{
	return unitDefense;
}

int Unit::GetUnitHealth()
{
	return unitHealth;
}

std::string Unit::getUnitName()
{
	return unitName;
}

std::string Unit::getUnitSymbol()
{
	return unitSymbol;
}

void Unit::SetUnitAttack(int value)
{
	unitAttack = value;
}

void Unit::SetUnitDefense(int value)
{
	unitDefense = value;
}

// Set damage to player health
void Unit::SetUnitHealth(int value)
{
	if (value >= unitHealth)
	{
		unitHealth = 0;
		isDead = true;
	}
	else
	{
		unitHealth -= value;
	}
	
}

int Unit::GetUnitMaxHealth()
{
	return unitMaxHealth;
}

// Return the value of is dead
bool Unit::IsDead()
{
	return isDead;
}

// Base Attack
void Unit::Attack(Unit* pUnitToAttack)
{
	// Calculate damage
	int damageToDeal = unitAttack - pUnitToAttack->GetUnitDefense();

	// Check if damage to deal is greater than 0 
	if (damageToDeal > 0)
	{
		pUnitToAttack->TakeDamage(this, damageToDeal);
	}
}

// Base take damage 
void Unit::TakeDamage(Unit* pUnitAttacker, int damage)
{

	if (damage < 0)
	{
		damage = 0;
	}

;	// Decrease the health of the unit damaged
	SetUnitHealth(damage);
}
