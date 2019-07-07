#include "pch.h"
#include "menu.h"
#include "display.h"
#include "MenuOption.h"
#include "MenuActions.h"
#include "Admin.h"
#include <list>
#include "File.h"
bool IsEscape(const KEY_EVENT_RECORD key)
{
	bool escape_clicked = true;
	if (key.wVirtualKeyCode == VK_ESCAPE)
	{
		escape_clicked = true;
	}
	else
	{
		escape_clicked = false;
	}
	return escape_clicked;
}
bool GetConchar(KEY_EVENT_RECORD& krec)
{
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL)
	{
		return false; // console not found
	}

	for (; ;)
	{
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false;
}
bool IsFinished(const MenuType CurrentType, const Menu menu)
{
	bool IsFinished = false;
	if (CurrentType == MAIN)
	{
		if (menu.GetIndex() == 4)
		{
			IsFinished = true;
		}
	}
	return IsFinished;
	
}

void MainMenuAction(Menu & menu, KEY_EVENT_RECORD & key)
{
	
	switch (menu.GetIndex())
	{
	case 0:
		menu.SetVector(ReturnDoctorOption());
		menu.SetMenuType(DOCTOR);
		break;
	case 1:
		menu.SetVector(ReturnPatientOption());
		menu.SetMenuType(PATIENT);
		break;
	case 2:
		menu.SetVector(ReturnVisitOption());
		menu.SetMenuType(VISIT);
		break;
	case 3:
		menu.SetVector(ReturnPrescriptionOption());
		menu.SetMenuType(PRESCRIPTION);
		break;
	case 5:
		key.wVirtualKeyCode = VK_ESCAPE;
		break;
	default:
		break;
	}

}

void PatientMenuAction(Menu & menu, Admin & acc)
{
	switch (menu.GetIndex())
	{
	case 0:
	//add patient
		acc.AddPatient();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 1:
	//detele patient
		acc.DeletePatient();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 2:
		//display patient info
		acc.DisplayPatientInfo();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 3:
		menu.SetVector(ReturnMainMenu());
		menu.SetMenuType(MAIN);
		break;
	default:
		break;
	}
}

void DoctorMenuAction(Menu & menu, Admin & acc)
{
	switch (menu.GetIndex())
	{
	case 0:
		//add doctor
		acc.AddDoctor();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 1:
		//detele doctor
		acc.DeleteDoctor();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 2:
		//show doctor shedule
		acc.ShowDoctorSchuedle();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 3:
		//display doctorInfo
		acc.DisplayDoctorInfo();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 4:
		menu.SetVector(ReturnMainMenu());
		menu.SetMenuType(MAIN);
		break;
	default:
		break;
	}
}
void PrescriptionMenuAction(Menu & menu, Admin & acc)
{
	switch (menu.GetIndex())
	{
	case 0:
		//add prescription
		acc.AddPrescription();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 1:
		//detele prescription
		acc.DeletePrescription();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 2:
		menu.SetVector(ReturnMainMenu());
		menu.SetMenuType(MAIN);
		break;
	default:
		break;
	}
}void VisitMenuAction(Menu & menu, Admin & acc)
{
	switch (menu.GetIndex())
	{
	case 0:
		//add visit
		acc.AddVisit();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 1:
		//detele visit
		acc.DeleteVisit();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 2:
		//book visit
		acc.BookVisit();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 3:
		//show visit info
		acc.ShowVisitInfo();
		std::cin.get();
		std::cout << "Press Enter to Continue" << std::endl;
		std::cin.get();
		break;
	case 4:
		menu.SetVector(ReturnMainMenu());
		menu.SetMenuType(MAIN);
		break;
	default:
		break;
	}
}
void SwitchMenu(MenuType & CurrentType, Menu & menu, KEY_EVENT_RECORD & key, Admin & acc)
{
	switch (CurrentType)
	{
	case MAIN:
		MainMenuAction(menu, key);
		break;
	case PATIENT:
		PatientMenuAction(menu, acc);
		break;
	case DOCTOR:
		DoctorMenuAction(menu, acc);
		break;
	case PRESCRIPTION:
		PrescriptionMenuAction(menu,acc);
		break;
	case VISIT:
		VisitMenuAction(menu, acc);
		break;
	default:
		break;
	}
}

void ChooseAction(Menu & menu, KEY_EVENT_RECORD & key)
{
	do
	{
		ClearScreen();
		menu.show();
		GetConchar(key);
		menu.MoveArrow();

	} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE && key.wVirtualKeyCode != VK_ESCAPE);
	
	}

void RunMenu(Menu & menu, Admin & acc)
{
	
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	menu.SetVector(ReturnMainMenu());

	do
	{
		menu.SetIndex(0);
		MenuType CurrentType = menu.GetMenuType();

		ChooseAction(menu, key);
		SwitchMenu(CurrentType, menu, key, acc);

		if (IsFinished(CurrentType, menu))
			break;

	} while (!IsEscape(key));

}
