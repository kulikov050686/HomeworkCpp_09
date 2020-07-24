#include "Task3.h"

void Task3::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string str[3];

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Введите " << i << " строку: ";
		std::getline(std::cin, str[i]);
		str[i] = RemoveSpaces(str[i]);
	}

	if (CorrectInput(str[0]) && CorrectInput(str[1]) && CorrectInput(str[2]))
	{
		int k = 0; // Общее количество крестиков
		int p = 0; // Общее количество ноликов

		for (int i = 0; i < 3; i++)
		{
			k += NumberOfSymbols(str[i], 'X');
			p += NumberOfSymbols(str[i], 'O');
		}

		if ((k == 3 && Victory(str, 'X') && p >= 4) || (p == 3 && Victory(str, 'O') && k >= 4))
		{
			std::cout << "Incorrect!!!" << std::endl;
		}
		else
		{
			if (std::abs(p - k) <= 1)
			{
				if (Victory(str, 'X'))
				{
					std::cout << "Petya won!!!" << std::endl;
				}
				else
				{
					if (Victory(str, 'O'))
					{
						std::cout << "Vanya won!!!" << std::endl;
					}
					else
					{
						std::cout << "Nobody!!!" << std::endl;
					}
				}
			}
			else
			{
				std::cout << "Incorrect!!!" << std::endl;
			}
		}		
	}
	else
	{
		std::cout << "Incorrect!!!" << std::endl;
	}	
}

bool Task3::CorrectInput(std::string str)
{
	bool key = true;

	if (str.length() == 3)
	{
		for (int i = 0; i < str.length() && key; i++)
		{
			key = key && AllowedSymbol(str[i]);
		}
	}
	else
	{
		return false;
	}

	return key;
}

bool Task3::AllowedSymbol(char chr)
{
	return (chr == 'O') ||
		   (chr == 'X') ||
		   (chr == '.');
}

bool Task3::Victory(const std::string *str, const char chr)
{
	for (int i = 0; i < 3; i++)
	{
		if (str[i][0] == chr && str[i][1] == chr && str[i][2] == chr)
		{
			return true;
		}

		if (str[0][i] == chr && str[1][i] == chr && str[2][i] == chr)
		{
			return true;
		}
	}

	if (str[0][0] == chr && str[1][1] == chr && str[2][2] == chr)
	{
		return true;
	}

	if (str[0][2] == chr && str[1][1] == chr && str[2][0] == chr)
	{
		return true;
	}	

	return false;
}
