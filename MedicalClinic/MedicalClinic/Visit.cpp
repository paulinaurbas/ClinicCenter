#include "pch.h"
#include "Visit.h"

Visit::Visit()
{
}
Visit::Visit(Date d1, std::string PatientID, std::string DoctorID, std::string VisitID, std::string Presc, bool free) : Date(d1), PatientID(PatientID), DoctorID(DoctorID), VisitID(VisitID), PrescriptionID(Presc), Free(free)
{
}
/*
Visit::Visit(int day, int month, int year, std::string hour, std::shared_ptr<Patient> patient1, std::shared_ptr<Doctor> doctor1, std::shared_ptr<Prescripction> prescription1)
	: Date(day, month, year, hour), patient(patient1), doctor(doctor1), prescription(prescription1)
{

} */
Visit::~Visit()
{

}
void Visit::SetFree(bool help)
{
	this->Free = help;
}
void Visit::SetPatient(std::string PatientID)
{
	this->PatientID = PatientID;
}
void Visit::SetDoctor(std::string DoctorID)
{
	this->DoctorID = DoctorID;
}
void Visit::SetID(std::string VisitID)
{
	this->VisitID = VisitID;
}
void Visit::SetPrescripction(std::string Presc)
{
	this->PrescriptionID = Presc;
}
std::string Visit::GetPatient()
{
	return this->PatientID;
}
std::string Visit::GetDoctor()
{
	return this->DoctorID;
}
std::string Visit::GetPrescription()
{
	return this->PrescriptionID;
}
std::string Visit::GetID()
{
	return this->VisitID;
}
bool Visit::GetFree()
{
	return this->Free;
}
/*
void Visit::SetPatient(std::shared_ptr<Patient> p1)
{
	this->patient = p1;
}
void Visit::SetDoctor(std::shared_ptr<Doctor> d1 )
{
	this->doctor = d1;
}
void Visit::SetPrescripction(std::shared_ptr<Prescripction> pre1)
{
	this->prescription = pre1;
}
void Visit::SetVisitID(int VisitID)
{
	this->VisitID = VisitID;
}
std::shared_ptr<Patient> Visit::GetPatient()
{
	return this->patient;
}
std::shared_ptr<Doctor> Visit::GetDoctor()
{
	return this->doctor;
}
std::shared_ptr<Prescripction> Visit::GetPrescription()
{
	return this->prescription;
}
int Visit::GetVisitID()
{
	return this->VisitID;
}*/
/*void Visit::Print(std::ostream & os) const
{
	os.precision(2);
	os << std::fixed;
	os << "Visit: " << this->day << " " << this->month << " " << this->year << " " << this->hour << " " << this->DoctorID<< " " << this->PatientID << " " << this->VisitID << " " << this->VisitID << std::endl;
}*/
std::ostream& operator<< (std::ostream & os, Visit & v1)
{
	os << v1.day << " " << v1.month << " " << v1.year << " " << v1.hour << " " << v1.DoctorID << " " << v1.PatientID<< " " << v1.VisitID << " " << v1.Free << " " << v1.PrescriptionID << std::endl;
	return os;
}
std::istream & operator >> (std::istream & in, Visit & v1)
{
	Date &b(v1);
	in >> b;
	in >> v1.DoctorID;
	in >> v1.PatientID;
	in >> v1.VisitID;
	in >> v1.Free;
	in >> v1.PrescriptionID;
	/*
	Patient p1;
	in >> p1;
	Doctor d1;
	in >> d1;
	Prescripction pr1;
	in >> pr1;
	std::shared_ptr<Doctor> d2 = std::make_shared<Doctor>(d1);
	v1.SetDoctor(d2);
	std::shared_ptr<Patient> p2 = std::make_shared<Patient>(p1);
	v1.SetPatient(p2);
	std::shared_ptr<Prescripction> pr2 = std::make_shared<Prescripction>(pr1);
	v1.SetPrescripction(pr2);*/
	return in;	
}
Visit Visit::NewElement()
{
	Date date;
	date.NewElement();
	bool Free1;
	//std::cout << "Patient ID: " << std::endl;
	//std::string PatientID1 = RegexIDPacient();
	std::string PatientID1 = "0000";
	std::cout << "Doctor ID: " << std::endl;
	std::string DoctorID1 = RegexIDDoctor();
	std::cout << "Visit ID: " << std::endl;
	std::string VisitID1 = RegexIDVisit();
//	std::cout << "Prescription ID: " << std::endl;
//	std::string PrescriptionID1 = RegexIDPrescription();
	std::string PrescriptionID1 = "0000";
	std::cout << "Is it free?: " << std::endl;
	std::cin >> Free1;
	Visit vv(date, PatientID1, DoctorID1, VisitID1, PrescriptionID1, Free1);
	return vv;
}