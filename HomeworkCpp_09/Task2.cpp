#include "Task2.h"

void Task2::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber1;
	std::string strNumber2;

	std::cout << "Введите первое число: ";
	std::cin >> strNumber1;
	std::cout << "Введите второе число: ";
	std::cin >> strNumber2;

	if (strNumber1.length() == 4 && strNumber2.length() == 4)
	{
		if (NumberCheck(strNumber1) && NumberCheck(strNumber2))
		{
			int bulls = 0;
			int cows = 0;
			char a = ' ';
			char k = ' ';

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (strNumber1[i] == strNumber2[j])
					{
						if (i == j)
						{
							bulls++;

							if (strNumber1[i] == a)
							{
								cows--;
							}
						}
						else
						{
							if (k != strNumber1[i])
							{
								cows++;
								k = strNumber1[i];
							}

							a = strNumber1[i];
						}
					}
				}
			}

			std::cout << "Быков: " << bulls << " Коров: " << cows << std::endl;
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

bool Task2::NumberCheck(std::string number)
{
	bool key = true;

	for (int i = 0; i < number.length() && key; i++)
	{
		key = key && Numeral(number[i]);
	}

	return key;
}
