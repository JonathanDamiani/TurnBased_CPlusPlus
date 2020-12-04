#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "ColorsEnum.h"
#include "UnitType.h"
#include "Unit.h"
#include "Logger.h"

// Ui Manager to control function that draw the ui
class UIManager
{
public:
	// Contructor
	UIManager();

	// Draw player choices on screen 
	UnitType GetPlayerUnitChoice(int unitValues[static_cast<int>(UnitType::MAX) - 1], int pointsLeft);

	// Show the player his choices
	void ShowPlayerArmyChoices(std::vector<Unit*> army);

	// Method that reveice the vector of both armies and draw the game screen with the units
	void DrawGameMainGameScreen(std::vector<Unit*> aiArmy, std::vector<Unit*> playerArmy);

	// Method to draw the army in te screen
	void DrawTheArmy(std::vector<Unit*> anyArmy);

	// Method show units
	void ShowInstructions();
};

