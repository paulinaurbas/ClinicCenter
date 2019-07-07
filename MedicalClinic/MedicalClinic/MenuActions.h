#pragma once
#include "menu.h"
#include "Admin.h"
#include <Windows.h>
//sprawdzenie czy mozna wyjsc 
bool IsEscape(const KEY_EVENT_RECORD key);
//funckja sprawdzajaca czy koniec menu 
bool IsFinished(const MenuType CurrentType, const Menu menu);
//funkcja sprawdzajaca akcje menu
void MainMenuAction(Menu & menu, KEY_EVENT_RECORD & key);
//menu pacjent
void PatientMenuAction(Menu & menu, Admin & acc);
//menu doctor
void DoctorMenuAction(Menu & menu, Admin & acc);
//menu recept
void PrescriptionMenuAction(Menu & menu, Admin & acc);
//menu wizyt
void VisitMenuAction(Menu & menu, Admin & acc);
//funkcja do wyboru typu menu
void SwitchMenu(MenuType & CurrentType, Menu & menu, KEY_EVENT_RECORD & key, Admin & acc);
//funckja do wyboru akcji w menu
void ChooseAction(Menu & menu, KEY_EVENT_RECORD & key);
//funkcja do w³aczenia menu 
void RunMenu(Menu & menu, Admin & acc);