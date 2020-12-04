#include "Army.h"
#include "Warrior.h"
#include "Mage.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Archer.h"
#include "Assassin.h"
#include "Logger.h"
#include "UIManager.h"

// Implementation Army class
const int MAXIMUM_POINTS = 3000;

/*  Values of units
	warrior,
	mage,
	vampire,
	werewolf,
	assassin
	archer
*/
int UnitValues[(int)UnitType::MAX - 1] =
{
	100,
	100,
	400,
	400,
	500,
	100
};

// Contructor
Army::Army() 
{
	pointsToGetUnits = MAXIMUM_POINTS;
}

// Destructor
Army::~Army() 
{
	Destroy();
}

// Method to return the vector of units
std::vector<Unit*> Army::GetArmy()
{
	return armyUnits;
}


// Implementing create army
void Army::CreateArmy()
{
	Logger log; 

	UIManager ui;

	UnitType unitType;

	// Loop until the player spend all it possible points in units
	while (pointsToGetUnits > 0)
	{
		// get the player choice from the logger
		unitType = ui.GetPlayerUnitChoice(UnitValues, pointsToGetUnits);

		// Create the unit
		Unit* unitToAdd = CreateUnit(unitType);

		// If the unit isnt null add to the vector
		if (unitToAdd != nullptr)
		{
			armyUnits.push_back(unitToAdd);
		}

		// Log player choices
		ui.ShowPlayerArmyChoices(armyUnits);

		// Wait for the user to press enter
		system("pause");
		system("CLS");
	}
}

// Implementing create random army for the AI
void Army::CreateRandomArmy()
{
	Logger log;

	// Loop to create the units, while have points to spend
	while (pointsToGetUnits > 0)
	{	

		// I am using the MAX of enum - 1 because my enum start at 1
		// Get the units number of unts that is possible to try create
		int unitsToTry = static_cast<int>(UnitType::MAX) - 1;

		// Get a random value of unit to choose
		int unitToChoose = std::rand() % (unitsToTry) + 1;
	
		// While to test the units and if it has points to create it.
		while (unitsToTry > 0)
		{
			// If the value of the unit is less than the point to get units it can get it
			// Than increase to the armyUnits vector.
			if (UnitValues[unitToChoose - 1] <= pointsToGetUnits)
			{
				Unit* newUnit = CreateUnit(static_cast<UnitType>(unitToChoose));
				armyUnits.push_back(newUnit);

				break;
			}

			unitsToTry--;
		}	
	}
}

void Army::Destroy()
{
	// Delete all units of the memory
	for (Unit* pUnit : armyUnits)
	{
		delete pUnit;
	}

	// Remove evething from the vector
	armyUnits.clear();
}

//Factory to create Units
Unit* Army::CreateUnit(UnitType eUnitType)
{
	pointsToGetUnits -= UnitValues[int(eUnitType) - 1];

	// Return the user according with the choice of unit type
	switch (eUnitType)
	{
	case UnitType::Warrior:
		return new Warrior();
		break;

	case UnitType::Mage:
		return new Mage();
		break;

	case UnitType::Vampire:
		return new Vampire();
		break;
	
	case UnitType::Werewolf:
		return new Werewolf();
		break;

	case UnitType::Assassin:
		return new Assassin();
		break;

	case UnitType::Archer:
		return new Archer();
		break;

	default:
		return nullptr;
		break;
	}
}