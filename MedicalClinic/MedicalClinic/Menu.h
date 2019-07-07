#pragma once
#include <vector>
#include <string>
enum MenuType {
	MAIN, DOCTOR, PATIENT, PRESCRIPTION, VISIT
};

class Menu
{
private:
	std::vector<std::string> options;
	int index = 0;
	MenuType type;
	static Menu * instance;
public:
	Menu();
	Menu(std::vector<std::string> options);

	void SetVector(std::vector<std::string>);
	void SetIndex(int);
	void SetMenuType(MenuType type);

	std::vector<std::string> GetVector() const;
	int GetIndex() const;
	MenuType GetMenuType() const;
	static Menu * GetInstance();
	void MoveArrow();
	void show() const;
	~Menu();
};