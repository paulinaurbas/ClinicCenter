#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "RegexSupport.h"

class Doctor: public Person
{
private:
	std::string DoctorID;
	std::string specialization;
public:
	Doctor();
	Doctor(Person p1, std::string DoctorID, std::string specialization);
	Doctor(Person p1, std::string specialization);
	~Doctor();
	Doctor(std::string name, std::string surname, int Age, std::string pesel, std::shared_ptr<Adress> adress, std::string sex, std::string DoctorID, std::string specialization);
	void SetID(std::string DoctorID);
	void SetDoctorSpecialization(std::string specialization);
	std::string GetID();
	std::string GetSpecialization();
	Doctor & operator=(const Doctor &) = default;
	//virtual void Print(std::ostream & os) const override;
    friend std::ostream& operator<< (std::ostream &, Doctor &);
	friend std::istream & operator >> (std::istream &, Doctor &);
	static Doctor NewElement();
};