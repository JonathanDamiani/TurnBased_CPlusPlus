#pragma once
#include <vector>
#include "Unit.h"
#include "Player.h"
#include "UIManager.h"
#include "Logger.h"
#include "ColorsEnum.h"

class PlayerHuman : public Player
{
public:
	// Contructor
	PlayerHuman();

	// Destructor
	~PlayerHuman();

	// Method to control turn
	void TakeTurn(std::vector<Unit*> AIArmy);
};
