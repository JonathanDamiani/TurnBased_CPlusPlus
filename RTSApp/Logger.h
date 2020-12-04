#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
// const expression, used to change the size of console. tell the compile that it is using a recent version of the windows
constexpr auto _WIN32_WINNTO = 0x0500;

#include <windows.h>
#include "ColorsEnum.h"
#include "UnitType.h"
#include "Unit.h"
#include "Singleton.h"

class Logger 
{
public:
	// Contructor
	Logger();
	// Write entire Line
	void WriteLine(std::string text, ColorsEnum textColor = ColorsEnum::White, bool isCentred = false, bool centerHeight = false);

	// Write with no new lines
	void Write(std::string text, ColorsEnum textColor);

	// Adding spaces for the text
	void AddSpaces(int numberOfSpaces);

	// Change console size
	void ChangeConsoleSize(int width, int height);
	
	// Center text in the console
	void CenterText(std::string text, bool centerHeight = false);

	// Get windows size
	void GetWindowsSize(int& rows, int& cols);
};

