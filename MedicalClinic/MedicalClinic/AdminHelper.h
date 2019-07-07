#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include "Patient.h"
#include "Doctor.h"
#include "Prescripction.h"
#include "Visit.h"
#pragma region Templets 
template <class T>
//szablon wyswietlanie mapy
void Display(std::map<std::string, T> * map)
{
	for (auto iter = map.begin(); iter != map.end(); ++iter)
	{
	 std::cout << iter->second;
	}
}
//szablon dodawanie elementu do mapy
template <class T>
void AddElementToMap(std::map<std::string, T> & mapa, std::string IDFormUser)
{
	T element = T::NewElement();
	element.SetID(IDFormUser);
	mapa.insert(std::make_pair(IDFormUser, element));

}
//szablon usuwanie z mapy 
template <class T>
void MoveFromMap(std::map<std::string, T> & mapa, std::string IDToFind)
{
	typename std::map<std::string, T>::iterator it;
	it = mapa.find(IDToFind);
	mapa.erase(it);
}
//szablon do wyswietlania danych 
template <class T>
void DisplayInfoElement(std::map<std::string, T> & mapa, std::string IDToFind)
{
	typename std::map<std::string, T>::iterator it;
	it = mapa.find(IDToFind);
	std::cout << it->second << std::endl;
}
//szablon znajdowanie po imiemieniu i nazwisku 
template <class T> 
std::string FindIDByNameAndSurname(std::map<std::string, T> & mapa, std::string name, std::string surname)
{
	std::string pom = "null";
	typename std::map<std::string, T>::iterator it;
	for (it = mapa.begin(); it != mapa.end(); ++it)
	{
		if (it->second.GetName() == name && it->second.GetSurname() == surname)
		{
			return it->first;
		}
	}
	return pom;
}
//szablon sprawdzanie czy istnieje w mapie element o takim ID 
template <class T>
bool CheckIfIDExist(std::map<std::string, T> & mapa, std::string id)
{
	return mapa.find(id) != mapa.end();
}

#pragma endregion 
#pragma region Function
std::string AskUserForName();
std::string AskUserForSurname();
#pragma endregion 