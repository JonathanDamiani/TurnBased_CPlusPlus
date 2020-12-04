#include "GameManager.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

// Method to run the game
void GameManager::Run()
{
	// Call game start to put the first screen of the game and the choice of the army
	GameManager::GameStart();
	
	Logger log;

	// Initializing player Army
	mPlayerHuman.playerArmy.CreateArmy();

	// Initializing the AI army
	mPlayerAI.playerArmy.CreateRandomArmy();

	system("pause");

	// Check if the player is defeated
	bool isPlayerDefeated = false;

	// Game Loop
	for (;;)
	{
		// AI defeated
		if (mPlayerAI.IsDefeated())
		{
			break;
		}

		// Player take turn
		mPlayerHuman.TakeTurn(mPlayerAI.playerArmy.GetArmy());
		
		// AI defeated
		if (mPlayerAI.IsDefeated())
		{
			break;
		}

		system("cls");

		// Player Defeated
		if (mPlayerHuman.IsDefeated())
		{
			isPlayerDefeated = true;
			break;
		}

		// AI take turn
		mPlayerAI.TakeTurn(mPlayerHuman.playerArmy.GetArmy());

		system("pause");

		// Player Defeated
		if (mPlayerHuman.IsDefeated())
		{
			isPlayerDefeated = true;
			break;
		}

		system("cls");
	}


	system("cls");
	if (isPlayerDefeated)
	{
		log.WriteLine("You have lost", ColorsEnum::Red, true, true);
	}
	else
	{
		log.WriteLine("You have won", ColorsEnum::Green, true, true);
	}

	system("pause");
}

// Game start private method, just create the first part of the game.
void GameManager::GameStart()
{
	// Create Log
	Logger log;

	// Create ui manager
	UIManager UI;

	// Change console size
	log.ChangeConsoleSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// Welcome to the game 
	log.WriteLine("WELCOME TO MEDIEVAL COMBAT", ColorsEnum::Green, true, true);

	// Add spaces to the the console
	log.AddSpaces(5);

	// Message to the user
	log.WriteLine("Press something to start", ColorsEnum::Blue, true);

	// Add spaces to the the console
	log.AddSpaces(5);

	// Wait for the use to type something
	getchar();

	system("CLS");

	// Show choices of units
	UI.ShowInstructions();

	system("pause");
	system("CLS");

}
