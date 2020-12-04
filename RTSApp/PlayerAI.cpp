#include "PlayerAI.h"

// Implementation PLayer AI
// Contructor

PlayerAI::PlayerAI(){}

// Destructor
PlayerAI::~PlayerAI(){}

// Implementation of take turn for player human
void PlayerAI::TakeTurn(std::vector<Unit*> humanArmy)
{
	// Create ui manager
	UIManager UI;

	// Create Logger
	Logger log;

	// Ramdon choose an unit to attack index 
	int unitIndex;

	// get unit to attack from the army vector
	Unit* unitToAttack;

	// :oop until choose alive unit
	while (true)
	{
		unitIndex = std::rand() % playerArmy.GetArmy().size();
		unitToAttack = playerArmy.GetArmy().at(unitIndex);

		if (!unitToAttack->IsDead())
		{
			break;
		}
	}

	// Random choose the target index
	int humanUnitIndex;

	// get target unit from the army vector of the player
	Unit* targetUnit;

	// Loop until find alive target
	while (true)
	{
		humanUnitIndex = std::rand() % humanArmy.size();
		targetUnit = humanArmy.at(humanUnitIndex);

		if (!targetUnit->IsDead())
		{
			break;
		}
	}

	// atack the unit
	unitToAttack->Attack(targetUnit);

	// Draw the armies
	UI.DrawGameMainGameScreen(playerArmy.GetArmy(), humanArmy);

	// Telling which enemy unit attacked which unit from player
	log.WriteLine("The enemy unit: " + std::to_string(unitIndex + 1) +" attacked your unit :" + std::to_string(humanUnitIndex + 1), ColorsEnum::Red);
}