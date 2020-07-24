#include "Task6.h"

void Task6::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string str;
	std::cout << "Введите текст: ";
	std::getline(std::cin, str);

	std::cout << "Количество слов в тексте: " << WordCount(str);
}

int Task6::WordCount(std::string str)
{
	if (str.length() > 0)
	{
		bool k = false;
		int m = 0;
		str += ' ';

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				if (k)
				{
					m++;
				}

				k = false;
			}
			else
			{
				k = true;
			}
		}

		return m;
	}

	return 0;
}
