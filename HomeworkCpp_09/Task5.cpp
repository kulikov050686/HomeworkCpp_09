#include "Task5.h"

void Task5::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string str;
	std::cout << "Введите email-адрес: ";
	std::getline(std::cin, str);

	if (NumberOfSymbols(str, '@') == 1 && 
		str[str.length() - 1] != '.' && 
		str[0] != '.' &&
		str[str.length() - 1] != '@' && 
		str[0] != '@' &&
		!RepeatingInRow(str,'.'))
	{
		std::string firstPart;
		std::string secondPart;
		bool key = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '@')
			{
				key = false;
				i++;
			}

			if(key)
			{
				firstPart += str[i];
			}
			else
			{
				secondPart += str[i];
			}
		}

		if (1 <= firstPart.length() && firstPart.length() <= 64 && 
			1 <= secondPart.length() && secondPart.length() <= 63)
		{
			key = true;

			for (int i = 0; i < firstPart.length() && key; i++)
			{
				key = key && ValidCharacterFirstPart(firstPart[i]);				
			}

			if (key)
			{
				for (int i = 0; i < secondPart.length() && key; i++)
				{
					key = key && ValidCharacterSecondPart(secondPart[i]);
				}

				if (key)
				{
					std::cout << "Введённый адрес корректен!!!" << std::endl;
				}
				else
				{
					std::cout << "Ошибка ввода данных!!!" << std::endl;
				}
			}
			else
			{
				std::cout << "Ошибка ввода данных!!!" << std::endl;
			}			
		}
		else
		{
			std::cout << "Превышена длина адреса!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

bool Task5::RepeatingInRow(std::string str, char chr)
{
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == chr && str[i + 1] == chr) return true;
	}

	return false;
}

bool Task5::ValidCharacterFirstPart(char chr)
{
	if ((48 <= chr && chr <= 57) || 
		(65 <= chr && chr <= 90) || 
		(97 <= chr && chr <= 122)||
		(35 <= chr && chr <= 39)||
		chr == 45 || 
		chr == 46 || 
		chr == 33 ||		
		chr == 42 || 
		chr == 43 || 
		chr == 47 || 
		chr == 61 || 
		chr == 63 || 
		chr == 94 || 
		chr == 95 ||
		chr == 96 || 
		chr == 123 || 
		chr == 124 || 
		chr == 125 || 
		chr == 126)
	{
		return true;
	}

	return false;
}

bool Task5::ValidCharacterSecondPart(char chr)
{
	if ((48 <= chr && chr <= 57) ||
		(65 <= chr && chr <= 90) ||
		(97 <= chr && chr <= 122) ||
		chr == 45 ||
		chr == 46)
	{
		return true;
	}

	return false;
}
