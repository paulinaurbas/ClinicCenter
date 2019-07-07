#include "pch.h"
#include <iostream>
#include <string>
#include "Prescripction.h"
#pragma region Constructors & Destructors
Prescripction::Prescripction(Date d1, std::string DoctorID, std::string PatientID, std::string PrescriptionID, std::string drug, std::string dose, std::string dosage)
	: Date(d1), DoctorID(DoctorID), PatientID(PatientID), PrescriptionID(PrescriptionID), drug(drug), dose(dose), dosage(dosage)
{

}
Prescripction::Prescripction() {

}
Prescripction::~Prescripction()
{

}
#pragma endregion
#pragma region Setter
void Prescripction::SetDrug(std::string drug)
{
	this->drug = drug;
}
void Prescripction::SetDose(std::string dose)
{
	this->dose = dose;
}
void Prescripction::SetDosage(std::string dosage)
{
	this->dosage = dosage;
}
void Prescripction::SetDoctorID(std::string DoctorID)
{
	this->DoctorID = DoctorID;
}
void Prescripction::SetPatientID(std::string PacientID)
{
	this->PatientID = PacientID;
}
void Prescripction::SetID(std::string PrescriptionID)
{
	this->PrescriptionID = PrescriptionID;
}
#pragma endregion
#pragma region Getters
std::string Prescripction::GetDrug()
{
	return this->drug;
}
std::string Prescripction::GetDose()
{
	return this->dose;
}
std::string Prescripction::GetDosage()
{
	return this->dosage;
}
std::string Prescripction::GetDoctorID()
{
	return this->DoctorID;
}
std::string Prescripction::GetPatientID()
{
	return this->PatientID;
}
std::string Prescripction::GetID()
{
	return this->PrescriptionID;
}
#pragma endregion

void Prescripction::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << this->day << " " << this->month << " " << this->year << " " << this->hour << " " << this->drug << " " << this->dose << " " << this->dosage << " " << this->DoctorID << std::endl;
}

std::istream & operator >> (std::istream & in, Prescripction & p1)
{
	Date &b(p1);
	in >> b;
	in >> p1.DoctorID;
	in >> p1.PatientID;
	in >> p1.drug;
	in >> p1.dose;
	in >> p1.dosage;
	return in;
}
Prescripction Prescripction::NewElement()
{
	Date date;
	date.NewElement();
	std::string PrescriptionID1;
	std::cout << "Patient ID: " << std::endl;
	std::string PatientID1 = RegexIDPacient();
	std::cout << "Doctor ID: " << std::endl;
	std::string DoctorID1 = RegexIDDoctor();
	std::cout << "Prescription ID: " << std::endl;
	std::cin >> PrescriptionID1;
	std::cout << "Drug " << std::endl;
	std::string drug1 = OnlyLetterProc();
	std::cout << "Dose " << std::endl;
	std::string dose1;
	std::cin >> dose1;
	std::cout << "Dosage " << std::endl;
	std::string dosage1;
	std::cin >> dosage1;
	Prescripction pp(date, DoctorID1, PatientID1, PrescriptionID1, drug1, dose1, dosage1);
	return pp;
}