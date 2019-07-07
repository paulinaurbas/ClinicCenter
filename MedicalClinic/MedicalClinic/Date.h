#pragma once
#include <iostream>
#include <string>
#include "RegexSupport.h"
#include "IPrintable.h"
class Date:public IPrintable
{
protected:
	int day;
	int month;
	int year;
	std::string hour;
public:
#pragma region Constructors and destruktors
	Date();
	Date(int day, int month, int year, std::string hour);
	~Date() = default;
#pragma endregion 
#pragma region Setters
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void SetHour(std::string hour);
#pragma endregion 
#pragma region Getters
	int GetDay();
	int GetMonth();
	int GetYear();
	std::string GetHour();
#pragma endregion 
#pragma region Operators
	virtual void Print(std::ostream & os) const override;
	//friend std::ostream & operator << (std::istream &, Date &);
	friend std::istream & operator >> (std::istream &, Date &);
#pragma endregion 
#pragma region Methods
	Date NewElement();
#pragma endregion
};