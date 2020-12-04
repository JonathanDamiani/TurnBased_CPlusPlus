#include "Player.h"
#include <iostream>

// Contructor
Player::Player() {}

// Destructor
Player::~Player(){}

// Implementing IsDefeated
bool Player::IsDefeated()
{
	// Check if all units are dead
	for (Unit* unit : playerArmy.GetArmy())
	{
		// if there is one alive return false
		if (!unit->IsDead())
		{
			return false;
		}
	}
	// If all is dead return true
	return true;
}

