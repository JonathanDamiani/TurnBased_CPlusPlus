#pragma once
#include "Player.h"
#include "Logger.h"
#include "UIManager.h"
#include "Unit.h"

// Class to player AI
class PlayerAI : public Player
{
public:
	// Contructor
	PlayerAI();

	// Desctructor
	~PlayerAI();

	// Take turn AI
	void TakeTurn(std::vector<Unit*> humanArmy);
};

