#include "pch.h"
#include "Display.h"
#include <iostream>
#include <iomanip>

#define VERTICAL_SPACING 4
#define HORIZONTAL_SPACE 50

void ClearScreen()
{
	system("cls");
}

void MultiEndl(int endl_number)
{
	for (int i = 0; i < endl_number; i++)
		std::cout << std::endl;
}

void UpperSpace()
{
	MultiEndl(VERTICAL_SPACING);
}

void CenterText()
{
	std::cout << std::setw(HORIZONTAL_SPACE);
}
