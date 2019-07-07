#include "pch.h"
#include <iostream>
#include <string>
#include "AdminHelper.h"



std::string AskUserForName()
{
	std::string Name;
	std::cout << "Name: " << std::endl;
	std::cin >> Name;
	return Name;
}
std::string AskUserForSurname()
{
	std::string Surname;
	std::cout << "Surname: " << std::endl;
	std::cin >> Surname;
	return Surname;
}
