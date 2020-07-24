#include "Task8.h"

void Task8::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	std::cout << "Введите римское число: ";
	std::getline(std::cin, strNumber);

	strNumber = RemoveSpaces(strNumber);

	if (CorrectInput(strNumber))
	{
		if (NumberRepeats(strNumber, 'D') < 2 && 
			NumberRepeats(strNumber, 'C') < 4 &&
			NumberRepeats(strNumber, 'L') < 2 &&
			NumberRepeats(strNumber, 'X') < 4 &&
			NumberRepeats(strNumber, 'V') < 2 && 
			NumberRepeats(strNumber, 'I') < 4)
		{
			if (LocationCheck(strNumber))
			{
				std::cout << "Число: " << RomToArab(strNumber) << std::endl;
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

bool Task8::CorrectInput(std::string str)
{
	bool key = true;

	for (int i = 0; i < str.length() && key; i++)
	{
		key = key && AllowedSymbol(str[i]);
	}

	return key;
}

bool Task8::AllowedSymbol(char chr)
{
	return chr == 'I' || 
		   chr == 'V' || 
		   chr == 'X' || 
		   chr == 'L' || 
		   chr == 'C' || 
		   chr == 'D' || 
		   chr == 'M';
}

bool Task8::RepeatingInRow(std::string str, char chr)
{
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == chr && str[i + 1] == chr) return true;
	}

	return false;
}

int Task8::NumberRepeats(std::string str, char chr)
{
	if (RepeatingInRow(str,chr))
	{
		int k = 1;

		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == chr && str[i + 1] == chr)
			{
				k++;
			}
		}

		return k;
	}

	return 0;
}

bool Task8::LocationCheck(std::string strNumber)
{
	Init(strNumber);

	if (numberOfCharacters_D <= 1 && 
		numberOfCharacters_L <= 1 && 
		numberOfCharacters_V <= 1)
	{
		if (PositionCheck_M(strNumber) && 
			PositionCheck_D(strNumber) && 
			PositionCheck_C(strNumber) && 
			PositionCheck_L(strNumber) && 
			PositionCheck_X(strNumber) && 
			PositionCheck_V(strNumber))
		{
			return true;
		}		
	}

	return false;
}

int Task8::RomToArab(std::string strNumber)
{
	int number = 0;

	for (int i = 0; i < strNumber.length(); ++i)
	{
		switch (strNumber[i])
		{
		case 'M':
			number += 1000;
			break;
		case 'D':
			number += 500;
			break;
		case 'C':
			i + 1 < strNumber.length() && (strNumber[i + 1] == 'D' || strNumber[i + 1] == 'M') ? number -= 100 : number += 100;
			break;
		case 'L':
			number += 50;
			break;
		case 'X':
			i + 1 < strNumber.length() && (strNumber[i + 1] == 'L' || strNumber[i + 1] == 'C') ? number -= 10 : number += 10;
			break;
		case 'V':
			number += 5;
			break;
		case 'I':
			i + 1 < strNumber.length() && (strNumber[i + 1] == 'V' || strNumber[i + 1] == 'X') ? number -= 1 : number += 1;
			break;

		}
	}

	return number;
}

int Task8::MaximumPosition(std::string str, char chr)
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == chr) return i;
	}

	return str.length();
}

int Task8::MinimumPosition(std::string str, char chr)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == chr) return i;
	}

	return str.length();
}

void Task8::Init(std::string strNumber)
{
	max_M = MaximumPosition(strNumber, 'M');
	max_C = MaximumPosition(strNumber, 'C');
	max_X = MaximumPosition(strNumber, 'X');
	max_I = MaximumPosition(strNumber, 'I');

	pos_D = MaximumPosition(strNumber, 'D');
	pos_L = MaximumPosition(strNumber, 'L');
	pos_V = MaximumPosition(strNumber, 'V');

	min_M = MinimumPosition(strNumber, 'M');
	min_C = MinimumPosition(strNumber, 'C');
	min_X = MinimumPosition(strNumber, 'X');
	min_I = MinimumPosition(strNumber, 'I');

	numberOfCharacters_M = NumberOfSymbols(strNumber, 'M');
	numberOfCharacters_D = NumberOfSymbols(strNumber, 'D');
	numberOfCharacters_C = NumberOfSymbols(strNumber, 'C');
	numberOfCharacters_L = NumberOfSymbols(strNumber, 'L');
	numberOfCharacters_X = NumberOfSymbols(strNumber, 'X');
	numberOfCharacters_V = NumberOfSymbols(strNumber, 'V');
	numberOfCharacters_I = NumberOfSymbols(strNumber, 'I');
}

bool Task8::PositionCheck_M(std::string strNumber)
{
	if (numberOfCharacters_M != 0)
	{
		if (max_M < pos_D &&
			max_M < pos_L &&
			max_M < pos_V &&
			max_M < min_X &&
			max_M < min_I &&
			numberOfCharacters_C == 0)
		{
			return true;			
		}

		if (max_M < pos_D &&
			max_M < pos_L &&
			max_M < pos_V &&
			max_M < min_X &&
			max_M < min_I &&
			numberOfCharacters_C != 0)
		{
			if (numberOfCharacters_C > 1 && max_M > min_C)
			{
				return false;
			}

			if (numberOfCharacters_D == 1)
			{
				if ((min_C - max_M == 1 && pos_D - min_C == 1) || (pos_D - max_M == 1 && min_C - pos_D == 1))
				{
					return true;
				}
			}

			if (numberOfCharacters_D == 0)
			{
				if (abs(max_M - min_C) == 1)
				{
					return true;
				}
			}			
		}

		return false;
	}

	return true;
}

bool Task8::PositionCheck_D(std::string strNumber)
{
	if (numberOfCharacters_D != 0)
	{
		if (pos_D < pos_L && 
			pos_D < pos_V && 
			pos_D < min_X && 
			pos_D < min_I && 
			numberOfCharacters_C == 0)
		{
			return true;
		}

		if (pos_D < pos_L &&
			pos_D < pos_V &&
			pos_D < min_X &&
			pos_D < min_I &&
			numberOfCharacters_C != 0)
		{
			if (numberOfCharacters_C > 1 && pos_D > min_C)
			{
				return false;
			}

			if (abs(min_C - pos_D) == 1)
			{
				return true;
			}
		}

		return false;
	}

	return true;
}

bool Task8::PositionCheck_C(std::string strNumber)
{
	if (numberOfCharacters_C != 0)
	{
		if (max_C < pos_L && 
			max_C < pos_V && 
			max_C < min_I && 
			numberOfCharacters_X == 0)
		{
			return true;
		}

		if (max_C < pos_L &&
			max_C < pos_V &&
			max_C < min_I &&
			numberOfCharacters_X != 0)
		{
			if (numberOfCharacters_X > 1 && max_C > min_X)
			{
				return false;
			}

			if (numberOfCharacters_L == 1)
			{
				if ((min_X - max_C == 1 && pos_L - min_X == 1) || (pos_L - max_C == 1 && min_X - pos_L == 1))
				{
					return true;
				}
			}

			if (numberOfCharacters_L == 0)
			{
				if (abs(max_C - min_X) == 1)
				{
					return true;
				}
			}
		}

		return false;
	}

	return true;
}

bool Task8::PositionCheck_L(std::string strNumber)
{
	if (numberOfCharacters_L != 0)
	{
		if (pos_L < pos_V && 
			pos_L < min_I && 
			numberOfCharacters_X == 0)
		{
			return true;
		}

		if (pos_L < pos_V &&
			pos_L < min_I &&
			numberOfCharacters_X != 0)
		{
			if (numberOfCharacters_X > 1 && pos_L > min_X)
			{
				return false;
			}

			if (abs(min_X - pos_L) == 1)
			{
				return true;
			}
		}

		return false;
	}

	return true;
}

bool Task8::PositionCheck_X(std::string strNumber)
{
	if (numberOfCharacters_X != 0)
	{
		if (max_X < pos_V && 
			numberOfCharacters_I == 0)
		{
			return true;
		}

		if (max_X < pos_V &&
			numberOfCharacters_I != 0)
		{
			if (numberOfCharacters_I > 1 && max_X > min_I)
			{
				return false;
			}

			if (numberOfCharacters_V == 1)
			{
				if ((min_I - max_X == 1 && pos_V - min_I == 1) || (pos_V - max_X == 1 && min_I - pos_V == 1))
				{
					return true;
				}
			}

			if (numberOfCharacters_V == 0)
			{
				if (abs(max_X - min_I) == 1)
				{
					return true;
				}
			}
		}

		return false;
	}

	return true;
}

bool Task8::PositionCheck_V(std::string strNumber)
{
	if (numberOfCharacters_V != 0)
	{
		if (numberOfCharacters_I == 0)
		{
			return true;
		}

		if (numberOfCharacters_I != 0)
		{
			if (numberOfCharacters_I > 1 && pos_V > min_I)
			{
				return false;
			}

			if (abs(min_I - pos_V) == 1)
			{
				return true;
			}
		}

		return false;
	}

	return true;
}
