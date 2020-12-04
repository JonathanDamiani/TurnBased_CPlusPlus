#include "UIManager.h"

// Contructor
UIManager::UIManager() {}

UnitType UIManager::GetPlayerUnitChoice(int unitValues[static_cast<int>(UnitType::MAX) - 1], int pointsLeft)
{
	int playerChoice = 0;

	Logger log;
	std::string* allUnits = Unit::GetTypesOfUnits();

	// Print the option to the player
	log.AddSpaces(5);
	log.WriteLine("        Choose your untis       ", ColorsEnum::Blue, true);
	log.AddSpaces(1);
	log.WriteLine("Points to spend: " + std::to_string(pointsLeft), ColorsEnum::Red, true);
	log.AddSpaces(1);
	log.WriteLine("--------------------------------", ColorsEnum::LightGreen, true);
	log.AddSpaces(2);

	// Creating player choices 
	for (int i = 0; i < static_cast<int>(UnitType::MAX) - 1; i++)
	{
		std::string unitToPrint = *(allUnits + i);
		std::string stringToPrint = std::to_string(i + 1) + ". " + unitToPrint + "| Value: " + std::to_string(unitValues[i]);

		log.WriteLine(stringToPrint, ColorsEnum::Green, true);
	}

	log.AddSpaces(2);
	log.WriteLine("--------------------------------", ColorsEnum::LightGreen, true);
	log.AddSpaces(3);


	while (true)
	{
		// Get the option
		// Verify if it a number
		if (!(std::cin >> playerChoice) || (playerChoice >= static_cast<int>(UnitType::MAX) || playerChoice <= 0))
		{
			// Creatin error message for the user
			std::string error;
			error = "Only number less than " + std::to_string(static_cast<int>(UnitType::MAX)) + " and greater than 0 are allowed";
			log.WriteLine(error, ColorsEnum::Red);

			// Clear the input from the stream
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;

		}
		else if (pointsLeft < unitValues[playerChoice - 1])
		{
			log.WriteLine("You don't have enougth points to spend on this unit", ColorsEnum::Red);
			continue;
		}
		break;
	}
	// Return the player choice as an unit type 
	return static_cast<UnitType>(playerChoice);
}

//Method to show the player his choices
void UIManager::ShowPlayerArmyChoices(std::vector<Unit*> army)
{
	// Instantiating Logger
	Logger log;

	// String array with all units
	std::string* allUnits = Unit::GetTypesOfUnits();

	// Logger functions
	log.AddSpaces(5);
	log.WriteLine("YOUR ARMY", ColorsEnum::Blue, true);

	// Loop for all for the max number of units
	for (int i = 0; i < static_cast<int>(UnitType::MAX) - 1; i++)
	{
		int counter = 0;

		// Get the name of the unit to print
		std::string unitToPrint = *(allUnits + i);

		// Count how many of this unit has in the vector of the army
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); ++it)
		{
			if ((*it)->getUnitName() == unitToPrint)
			{
				counter++;
			}
		}
		// Print the name unit with the number of units 
		std::string stringToPrint = std::to_string(i + 1) + ". " + unitToPrint + ": " + std::to_string(counter);
		log.WriteLine(stringToPrint, ColorsEnum::Green, true);
	}

}

// Implementation of draw game screen
void UIManager::DrawGameMainGameScreen(std::vector<Unit*> aiArmy, std::vector<Unit*> playerArmy)
{
	Logger log;

	// Print the AI Army
	log.WriteLine("AI Army", ColorsEnum::Red, true);
	log.AddSpaces(2);

	UIManager::DrawTheArmy(aiArmy);

	log.AddSpaces(4);

	// Print the AI Army
	log.WriteLine("Player Army", ColorsEnum::Blue, true);
	log.AddSpaces(2);

	// Draw the army
	UIManager::DrawTheArmy(playerArmy);
	
	log.AddSpaces(4);
}

// Method to draw the army
void UIManager::DrawTheArmy(std::vector<Unit*> anyArmy)
{
	// Instance of logger
	Logger log;

	// String to print
	std::string strToPrint;

	int counter = 1;

	// Iterating throught the vector and print in a good way
	for (Unit* pUnit : anyArmy)
	{
		// creating the string with the number
		strToPrint = "  " + std::to_string(counter) + ". ";

		// Using the write method to print text with color
		log.Write(strToPrint, ColorsEnum::White);

		// Get the values of health and max health of the units
		int unitHeath = pUnit->GetUnitHealth();
		int maxUnitHeath = pUnit->GetUnitMaxHealth();

		// Create a string with the life and health
		strToPrint = pUnit->getUnitSymbol() + ": HP: " + std::to_string(unitHeath) + "/" + std::to_string(maxUnitHeath) + "\t ";

		// int to store a aproximation of a percent between the current life and the max health of the unit
		int unitHPPercent;

		// Calculating the percent
		unitHPPercent = (unitHeath * 100) / maxUnitHeath;

		// Print the life with different colors based on the percert of the life
		if (unitHPPercent >= 90)
		{
			log.Write(strToPrint, ColorsEnum::Green);
		}
		else if (unitHPPercent < 90 && unitHPPercent >= 40)
		{
			log.Write(strToPrint, ColorsEnum::Yellow);
		}
		else if (unitHPPercent < 40)
		{
			log.Write(strToPrint, ColorsEnum::Red);
		}

		// Counter
		counter++;
	}
}

// Show units to player at beginning of the game with instruction
void UIManager::ShowInstructions()
{
	// Instance of logger
	Logger log;

	log.AddSpaces(1);
	log.WriteLine("INSTRUCTIONS", ColorsEnum::White, true);
	log.AddSpaces(1);

	log.WriteLine("Choose among the units spending points and create you army to fight againts an AI", ColorsEnum::White, true);
	log.WriteLine("Every unit has unique features and are weak against others units and strong another units", ColorsEnum::White, true);
	log.AddSpaces(2);

	log.AddSpaces(3);
	log.WriteLine("UNITS OF THE GAME", ColorsEnum::White, true);
	log.AddSpaces(1);
	log.WriteLine("----------------------------------------------------------------------------------", ColorsEnum::Blue, true);
	log.AddSpaces(1);
	log.WriteLine("Warrior [ W ]", ColorsEnum::LightBlue, true);
	log.WriteLine("Warriors are strong against archer and have good defense but they are really weak against mages", ColorsEnum::LightBlue, true);
	log.AddSpaces(1);
	log.WriteLine("Mage [ M ]", ColorsEnum::Green, true);
	log.WriteLine("Mages are strong against warriors and have good attack but bad defense, they are weak against archer", ColorsEnum::Green, true);
	log.AddSpaces(1);
	log.WriteLine("Archer [ AR ] ", ColorsEnum::Purple, true);
	log.WriteLine("Archer are strong against mages and have a chance of avoid all damage, they weak against warriors", ColorsEnum::Purple, true);
	log.AddSpaces(1);
	log.WriteLine("Assassin [ AS ]", ColorsEnum::Yellow, true);
	log.WriteLine("Assassins have great attack but no defense, they have a small chance to avoid attack, and a good chance one hit kill enemies", ColorsEnum::Yellow, true);
	log.AddSpaces(1);
	log.WriteLine("Vampire [ V ]", ColorsEnum::Aqua, true);
	log.WriteLine("Vampire are strong but expensives units, they do great damage in werewolfs but also weak against them, they recover a amount of HP per attack", ColorsEnum::Aqua, true);
	log.WriteLine("but also weak against them, they recover a amount of HP per attack", ColorsEnum::Aqua, true);
	log.AddSpaces(1);
	log.WriteLine("Werewolf [ WW ]", ColorsEnum::White, true);
	log.WriteLine("Werewolfs give good damage to vampires but are weak against them, they are really powerful, ", ColorsEnum::White, true);
	log.WriteLine("when attacked the give a small damage to the attacker", ColorsEnum::White, true);
	log.AddSpaces(1);
	log.AddSpaces(1);
	log.WriteLine("----------------------------------------------------------------------------------", ColorsEnum::Blue, true);
}
