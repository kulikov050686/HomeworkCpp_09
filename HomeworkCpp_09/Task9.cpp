#include "Task9.h"

void Task9::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string str;

	std::cout << "Введите два действительных числа разделённых пробелом: ";
	std::getline(std::cin, str);

	if (WordCount(str) == 2)
	{
		if (TaskBase::NumberOfSymbols(str,'.') <= 2)
		{
			strNumber1 = StringWord(str, 1);
			strNumber2 = StringWord(str, 2);

			double number1;
			double number2;

			if (ToDouble(strNumber1, number1) && ToDouble(strNumber2, number2))
			{
				if (number1 < number2)
				{
					std::cout << "Less" << std::endl;
				}

				if (number1 > number2)
				{
					std::cout << "More" << std::endl;
				}

				if (number1 == number2)
				{
					std::cout << "Equal" << std::endl;
				}
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
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

std::string Task9::StringWord(std::string str, int number)
{
	if (str.length() > 0 && number > 0)
	{
		bool k = false;
		int m = 0;
		std::string temp;
		str += ' ';

		for (int i = 0; i <str.length(); i++)
		{
			if (str[i] == ' ')
			{
				if (k)
				{
					m++;

					if (number == m)
					{
						return temp;
					}

					temp = "";
				}

				k = false;
			}
			else
			{
				k = true;

				temp += str[i];
			}
		}
	}

	return "";
}

bool Task9::ToDouble(std::string strNumber, double& number)
{
	int point = 0;
	int sign = 1;                  // Знак числа
	std::string strIntegerPart;    // целая часть действительного числа
	std::string strFractionalPart; // дробная часть действительного числа
	bool bFractionalPart = false;
	double result;
	int numeral = 0;
	double temp = 0;

	if (strNumber[strNumber.length() - 1] == '.')
	{
		strNumber += '0';
	}

	for (int i = 0; i < strNumber.length(); i++)
	{
		if (i == 0)
		{
			if (strNumber[0] == '-')
			{
				strNumber.erase(0, 1);
				sign = -1;
			}
			else
			{
				if (strNumber[0] == '+')
				{
					strNumber.erase(0, 1);
				}
			}
		}

		if (strNumber[i] == '.')
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
			strFractionalPart += strNumber[i];
		}
		else
		{
			strIntegerPart += strNumber[i];
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
		key1 = key1 && TaskBase::Numeral(strFractionalPart[i]);
	}

	for (int i = 0; i < strIntegerPart.length() && key2; i++)
	{
		key2 = key2 && TaskBase::Numeral(strIntegerPart[i]);
	}

	if (key1 && key2)
	{
		for (int i = 0; i < strIntegerPart.length(); i++)
		{
			numeral = strIntegerPart[i] & 0x0F;
			temp += numeral * pow(10, strIntegerPart.length() - 1 - i);
		}

		result = temp;
		temp = 0;
		numeral = 0;

		for (int i = 0; i < strFractionalPart.length(); i++)
		{
			numeral = strFractionalPart[i] & 0x0F;
			temp += numeral / pow(10, i + 1);
		}

		result += temp;

		number = sign * result;
		return true;
	}
	
	return false;
}
