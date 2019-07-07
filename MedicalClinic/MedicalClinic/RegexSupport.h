#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <regex>
#include <limits>

std::string PostCodeRegex();
int OnlyNumberProc(); 
std::string OnlyLetterProc();
std::string RegexIDPacient();
std::string RegexIDDoctor();
std::string RegexIDVisit();
std::string RegexIDPrescription();
std::string RegexPeselValidation();
std::string RegexSexValidation();
std::string RegexHouseNumber();
std::string RegexTime();
