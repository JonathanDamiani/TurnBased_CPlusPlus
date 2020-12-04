#pragma once
#include <iostream>
#include "PlayerAI.h"
#include "PlayerHuman.h"
#include "Singleton.h"
#include "Logger.h"
#include "ColorsEnum.h"
#include "UIManager.h"

// Class Game manager, to control the game loop as a singleton
class GameManager : public Singleton<GameManager>
{
public:

	// Make this class able to access the singleton private members
	friend class Singleton<GameManager>;

	//Method to run the game
	void Run();

	// Player
	PlayerAI mPlayerAI;
	PlayerHuman mPlayerHuman;
	
protected:

	// Contructor
	GameManager() {};

private: 
	// Method game start to the first things on screen
	void GameStart();

};

