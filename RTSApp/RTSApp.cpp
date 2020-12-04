// RTSApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameManager.h"
#include <ctime>

// Game manager
GameManager* Singleton<GameManager>::mInstance = nullptr;

int main()
{
	std::srand(std::time(nullptr)); // seed the rand with the time

	// Creating Instance of GM
	GameManager::CreateInstance();

	// Pointer to the intance 
	GameManager* GM = GameManager::GetInstance();

	// Running the game
	GM->Run();

	// Destroy Game manager instance
	GameManager::DestroyInstance();
}
