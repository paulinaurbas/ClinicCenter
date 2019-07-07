#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Adress.h"
#include "IPrintable.h"
#include "RegexSupport.h"

class Person
{
protected:
	std::string Name;
	std::string Surname;
	int Age;
	std::string PESEL;
	std::shared_ptr<Adress> adress = std::make_shared<Adress>();
	std::string sex;
public:
#pragma region Constructors & Destructors
	Person();
	Person(std::string name, std::string surname, int age, std::string PESEL, std::string sex, std::shared_ptr<Adress> adress);
	~Person();
#pragma endregion
#pragma region Setters

	void SetName(std::string name);
	void SetSurname(std::string surname);
	void SetAge(int age);
	void SetPesel(std::string Pesel);
	void SetSex(std::string Sex);
    void SetAdress(std::shared_ptr<Adress>);

#pragma endregion
#pragma region Getters
	std::string GetName();
	std::string GetSurname();
	std::string GetSex();
	int GetAge();
	std::string GetPesel();
	std::shared_ptr<Adress> GetAdress();
#pragma endregion
#pragma region Operators
	//virtual void Print(std::ostream & os) const override;
	friend std::ostream& operator<< (std::ostream &, Person &);
	friend std::istream & operator >> (std::istream &, Person &);
#pragma endregion
#pragma region Methods
	Person NewElement();
#pragma endregion
};