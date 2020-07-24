#include "Task7.h"

void Task7::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	std::cout << "Введите положительное целое число: ";
	std::getline(std::cin, strNumber);

	int number = 0;
	int numberOf1000 = 0;
	int numberOf500 = 0;
	int numberOf100 = 0;
	int numberOf50 = 0;
	int numberOf10 = 0;
	int numberOf5 = 0;


	if (Convert::ToInt(strNumber, number))
	{
		if (number > 0)
		{
			strNumber = "";

			numberOf1000 = number / 1000;
			number -= numberOf1000 * 1000;

			numberOf500 = number / 500;
			number -= numberOf500 * 500;

			numberOf100 = number / 100;
			number -= numberOf100 * 100;

			numberOf50 = number / 50;
			number -= numberOf50 * 50;

			numberOf10 = number / 10;
			number -= numberOf10 * 10;

			numberOf5 = number / 5;

			if (number >= 5)
			{
				number -= numberOf5 * 5;
			}
			
			if (numberOf1000 > 0)
			{
				for (int i = 0; i < numberOf1000; i++)
				{
					strNumber += RomanNumeral(1000);
				}
			}
			
			if (numberOf500 == 1)
			{
				if (0 <= numberOf100 && numberOf100 < 4)
				{
					strNumber += RomanNumeral(500);

					for (int i = 0; i < numberOf100; i++)
					{
						strNumber += RomanNumeral(100);
					}
				}

				if (numberOf100 == 4)
				{
					strNumber += "CM";
				}
			}
			else
			{
				if (0 < numberOf100 && numberOf100 < 4)
				{
					for (int i = 0; i < numberOf100; i++)
					{
						strNumber += RomanNumeral(100);
					}
				}

				if (numberOf100 == 4)
				{
					strNumber += "CD";
				}
			}

			if (numberOf50 == 1)
			{
				if (0 <= numberOf10 && numberOf10 < 4)
				{
					strNumber += RomanNumeral(50);

					for (int i = 0; i < numberOf10; i++)
					{
						strNumber += RomanNumeral(10);
					}
				}

				if (numberOf10 == 4)
				{
					strNumber += "XC";
				}
			}
			else
			{
				if (0 <= numberOf10 && numberOf10 < 4)
				{
					for (int i = 0; i < numberOf10; i++)
					{
						strNumber += RomanNumeral(10);
					}
				}

				if (numberOf10 == 4)
				{
					strNumber += "XL";
				}
			}

			if (numberOf5 == 1)
			{
				if (0 <= number && number < 4)
				{
					strNumber += RomanNumeral(5);

					for (int i = 0; i < number; i++)
					{
						strNumber += RomanNumeral(1);
					}
				}

				if (number == 4)
				{
					strNumber += "IX";
				}
			}
			else
			{
				if (0 <= number && number < 4)
				{
					for (int i = 0; i < number; i++)
					{
						strNumber += RomanNumeral(1);
					}
				}

				if (number == 4)
				{
					strNumber += "IV";
				}
			}

			std::cout << "Вывод: " << strNumber << std::endl;

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

std::string Task7::RomanNumeral(int number)
{
	switch (number)
	{
	case 1:
		return "I";
		break;	
	case 5:
		return "V";
		break;	
	case 10:
		return "X";
		break;
	case 50:
		return "L";
		break;
	case 100:
		return "C";
		break;
	case 500:
		return "D";
		break;
	case 1000:
		return "M";
		break;	
	}

	return "Error!!!";
}
