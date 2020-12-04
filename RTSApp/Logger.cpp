#include "Logger.h"

// Contructor
Logger::Logger() {};

// Change the console size
void Logger::ChangeConsoleSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, width, height, true);
}


// Function to write a color message to the console, centred or not.
void Logger::Write(std::string text, ColorsEnum textColor)
{
	// Handle to manage the colors
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	// Set console color using the colors enum and casting it to int
	SetConsoleTextAttribute(color, static_cast<int>(textColor));

	// Print the text line
	std::cout << text;

	// Set the color back
	SetConsoleTextAttribute(color, static_cast<int>(ColorsEnum::White));
}

// Function to write a color message to the console, centred or not.
void Logger::WriteLine(std::string text, ColorsEnum textColor, bool isCentred, bool centerHeight)
{
	// Handle to manage the colors
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Set console color using the colors enum and casting it to int
	SetConsoleTextAttribute(color, static_cast<int>(textColor));

	// If center Height is true set the heigh position of the text
	if (centerHeight)
	{
		Logger::CenterText(text, true);
	}

	// Centralize string in the horizontal
	if (isCentred)
	{
		Logger::CenterText(text);
	}

	// Print the text line
	std::cout << text << std::endl << std::flush;

	// Set the color back
	SetConsoleTextAttribute(color, static_cast<int>(ColorsEnum::White));
}

// Method to add spaces to the logger
void Logger::AddSpaces(int numberOfSpaces)
{
	int counter = 0;
	// While to create lots of line
	while (counter != numberOfSpaces)
	{
		std::cout << std::endl;
		counter++;
	}
}

// Method to center text
void Logger::CenterText(std::string str, bool centerHeight) 
{
	int cols;
	int rows;

	// Get the windows size using the address operator
	Logger::GetWindowsSize(rows, cols);

	// Calculate the positon of the rol the string should be when centralized
	// get the number os cols less the size of the string and divide by 2
	int positionCol = (int)((cols - str.length()) / 2);
	
	// Center the text in the middle of the width
	for (int i = 0; i < positionCol; i++)
	{
		std::cout << " ";
	}

	// Center the text in the middle of the height if its true
	if (centerHeight)
	{
		// It is the same as the colums but with the rows to define the height
		int positionRow = (int)((rows) / 2);
		Logger::AddSpaces(positionRow);
	}

}

// Method to get windows size
void Logger::GetWindowsSize(int& rRows, int& rCols)
{
	// Get the current console info
	CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo;

	// Get the console screen buffer info function 
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleBufferInfo);

	// Getting the number of columns and rows and pass to the parameters;
	rCols = consoleBufferInfo.srWindow.Right - consoleBufferInfo.srWindow.Left;
	rRows = consoleBufferInfo.srWindow.Bottom - consoleBufferInfo.srWindow.Top;
}
