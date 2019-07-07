#include "pch.h"
#include "menu.h"
#include "Display.h"
#include <Windows.h>
#include <iostream>

Menu::Menu()
{

}
Menu::Menu(std::vector<std::string> options)
{
	this->options = options;
	index = 0;
}
Menu::~Menu()
{

}
void Menu::SetVector(std::vector<std::string> options)
{
	this->options = options;
}

void Menu::SetIndex(int index)
{
	this->index = index;
}

void Menu::SetMenuType(MenuType type)
{
	this->type = type;
}

std::vector<std::string> Menu::GetVector() const
{
	return options;
}

int Menu::GetIndex() const
{
	return index;
}

MenuType Menu::GetMenuType() const
{
	return type;
}
Menu * Menu::GetInstance()
{
	static Menu instance;
	return &instance; 
}
void Menu::MoveArrow()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (index != 0)
		{
			options.at(index).replace(0, 1, " ");
			index = index - 1;
			options.at(index).replace(0, 1, ">");
		}
	}
	else
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (index != options.size() - 1)
			{
				options.at(index).replace(0, 1, " ");
				index = index + 1;
				options.at(index).replace(0, 1, ">");
			}
		}
}

void Menu::show() const
{
	UpperSpace();
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		CenterText();
		std::cout << *i << std::endl;
	}
}