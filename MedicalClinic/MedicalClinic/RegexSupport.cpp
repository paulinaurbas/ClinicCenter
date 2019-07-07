#include "pch.h"
#include "RegexSupport.h"



std::string PostCodeRegex()
{
	bool ok = true;
	std::string PostCode1;
    std::regex PostCodeTemplate("^\\d{2}-\\d{3}$");
	while (ok)
	{
		std::cout << "PostCode: (Correct format: 00-000)" << std::endl;
		std::cin.clear();
		std::cin >> PostCode1;
		if (std::regex_match(PostCode1, PostCodeTemplate))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			
		}
		else
		{
			std::cout << "You enter wrong PostCode. Please try again! (Correct format: 00-000)" << std::endl;
		}
	}
	return PostCode1;
}
int OnlyNumberProc()
{
	int x; 
	while (!(std::cin >> x))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: ";
	}
	return x;
}
std::string OnlyLetterProc()
{
	bool ok = true;
	std::string output;
	std::regex LetterOnly("[a-zA-Z]+");
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, LetterOnly))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: only letters)" << std::endl;
		}
	}
	return output;
}
std::string RegexIDPacient()
{
	bool ok = true;
	std::regex CorrectID("^\\P\\d{3}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: P000)" << std::endl;
		}
	}
	return output;
}

std::string RegexIDDoctor()
{
	bool ok = true;
	std::regex CorrectID("^\\D\\d{3}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: D000)" << std::endl;
		}
	}
	return output;
}
std::string RegexIDVisit()
{
	bool ok = true;
	std::regex CorrectID("^\\V\\d{3}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: V000)" << std::endl;
		}
	}
	return output;
}
std::string RegexIDPrescription()
{
	bool ok = true;
	std::regex CorrectID("^(Pres)\\d{3}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: Pres000)" << std::endl;
		}
	}
	return output;
}
std::string RegexSexValidation()
{
	bool ok = true;
	std::regex CorrectID("^\\F|\\M");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: F (female) or M(male))" << std::endl;
		}
	}
	return output;
}
std::string RegexPeselValidation()
{
	bool ok = true;
	std::regex CorrectID("^\\d{11}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: 00000000000 - 11 numbers)" << std::endl;
		}
	}
	return output;
}
std::string RegexHouseNumber()
{
	bool ok = true;
	std::regex CorrectID("^\\d|\\d{2}|\\d/\\d$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: 0 or 0/0)" << std::endl;
		}
	}
	return output;
}
std::string RegexTime()
{
	//8-16.0-59
	bool ok = true;
	std::regex CorrectID("^([0-9]|())}.\\d{3}$");
	std::string output;
	while (ok)
	{
		std::cin.clear();
		std::cin >> output;
		if (std::regex_match(output, CorrectID))
		{
			ok = false;
			std::cout << "OK" << std::endl;
			break;
		}
		else
		{
			std::cout << "You enter incorrect format. Please try again! (Correct format: 0 or 0/0)" << std::endl;
		}
	}
	return output;
}

