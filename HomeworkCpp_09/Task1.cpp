#include "Task1.h"

void Task1::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strDepartureTime;
	std::string strArrivalTime;

	std::cout << "Введите время отправления (ЧЧ:ММ): ";
	std::cin >> strDepartureTime;
	std::cout << "Введите время прибытия (ЧЧ:ММ): ";
	std::cin >> strArrivalTime;

	if (strDepartureTime.length() == 5 && strArrivalTime.length() == 5)
	{
		if (strArrivalTime[2] == ':' && strDepartureTime[2] == ':')
		{
			std::string strNumber[4];
			unsigned int number[4];

			strNumber[0].assign(strDepartureTime, 0, 2);
			strNumber[1].assign(strDepartureTime, 3, 5);
			strNumber[2].assign(strArrivalTime, 0, 2);
			strNumber[3].assign(strArrivalTime, 3, 5);

			bool key = true;

			for (int i = 0; i < 4; i++)
			{
				key = key && Convert::ToUint(strNumber[i], number[i]);
			}

			if (key)
			{
				if (number[0] <= 23 && number[2] <= 23 && number[1] <= 59 && number[3] <= 59)
				{
					int minutes = number[3] - number[1];
					int hours = number[2] - number[0];
					int amendment = 0;

					

					if (minutes >= 0)
					{
						amendment = 0;
					}
					else
					{
						minutes += 60;
						amendment = -1;
					}
					
					if (hours >= 0)
					{
						hours += amendment;
					}
					else
					{
						hours += 24 + amendment;
					}

					std::cout << "Поезд находится в пути: " << hours << " " << OutputHours(hours) << " " << minutes << " " << OutputMinutes(minutes) << std::endl;
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
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

std::string Task1::OutputMinutes(int minutes)
{
	std::string result;

	if (minutes > 20)
	{
		int numeral = minutes % 10;

		if (numeral == 1)
		{
			result = "минута";
		}

		if (2 <= numeral && numeral <= 4)
		{
			result = "минуты";
		}

		if (5 <= numeral || numeral == 0)
		{
			result = "минут";
		}
	}
	else
	{
		if (minutes == 1)
		{
			result = "минута";
		}

		if (2 <= minutes && minutes < 5)
		{
			result = "минуты";
		}

		if (5 <= minutes <= 20)
		{
			result = "минут";
		}
	}

	return result;
}

std::string Task1::OutputHours(int hours)
{
	std::string result;

	if (hours > 20)
	{
		int numeral = hours % 10;

		if (numeral == 1)
		{
			result = "час";
		}

		if (2 <= numeral && numeral < 4)
		{
			result = "часа";
		}		
	}
	else
	{
		if (hours == 1)
		{
			result = "час";
		}

		if (2 <= hours && hours <= 4)
		{
			result = "часа";
		}

		if (5 <= hours <= 20)
		{
			result = "часов";
		}
	}

	return result;
}
