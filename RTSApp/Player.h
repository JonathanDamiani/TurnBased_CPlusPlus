#pragma once
#include "Army.h"
#include <iostream>
// Base class for the player
class Player
{
public:
	// Player army
	Army playerArmy;

	// Contructor
	Player();

	// Destructor
	~Player();

	// Method to control turn
	virtual void TakeTurn(std::vector<Unit*> AIArmy) = 0;

	// Method to check if the player is defeated
	bool IsDefeated();
};