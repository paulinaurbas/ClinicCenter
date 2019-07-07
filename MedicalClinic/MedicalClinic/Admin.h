#pragma once
#include "pch.h"
#include <iterator>
#include <list>
#include <map>
#include "Patient.h"
#include "Doctor.h"
#include "Visit.h"
#include "Prescripction.h"
#include "File.h"
#include "AdminHelper.h"
class Admin
{
/** Deklaracja Klasy Admin, singleton
@author Paulina Urbas
*/
private:
	std::map <std::string, Patient> PatientList;
	std::map <std::string,Doctor> DoctorList;
	std::map <std::string, Visit> VisitList;
	std::map <std::string, Prescripction> PrescriptionList;
	//prywatny konstruktor wed³ug wzorca signleton
	Admin();
public:
/** Konstruktory i destruktory
@author Paulina Urbas
*/
	~Admin();
	static Admin & GetInstance();
	std::map <std::string, Patient> * GetPatientList();
	std::map <std::string, Doctor> * GetDoctorList();
	std::map <std::string, Visit> * GetVisitList();
	std::map <std::string, Prescripction> * GetPrescriptionList();
#pragma region patient
	/** Metoda znajduj¹ca pacjenta po ID
		@author Paulina Urbas
		*/
	void FindPatientByID();
	/** Metoda znajduj¹ca pacjenta po imieniu i nazwisku 
		@author Paulina Urbas
		*/
	void FindPatientByNameAndSurname();
	/** Metoda dodajca pacjenta po ID
		@author Paulina Urbas
		*/
	void AddPatient();
	/** Metoda usuwajaca pacjenta po ID
		@author Paulina Urbas
		*/
	void DeletePatient();
	/** Metoda wyswietlajaca informacje o pacjencie
		@author Paulina Urbas
		*/
	void DisplayPatientInfo();
#pragma endregion
#pragma region doctor
	/** Metoda znajduj¹ca lekarza po ID
	@author Paulina Urbas
	*/
	void FindDoctorByID();
	/** Metoda znajduj¹ca lekarza po imieniu i nazwisku
@author Paulina Urbas
*/
	void FindDoctorByNameAndSurname();
	/** Metoda dodajca lekarza po ID
		@author Paulina Urbas
		*/
	void AddDoctor();
	/** Metoda usuwaj¹ca lekarza po ID
		@author Paulina Urbas
		*/
	void DeleteDoctor();
	/** Pokazuj¹ca plan wizyt danego lekarza
		@author Paulina Urbas
		*/
	void ShowDoctorSchuedle();
	/** Metoda wyœwietlajca informacje o lekarzu
		@author Paulina Urbas
		*/
	void DisplayDoctorInfo();
#pragma endregion
#pragma region prescription
	/** Metoda znajdujaca recepte
		@author Paulina Urbas
		*/
	void FindPrescription();
	/** Metoda dodajca recepte
		@author Paulina Urbas
		*/
	void AddPrescription();
	/** Metoda usuwajaca recepte
		@author Paulina Urbas
		*/
	void DeletePrescription();
#pragma endregion
#pragma region Visit 
	/** Metoda znajdujaca wizyte
		@author Paulina Urbas
		*/
	void FindVisit();
	/** Metoda dodajca wizyte
		@author Paulina Urbas
		*/
	void AddVisit();
	/** Metoda usuwajaca wizyte
		@author Paulina Urbas
		*/
	void DeleteVisit();
	/** Metoda rezerwujaca wizyte
		@author Paulina Urbas
		*/
	void BookVisit();
	/** Metoda pokazujaca wizyty
		@author Paulina Urbas
		*/
	void ShowVisitInfo();
#pragma endregion
};
/** Metoda wyswietlajaca jedynie wolne wizyty
		@author Paulina Urbas
		*/
bool DisplayOnlyAnableVisit(std::map <std::string, Visit> & mapa, std::string DoctorID);
/** Metoda wyswietlajaca lekarza znajdujacego sie w liscie
		@author Paulina Urbas
		*/
void DisplayDoctor(std::map <std::string, Visit> & mapa, std::string DoctorID);
/** Metoda usuwajaca doktora z wizyty
		@author Paulina Urbas
		*/
void DeleteDoctorVisit(std::map <std::string, Visit> & mapa, std::string DoctorID);