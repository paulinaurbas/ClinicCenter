#include "pch.h"
#include <vector>
#include <string>

std::vector<std::string> ReturnMainMenu()
{
	std::vector<std::string> MainStringMenu
	{
		"> Doctor",
		"  Patient",
		"  Visit",
		"  Prescription",
		"  Quit"
	};
	return MainStringMenu;
}

std::vector<std::string> ReturnDoctorOption()
{
	std::vector<std::string> DoctiorOptionMenu
	{
		"> Add Doctor",
		"  Delete Doctor",
		"  Show Doctor schedule",
		"  Display Doctor Info",
		"  Back"
	};
	return DoctiorOptionMenu;
}

std::vector<std::string> ReturnPatientOption()
{
	std::vector<std::string> PatientOptionMenu
	{
		"> Add Patient",
		"  Delete Patient",
		"  Display Patient Info",
		"  Back"
	};
	return PatientOptionMenu;
}
std::vector<std::string> ReturnPrescriptionOption()
{
	std::vector<std::string> PrescriptionOptionMenu
	{
		"> Add Prescription",
		"  Delete Prescription",
		"  Back"
	};
	return PrescriptionOptionMenu;
}
std::vector<std::string> ReturnVisitOption()
{
	std::vector<std::string> VisitOptionMenu
	{
		"> Add Visit",
		"  Delete Visit",
		"  Book Visit",
		"  Show Visit Info",
		"  Back"
	};
	return VisitOptionMenu;
}