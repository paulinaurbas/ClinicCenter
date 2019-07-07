#include "pch.h"
#include <iostream>
#include <string>
#include "Patient.h"

Patient::Patient()
{

}
Patient::Patient(Person p1, std::string PatientID)
{
	this->Name = p1.GetName();
	this->Surname = p1.GetSurname();
	this->Age = p1.GetAge();
	this->PESEL = p1.GetPesel();
	this->adress = p1.GetAdress();
	this->PatientID = PatientID;
}
Patient::Patient(Person p1)
{
	this->Name = p1.GetName();
	this->Surname = p1.GetSurname();
	this->Age = p1.GetAge();
	this->PESEL = p1.GetPesel();
	this->adress = p1.GetAdress();
	this->sex = p1.GetSex();
}
Patient::~Patient()
{

}
void Patient:: SetID(std::string PacientID)
{
	this->PatientID = PacientID;
}
std::string Patient::GetID()
{
	return this->PatientID;
}
/*/
void Patient::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << this->Name << " " << this->Surname << " " << this->Age << " " << this->sex << " " << this->PatientID << std::endl;
}*/
std::ostream& operator<< (std::ostream & out, Patient & patient)
{
	out << patient.Name << " " << patient.Surname << " " << patient.Age << " " <<patient.PESEL <<" "<< patient.sex << " " << patient.adress->GetStreet() << " " << patient.adress->GetCity()<< " " << patient.adress->GetCodePost() << " " << patient.adress->GetHouseNum()<< " "<<patient.PatientID << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, Patient & patient)
{
	Person &b(patient);
	in >> b;
	in >> patient.PatientID;
	return in;
}
 Patient Patient::NewElement()
{
	Person pp;
	pp.NewElement();
	//std::cout << "ID: " << std::endl;
//	std::string PatientID = RegexIDPacient();
	//Patient p1(pp, PatientID);
	Patient p1(pp);

	return p1; 
}