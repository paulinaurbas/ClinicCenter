#include "pch.h"
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Person.h"
Doctor::Doctor()
{

}
Doctor::Doctor(std::string name, std::string surname, int Age, std::string pesel, std::shared_ptr<Adress> adress, std::string sex, std::string DoctorID, std::string specialization)
{
	this->Name = name;
	this->Surname = surname;
	this->Age = Age;
	this->PESEL = pesel;
	this->adress = adress;
	this->sex = sex;
	this->DoctorID = DoctorID;
	this->specialization = specialization;
}
Doctor::Doctor(Person p1, std::string DoctorID, std::string specialization)
{
	this->Name = p1.GetName();
	this->Surname = p1.GetSurname();
	this->Age = p1.GetAge();
	this->PESEL = p1.GetPesel();
	this->adress = p1.GetAdress();
	this->sex = p1.GetSex();
	this->DoctorID = DoctorID;
	this->specialization = specialization;
}
Doctor::Doctor(Person p1, std::string specialization)
{
	this->Name = p1.GetName();
	this->Surname = p1.GetSurname();
	this->Age = p1.GetAge();
	this->PESEL = p1.GetPesel();
	this->adress = p1.GetAdress();
	this->sex = p1.GetSex();
	this->specialization = specialization;
}
Doctor::~Doctor()
{

}
std::string Doctor::GetID()
{
	return this->DoctorID;
}
std::string Doctor:: GetSpecialization()
{
	return this->specialization;
}
void Doctor::SetID(std::string DoctorID)
{
	this->DoctorID = DoctorID;
}
void Doctor::SetDoctorSpecialization(std::string specialization)
{
	this->specialization = specialization;
}
/*
void Doctor::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << this->Name << " " << this->Surname << " " << this->Age << " " << this->sex << " " << this->DoctorID << " " << this->specialization << std::endl;

}*/
std::ostream& operator<< (std::ostream & out, Doctor & d1)
{
	out << d1.Name << " " << d1.Surname << " " << d1.Age << " " << d1.sex << " " << d1.adress->GetStreet() << " " << d1.adress->GetCity() << " " << d1.adress->GetCodePost() << " " << d1.adress->GetHouseNum() << " "	<< d1.DoctorID << " " << d1.specialization << std::endl;
	return out;
}
std::istream & operator >> (std::istream & in , Doctor & d2)
{
	Person &b(d2);
	in >> b;
	in >> d2.DoctorID;
	in >> d2.specialization;
	return in;
}
Doctor Doctor::NewElement()
{
	Person p1;
	p1.NewElement();
	//std::cout << "ID: " << std::endl;
	//std::string Doctorid = RegexIDDoctor();
	std::cout << "Specialization: " << std::endl;
	std::string Specialization = OnlyLetterProc();
	//Doctor D1(p1, Doctorid, Specialization);
	Doctor D1(p1, Specialization);
	return D1;
}