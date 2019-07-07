#pragma once
#include <iostream>
#include <string>

class Adress
{
	
private:
	std::string Street;
	std::string City;
	std::string CodePost;
	std::string HouseNum;
public: 
#pragma region Constructors
	Adress();
	Adress(std::string Street, std::string City,std::string CodePost,std::string HouseNum);
	~Adress();
#pragma endregion 
#pragma region Setters
	void SetStreet(std::string street);
	void SetCity(std::string city);
	void SetCodePost(std::string codepost);
	void SetHouseNum(std::string housenum);
#pragma endregion 
#pragma region Getters
	std::string GetStreet();
	std::string GetCity();
	std::string GetCodePost();
	std::string GetHouseNum();
#pragma endregion 
	friend std::ostream& operator<< (std::ostream &, Adress &);
	friend std::istream & operator >> (std::istream &, Adress &);
	
};