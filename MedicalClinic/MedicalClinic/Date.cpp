#include "pch.h"
#include "Date.h"

Date::Date()
{

}
Date::Date(int day, int month, int year, std::string hour): day(day), month(month), year(year), hour(hour)
{

}
void Date::SetDay(int day)
{
	this->day = day;
}
void Date::SetMonth(int month)
{
	this->month = month;
}
void Date::SetYear(int year)
{
	this->year = year;
}
void Date::SetHour(std::string hour)
{
	this->hour = hour;
}

int Date::GetDay()
{
	return this->day;
}
int Date::GetMonth()
{
	return this->month;
}
int Date::GetYear()
{
	return this->year;
}
std::string Date::GetHour()
{
	return this->hour;
}
/*std::ostream & operator<<(std::ostream & os, Date & d1)
{
	os << d1.GetDay()<< " " << d1.GetMonth() << " " << d1.GetYear() << " " << d1.GetHour() << std::endl;

	return os;
}*/
void Date::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << this->day << " " << this->month << " " << this->year << " " << this->hour << std::endl;
}
std::istream & operator >> (std::istream &in, Date & d1)
{
	in >> d1.day;
	in >> d1.month;
	in >> d1.year;
	in >> d1.hour;
	return in;
}
Date Date::NewElement()
{
	
	std::cout << "Day: " << std::endl;
	int day1 = OnlyNumberProc();
	while (day1 > 31 || day1 < 1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: ";
		day1 = OnlyNumberProc();
	}
	
	std::cout << "Month: " << std::endl;
	int month1 = OnlyNumberProc();
	while (month1 > 12 || day1 < 1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: ";
		month1 = OnlyNumberProc();
	}
	std::cout << "Year: " << std::endl;
	int year1 = OnlyNumberProc();
	while (year1 < 2019)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: ";
	    year1 = OnlyNumberProc();
	}
	int hr;
	bool pomok = true;
	bool pomok2 = true;
	while (pomok) {
		std::cout << "Hour: " << std::endl;
		std::cin >> hr;
		if (hr >= 8 && hr < 19)
			break;
		std::cout << "Invalid Input, try again.";
	}
	int min;
	while (pomok2) {
		std::cout << "Minutes: " << std::endl;
		std::cin >> min;
		if (min >= 0 && min < 59)
			break;
		std::cout << "Invalid Input, try again.";
	}

	std::string hour1;
	hour1 += std::to_string(hr);
	hour1 += ".";
	hour1 += std::to_string(min);
	this->day = day1;
	this->month = month1;
	this->year = year1;
	this->hour = hour1;
	return *(this);
}