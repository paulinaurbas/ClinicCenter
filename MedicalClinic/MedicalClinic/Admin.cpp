#include "pch.h"
#include "Admin.h"
#pragma region Constructors & Destructors
Admin::Admin() : PatientList(std::map <std::string, Patient>()), DoctorList(std::map <std::string, Doctor>()), PrescriptionList(std::map <std::string, Prescripction>()), VisitList(std::map <std::string, Visit>())
{
	ReadFromFile("Patients.txt", PatientList);
	ReadFromFile("Doctors.txt", DoctorList);
	ReadFromFile("Prescription.txt", PrescriptionList);
	ReadFromFile("Visits.txt", VisitList);
}

Admin::~Admin()
{
	WriteToFile<Patient>("Patient2.txt", PatientList);
    WriteToFile<Doctor>("Doctors2.txt", DoctorList);
	WriteToFile<Prescripction>("Prescription2.txt", PrescriptionList);
	WriteToFile<Visit>("Visits2.txt", VisitList);
}
#pragma endregion
#pragma region Setters & Getters
Admin & Admin::GetInstance()
{
	static Admin instance;
	return instance;
}
std::map <std::string, Patient> * Admin::GetPatientList()
{
	return &(this->PatientList);
}
std::map <std::string, Doctor> * Admin::GetDoctorList()
{
	return &(this->DoctorList);
}
std::map <std::string, Prescripction> * Admin::GetPrescriptionList()
{
	return &(this->PrescriptionList);
}
std::map <std::string, Visit> * Admin::GetVisitList()
{
	return &(this->VisitList);
}
#pragma endregion 
#pragma region Patient
void Admin::FindPatientByID()
{
	
	std::cout << "Please enter patientID which you want find (Coreect format: P000)" << std::endl;
	std::string patienttemp = RegexIDPacient();
	auto pomc = this->PatientList.find(patienttemp);
	
}
void Admin::FindPatientByNameAndSurname()
{
	std::cout << "Please enter name which you want find (Coreect format: only letters)" << std::endl;
	std::string patienttempname = OnlyLetterProc();
	std::cout << "Please enter surname which you want find (Coreect format: only letters)" << std::endl;
	std::string patienttempsurname = OnlyLetterProc();
	std::string pom = FindIDByNameAndSurname(this->PatientList, patienttempname, patienttempsurname);
	if (pom == "null")
	{
		std::cout << "No Patient!" << std::endl;
	}
	else
	{
		DisplayInfoElement(this->PatientList, pom);
	}
}

void Admin::AddPatient()
{
	bool ok = true;
	while (ok)
	{
		std::cout << "Please enter patientID which you want add (Coreect format: P000)" << std::endl;
		std::string ID = RegexIDPacient();
		if (CheckIfIDExist(this->PatientList, ID) == false)
		{
			ok = false;
			AddElementToMap(this->PatientList, ID);
		}
		else
		{
			std::cout << "Patient with this ID already exist" << std::endl;
		}
	}
}

void Admin::DeletePatient()
{
	std::cout << "Please enter patientID which you want delete (Coreect format: P000)" << std::endl;
	std::string patienttemp = RegexIDPacient();
	if (CheckIfIDExist(this->PatientList, patienttemp) == true)
	{
		MoveFromMap(this->PatientList, patienttemp);
	}
	else
	{
		std::cout << "No patient!" << std::endl;
	}
	
}
void Admin::DisplayPatientInfo()
{
	int pom;
	std::string patienttemp;
	std::cout << "Do you want to find doctor by ID or Name and surname? If ID press 1, if name and surname press 2" << std::endl;
	std::cin >> pom;
	while (pom != 2 && pom != 1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: ";
		pom = OnlyNumberProc();
	}
	if (pom == 1)
	{
		std::cout << "Please enter patientID which you want display (Coreect format: P000)" << std::endl;
		patienttemp = RegexIDPacient();
		if (CheckIfIDExist(this->PatientList, patienttemp) == true)
		{
			DisplayInfoElement(this->PatientList, patienttemp);
		}
		else
		{
			std::cout << "No patient!" << std::endl;
		}
	}
	else
	{
		FindPatientByNameAndSurname();
	}

}
#pragma endregion
#pragma region Doctor
void Admin::FindDoctorByID()
{
	std::cout << "Please enter DoctorID which you want find (Coreect format: D000)" << std::endl;
	std::string DoctorID = RegexIDDoctor();
	this->DoctorList.find(DoctorID);
}
void Admin::FindDoctorByNameAndSurname()
{
	std::cout << "Please enter name which you want find (Coreect format: only letters)" << std::endl;
	std::string tempname = OnlyLetterProc();
	std::cout << "Please enter surname which you want find (Coreect format: only letters)" << std::endl;
	std::string tempsurname = OnlyLetterProc();
	std::string pom = FindIDByNameAndSurname(this->DoctorList, tempname, tempsurname);
	if (pom == "null")
	{
		std::cout << "No Doctor!" << std::endl;
	}
	else
	{
		DisplayInfoElement(this->DoctorList, pom);
	}
	
}
void Admin::AddDoctor()
{
	bool ok = true;
	while (ok)
	{
		std::cout << "Please enter DoctorID which you want add (Coreect format: D000)" << std::endl;
		std::string DoctorID = RegexIDDoctor();
		if (CheckIfIDExist(this->DoctorList, DoctorID) == false)
		{
			ok = false;
			AddElementToMap(this->DoctorList, DoctorID);
		}
		else
		{
			std::cout << "Doctor with this ID already exist" << std::endl;
		}
	}
}

void Admin::DeleteDoctor()
{
	std::cout << "Please enter DoctorID which you want delete (Coreect format: D000)" << std::endl;
	std::string DoctorID = RegexIDDoctor();
	if (CheckIfIDExist(this->DoctorList, DoctorID) == true)
	{
		DeleteDoctorVisit(this->VisitList, DoctorID);
		MoveFromMap(this->DoctorList, DoctorID);
		
	}
	else
	{
		std::cout << "No doctor!" << std::endl;
	}	
}

void Admin::ShowDoctorSchuedle()
{
	std::cout << "Please enter DoctorID which you want delete (Coreect format: D000)" << std::endl;
	std::string DoctorID = RegexIDDoctor();

	DisplayDoctor(this->VisitList, DoctorID);

}
void Admin::DisplayDoctorInfo()
{
		int pom;
		std::string DoctorID;
		std::cout << "Do you want to find doctor by ID or Name and surname? If ID press 1, if name and surname press 2" << std::endl;
		std::cin >> pom;
		while (pom != 2 && pom != 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try again: ";
			pom = OnlyNumberProc();
		}
		if (pom == 1)
		{
			std::cout << "Please enter DoctorID which you want display (Coreect format: D000)" << std::endl;
			DoctorID = RegexIDDoctor();
			if (CheckIfIDExist(this->DoctorList, DoctorID) == true)
			{
				DisplayInfoElement(this->DoctorList, DoctorID);
			}
			else
			{
				std::cout << "No doctor!" << std::endl;
			}
		}
		else
		{
			FindDoctorByNameAndSurname();
		}
	
	
}

#pragma endregion
#pragma region Prescription


void Admin::FindPrescription()
{
	std::cout << "Please enter Prescription ID which you want find (Coreect format: Pres000)" << std::endl;
	std::string PrescriptionID = RegexIDPrescription();
	this->DoctorList.find(PrescriptionID);
}
void Admin::AddPrescription()
{
	bool ok = true;
	while (ok)
	{
		std::cout << "Please enter Prescription ID which you want add (Coreect format: Pres000)" << std::endl;
		std::string PrescriptionID = RegexIDPrescription();
		if (CheckIfIDExist(this->PrescriptionList, PrescriptionID) == false)
		{
			ok = false;
			AddElementToMap(this->PrescriptionList, PrescriptionID);
		}
		else
		{
			std::cout << "Prescription with this ID already exist" << std::endl;
		}
	}
}
void Admin::DeletePrescription()
{
	std::cout << "Please enter Prescription ID which you want delete (Coreect format: Pres000)" << std::endl;
	std::string PrescriptionID = RegexIDPrescription();
	if (CheckIfIDExist(this->PrescriptionList, PrescriptionID) == true)
	{
		MoveFromMap(this->PrescriptionList, PrescriptionID);
	}
	else
	{
		std::cout << "No prescription" << std::endl;
	}

}
#pragma endregion
#pragma region Visit 

void Admin::FindVisit()
{
	std::cout << "Please enter VisitID which you want find (Coreect format: V000)" << std::endl;
	std::string VisitID = RegexIDVisit();
	this->VisitList.find(VisitID);
}
void Admin::AddVisit()
{
	bool ok = true;
	while (ok)
	{
		std::cout << "Please enter VisitID which you want add (Coreect format: V000)" << std::endl;
		std::string VisitID = RegexIDVisit();
		if (CheckIfIDExist(this->VisitList, VisitID) == false)
		{
			ok = false;
			AddElementToMap(this->VisitList, VisitID);
		}
		else
		{
			std::cout << "No visit!" << std::endl;
		}
	}
}

void Admin::DeleteVisit()
{
	std::cout << "Please enter VisitID which you want delete (Coreect format: V000)" << std::endl;
	std::string VisitID = RegexIDVisit();
	if (CheckIfIDExist(this->VisitList, VisitID) == true)
	{
		MoveFromMap(this->VisitList, VisitID);
	}
	else
	{
		std::cout << "No visit" << std::endl;
	}

}
void Admin::BookVisit()
{
	bool ok = true;
	while (ok)
	{
		std::cout << "Please enter DoctorID which you want visit (Coreect format: D000)" << std::endl;
		std::string DoctorID = RegexIDDoctor();
		if (CheckIfIDExist(this->DoctorList, DoctorID) == true)
		{
			std::string VisitID;
			ok = false;
			bool flag = true;
			while (flag)
			{
				bool pomoc = DisplayOnlyAnableVisit(this->VisitList, DoctorID);
				if (pomoc == true)
				{
					std::cout << "Please enter VisitID which you want book (Coreect format: V000)" << std::endl;
					VisitID = RegexIDVisit();
					if (CheckIfIDExist(this->VisitList, VisitID) == true)
					{
						flag = false;
						auto help = this->VisitList.find(VisitID);
						bool pom = true;
						while (pom)
						{
							std::cout << "Please enter PatientID which you want(Coreect format: P000)" << std::endl;
							std::string PatientID = RegexIDPacient();
							if (CheckIfIDExist(this->PatientList, PatientID) == true)
							{
								pom = false;
								help->second.SetPatient(PatientID);
								help->second.SetFree(false);
							}
							else
							{
								std::cout << "Patient with this ID doesn't exist" << std::endl;
							}
						}
					}
					else
					{
						std::cout << "Visit with this ID doesn't exist" << std::endl;
					
					}
				}
				else
				{
					std::cout << "Visit with this ID doesn't exist" << std::endl;
					flag = false;
				}
			}
		}
		else
		{
			std::cout << "Doctor with this ID doesn't exist" << std::endl;
		}

	}
}

void Admin::ShowVisitInfo()
{
	std::cout << "Please enter VisitID which you want display (Coreect format: V000)" << std::endl;
	std::string VisitID = RegexIDVisit();
	if (CheckIfIDExist(this->VisitList, VisitID) == true)
	{
		DisplayInfoElement(this->VisitList, VisitID);
	}
	else
	{
		std::cout << "No visit!" << std::endl;
	}
	
}
bool DisplayOnlyAnableVisit(std::map <std::string, Visit> & mapa, std::string DoctorID)
{
	bool help = false;
	for (auto iter = mapa.begin(); iter != mapa.end(); ++iter)
	{
		if (iter->second.GetFree() == true && iter->second.GetDoctor() == DoctorID)
		{
			std::cout << iter->second;
			help = true;
		}
	}
	return help;

}
void DisplayDoctor(std::map <std::string, Visit> & mapa, std::string DoctorID)
{
	for (auto iter = mapa.begin(); iter != mapa.end(); ++iter)
	{
		if (iter->second.GetDoctor() == DoctorID)
		{
			std::cout << iter->second;
		}
	}
}
void DeleteDoctorVisit(std::map <std::string, Visit> & mapa, std::string DoctorID)
{
	for (auto iter = mapa.begin(); iter != mapa.end(); ++iter)
	{
		if (iter->second.GetDoctor() == DoctorID)
		{
			iter->second.SetDoctor("0000");
		}
	}
}
#pragma endregion
