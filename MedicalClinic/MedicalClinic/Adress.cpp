#include "pch.h"
#include <iostream>
#include <string>
#include "Adress.h"


#pragma region Constructors
Adress::Adress()
{

}
Adress::Adress(std::string Street, std::string City, std::string CodePost, std::string HouseNum)
{
	this->Street = Street;
	this->City = City;
	this->CodePost = CodePost;
	this->HouseNum = HouseNum;
}
Adress::~Adress()
{

}
#pragma endregion 
#pragma region Setters
void Adress::SetStreet(std::string Street)
{
	this->Street = Street;
}
void Adress::SetCity(std::string city)
{
	this->City = city;
}
void Adress::SetCodePost(std::string codepost)
{
	this->CodePost = codepost;
}
void Adress::SetHouseNum(std::string housenum)
{
	this->HouseNum = housenum;
}
#pragma endregion 
#pragma region Getters
std::string Adress::GetStreet()
{
	return this->Street;
}
std::string Adress::GetCity()
{
	return this->City;
}
std::string Adress::GetCodePost()
{
	return this->CodePost;
}
std::string Adress::GetHouseNum()
{
	return this->HouseNum;
}
#pragma endregion 
std::ostream & operator<<(std::ostream & os, Adress & adress)
{
	os << adress.Street << " " << adress.City << " " <<adress.CodePost << " " << adress.HouseNum << std::endl;
	return os;
}
std::istream & operator >> (std::istream &in, Adress & adress)
{
	in >> adress.Street;
	in >> adress.City;
	in >> adress.CodePost;
	in >> adress.HouseNum;
	return in;
}