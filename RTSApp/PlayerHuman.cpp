#include "PlayerHuman.h"

// Contructor
PlayerHuman::PlayerHuman() {}

// Destructor
PlayerHuman::~PlayerHuman() {}

// Implementation of take turn for player human
void PlayerHuman::TakeTurn(std::vector<Unit*> AIArmy)
{
	// Create ui manager
	UIManager UI;

	// Create Logger
	Logger log;

	// Draw the main game screen
	UI.DrawGameMainGameScreen(AIArmy, playerArmy.GetArmy());

	log.WriteLine("Player Turn", ColorsEnum::Blue, true);
	

	int targetUnit;
	int unitToAttack;


	Unit* playerUnit;
	Unit* enemyUnit;

	log.AddSpaces(1);
	log.WriteLine("Choose which unit you want to attack an enemy unit by its number", ColorsEnum::White);
	// Get target unit 
	while (true)
	{
		// Check if the user input is valid
		if (!(std::cin >> unitToAttack) || unitToAttack <= 0 || unitToAttack > playerArmy.GetArmy().size())
		{
			log.WriteLine("That is not a valid choice, you must choose only numbers that exists in the yout army", ColorsEnum::Red);
			// Clear the input from the stream
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		else
		{
			// Get the player unit according with the selected choices of the player
			playerUnit = playerArmy.GetArmy().at(unitToAttack - 1);

			if (playerUnit->IsDead())
			{
				log.WriteLine("That is not a valid unit, it is dead", ColorsEnum::Red);
			}
			else
			{
				break;
			}
		}
	}

	log.AddSpaces(1);
	log.WriteLine("Choose the target unit you want to attack by its number in the enemy army", ColorsEnum::White);
	// Get target unit 
	while (true)
	{
		// Check if the user input is valid
		if (!(std::cin >> targetUnit) || targetUnit <= 0 || targetUnit > AIArmy.size())
		{
			log.WriteLine("That is not a valid choice, you must choose only numbers that exists in the enemy army", ColorsEnum::Red);
			// Clear the input from the stream
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		else
		{
			enemyUnit = AIArmy.at(targetUnit - 1);

			if (enemyUnit->IsDead())
			{
				log.WriteLine("That is not a valid unit, it is already dead", ColorsEnum::Red);
			}
			else
			{
				break;
			}

		}
	}

	// Attack the unit
	playerUnit->Attack(enemyUnit);
}