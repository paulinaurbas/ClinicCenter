#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
template <class T>

void readList(std::string nazwa) {
	std::fstream plik;
	plik.open(nazwa, std::ios::in);

	if (plik.good()) {
		T element;
		while (plik >> element) {
			std::cout << element;
		}
		plik.close();
	}
}
//szablon do odczytu do mapy z pliku
template <class T>
void ReadFromFile(std::string name, std::map<std::string, T> & mapa)
{
	std::fstream file;
	file.open(name, std::ios::in);
	try
	{
		if (file.good()) {
			bool ok = true;
			while (ok) {
				T element;
				if (!(file >> element)) {
					ok = false;
				}
				else {
					mapa.insert(std::make_pair(element.GetID(), element));
				}
			}
			file.close();
		}
	}
	catch (...)
	{
		throw "Read from File error";
		file.close();
	}
	
}
	/*if (file.good()) {
		bool ok = true;
		while (ok) {
			T element;
			//if (!(file >> element)) {
			//	ok = false;
			//}
			//else {
				mapa.insert(std::make_pair(element.GetID(), element));
			//}
		}
		file.close();
	}
}*/
	
	/*
	if (file.good()) {
		bool ok = true;
		while (ok) {
			T element;
			if (!(file >> element)) {
				ok = false;
			}
			else {
				list.push_back(element);
			}
		}
		file.close();
	}
	return true;

*/

//szablon do zapisu do pliku mapy 
template<class T>
void WriteToFile(std::string fileName, std::map<std::string,T>& map)
{
	
	std::fstream file;
	file.open(fileName, std::ios::out);
	try
	{
		if (file.good())
		{
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				file << iter->second;
			}
			/*
			typename std::list<T>::iterator it;
			for (it = list.begin(); it != list.end(); it++)
			{
				file << *it;
			}
			file.close();
			*/
		}
	}
	catch (...)
	{
		throw "Write from File error";
	}

}

