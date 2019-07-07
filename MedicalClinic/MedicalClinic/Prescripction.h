#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "AdminHelper.h"
class Prescripction : public Date, public IPrintable
{
private:
	std::string DoctorID;
	std::string PatientID;
	std::string PrescriptionID;
	std::string drug;
	std::string dose;
	std::string dosage;
public:
#pragma region Constructors & destructors 
	Prescripction();
	Prescripction(Date d1, std::string DoctorID, std::string PatientID,	std::string PrescriptionID,	std::string drug, std::string dose, std::string dosage);
	~Prescripction();
#pragma endregion
#pragma region Setter
	void SetDrug(std::string drug);
	void SetDose(std::string dose);
	void SetDosage(std::string dosage);
	void SetDoctorID(std::string);
	void SetPatientID(std::string);
	void SetID(std::string);
#pragma endregion
#pragma region Getters
	std::string GetDrug();
	std::string GetDose();
	std::string GetDosage();
	std::string GetDoctorID();
	std::string GetPatientID();
	std::string GetID();
#pragma endregion
	Prescripction & operator=(const Prescripction &) = default;
	virtual void Print(std::ostream & os) const override;
	friend std::istream & operator >> (std::istream &, Prescripction &);
	static Prescripction NewElement();
};




