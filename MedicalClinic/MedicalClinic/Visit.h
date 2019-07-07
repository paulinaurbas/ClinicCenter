#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include "Prescripction.h"
#include "IPrintable.h"
#include "RegexSupport.h"

class Visit : public Date
{
private:
	std::string VisitID;
	std::string PatientID;
	std::string DoctorID;
	std::string PrescriptionID;
	bool Free;
	/*std::shared_ptr<Patient> patient = std::make_shared<Patient>();
	std::shared_ptr<Doctor> doctor = std::make_shared<Doctor>();
	std::shared_ptr<Prescripction> prescription = std::make_shared<Prescripction>();
	*/
public:
	Visit();
	Visit(Date d1, std::string PatientID, std::string DoctorID, std::string VisitID, std::string Presc, bool free);
	~Visit();
	void SetPatient(std::string );
	void SetDoctor(std::string );
	void SetPrescripction(std::string);
	void SetID(std::string);
	void SetFree(bool);
	std::string GetPatient();
	std::string GetDoctor();
	std::string GetPrescription();
	std::string GetID();
	bool GetFree();
	/*void SetPatient(std::shared_ptr<Patient>);
	void SetDoctor(std::shared_ptr<Doctor>);
	void SetPrescripction(std::shared_ptr<Prescripction>);
	void SetVisitID(int VisitID);
	std::shared_ptr<Patient> GetPatient();
	std::shared_ptr<Doctor> GetDoctor();
	std::shared_ptr<Prescripction> GetPrescription();
	int GetVisitID();
	*/
	//virtual void Print(std::ostream & os) const override;
	friend std::ostream& operator<< (std::ostream &, Visit &);
	friend std::istream & operator >> (std::istream &, Visit &);
	static Visit NewElement();
};