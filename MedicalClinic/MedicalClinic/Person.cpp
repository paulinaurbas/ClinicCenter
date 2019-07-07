#include "pch.h"
#include <string>
#include <iostream>
#include "Person.h"
#include <sstream>
#include <istream>
#include <string>
Person::Person()
{

}
Person::Person(std::string name, std::string surname, int age, std::string PESEL, std::string sex, std::shared_ptr<Adress> adress)
{
	this->Name = name;
	this->Surname = surname;
	this->Age = Age;
	this->PESEL = PESEL;
	this->adress = adress;
	this->sex = sex;
}
Person::~Person()
{

}
void Person::SetName(std::string name)
{
	this->Name = name;
}
void Person::SetSurname(std::string surname)
{
	this->Surname = surname;
}
void Person::SetAge(int Age)
{
	this->Age = Age;
}
void Person::SetPesel(std::string PESEL)
{
	this->PESEL = PESEL;
}
void Person::SetAdress(std::shared_ptr<Adress>)
{
	this->adress = adress;
}
void Person::SetSex(std::string sex)
{
	this->sex = sex;
}
std::string Person::GetName()
{
	return this->Name;
}
std::string Person::GetSurname()
{
	return this->Surname;
	
}
int Person::GetAge()
{
	return this->Age;
}
std::string Person::GetPesel()
{
	return this->PESEL;
}
std::string Person::GetSex()
{
	return this->sex;
}

std::shared_ptr<Adress> Person::GetAdress()
{
	return this->adress;
}
/*
void Person::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << this->Name << " " <<this->Surname << " " << this->Age << " " << this->PESEL << " " << this->adress << " " << this->sex << std::endl;
	
}
*/
Person Person::NewElement()
{
	std::cout << "Name: " << std::endl;
	std::string FirstName = OnlyLetterProc();
	std::cout << "Surname: " << std::endl;
	std::string LastName = OnlyLetterProc();
	std::cout << "Age: " << std::endl;
	int Age1 = OnlyNumberProc();
	std::cout << "PESEL: " << std::endl;
	std::string pesel1 = RegexPeselValidation();
	std::cout << "Sex " << std::endl;
	std::string sex1 = OnlyLetterProc();
	std::cout << "Street: " << std::endl;
	std::string Street1 = OnlyLetterProc();
	std::cout << "City: " << std::endl;
	std::string City1 = OnlyLetterProc();
	std::string PostCode1 = PostCodeRegex();
	std::cout << "House Number: " << std::endl;
	std::string HouseNum1 = RegexHouseNumber();
	std::shared_ptr <Adress> ad1 = std::make_shared<Adress>(Street1, City1, PostCode1, HouseNum1);
	this->Name = FirstName;
	this->Surname = LastName;
	this->Age = Age1;
	this->PESEL = pesel1;
	this->adress = ad1;
	this->sex = sex1;
	return *(this);
}
std::ostream & operator<<(std::ostream & os, Person & person)
{
	os << person.Name<< " " << person.Surname << " " <<person.Age<< " " << person.PESEL << " " << person.adress<< " " << person.sex << std::endl;

	return os;
}
std::istream & operator >> (std::istream &in, Person & person)
{
	in >> person.Name;
	in >> person.Surname;
	in >> person.Age;
	in >> person.PESEL;
	in >> person.sex;
	std::string help;
	in >> help;
	person.adress->SetStreet(help);
	in >> help;
	person.adress->SetCity(help);
	in >> help;
	person.adress->SetCodePost(help);
	in >> help;
	person.adress->SetHouseNum(help);
	return in;
}