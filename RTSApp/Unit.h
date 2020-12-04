#pragma once
#include <string>
#include <vector>
#include "UnitType.h"

class Unit
{
public:

	// base contructor
	Unit();

	// contructor to initialize values of unit  
	Unit(int atk, int def, int hp);

	// Unity Desctructor
	~Unit();

	// Attack method
	// Receive a pointer to the unit that it is attacking
	virtual void Attack(Unit* pUnitToAttack);

	// Take method
	// Receive a pointer to the unit that it is receiving the damage, and the amount of damage the unit take.
	virtual void TakeDamage(Unit* pUnitAttacker, int damage);

	// Getters and Setters
	int GetUnitAttack();
	void SetUnitAttack(int value);

	int GetUnitDefense();
	void SetUnitDefense(int value);

	int GetUnitHealth();
	void SetUnitHealth(int value);

	int GetUnitMaxHealth();

	bool IsDead();

	std::string getUnitName();
	std::string getUnitSymbol();

	// Method to return an array of the units names
	static std::string* GetTypesOfUnits();

	
protected:
	// Unit basic stats
	int unitAttack;
	int unitDefense;
	int unitHealth;
	int unitMaxHealth;

	// Unit helpers variables
	bool isDead;
	std::string unitName;
	std::string unitSymbol;

	// Unit Critical hit chance, 100 = 100% , 20 = 20% ...
 	int criticalHitChance;
};

