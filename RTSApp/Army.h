#pragma once
#include <vector>
#include "Unit.h"
#include "UnitType.h"
#include <ctime>

// Army class
class Army
{
public:
	// Constructor
	Army();

	// Destructor
	~Army();

	// Detroy units / Clear memory
	void Destroy();

	// Method to create an army by user choices
	void CreateArmy();

	// Method to create an ramdom army
	void CreateRandomArmy();

	// Create unit
	Unit* CreateUnit(UnitType eUnitType);

	// Get army vector
	std::vector<Unit*> GetArmy();

private:
	// Vector of units
	std::vector<Unit*> armyUnits;

	// Points to get units
	int pointsToGetUnits;
};
