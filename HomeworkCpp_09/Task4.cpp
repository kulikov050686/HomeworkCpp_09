#include "Task4.h"

void Task4::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	
	std::cout << "Введите действительное число: ";
	std::cin >> strNumber;

	if (NumberCheck(strNumber))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
}

bool Task4::NumberCheck(std::string number)
{
	int point = 0;	
	std::string strIntegerPart;    // целая часть действительного числа
	std::string strFractionalPart; // дробная часть действительного числа
	bool bFractionalPart = false;
	
	number = RemoveSpaces(number);

	bool key = true;

	for (int i = 0; i < number.length() && key; i++)
	{
		if (Numeral(number[i]))
		{
			key = false;
		}
	}

	if (key)
	{
		return false;
	}

	if (number[number.length() - 1] == '.')
	{
		number += '0';
	}

	for (int i = 0; i < number.length(); i++)
	{
		if (i == 0)
		{
			if (number[0] == '-')
			{
				number.erase(0, 1);				
			}
			else
			{
				if (number[0] == '+')
				{
					number.erase(0, 1);					
				}
			}
		}
		
		if (number[i] == '.')
		{
			point++;
			bFractionalPart = true;
			i++;
		}

		if (point >= 2)
		{
			return false;
		}
		
		if (bFractionalPart)
		{
			strFractionalPart += number[i];
		}
		else
		{
			strIntegerPart += number[i];
		}		
	}

	strIntegerPart = RemoveZeros(strIntegerPart);

	if (strIntegerPart == "")
	{
		strIntegerPart += '0';
	}
	
	bool key1 = true;
	bool key2 = true;

	for (int i = 0; i < strFractionalPart.length() && key1; i++)
	{
		key1 = key1 && Numeral(strFractionalPart[i]);
	}

	for (int i = 0; i < strIntegerPart.length() && key2; i++)
	{
		key2 = key2 && Numeral(strIntegerPart[i]);
	}

	return key1 && key2;
}

std::string Task4::RemoveZeros(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			str.erase(i, 1);
			i--;
		}
		else
		{
			break;
		}
	}

	return str;
}
