#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "RegexSupport.h"

class Patient : public Person
{
private: 
	std::string PatientID;
public:
	Patient();
	~Patient();
	Patient(Person p1, std::string PatientID);
	Patient(Person p1);
	void SetID(std::string PacientID);
	std::string GetID();
	Patient & operator=(const Patient &) = default;
	//virtual void Print(std::ostream & os) const override;
	friend std::ostream& operator<< (std::ostream &, Patient &);
	friend std::istream & operator >> (std::istream &, Patient &);
	static Patient NewElement();
};