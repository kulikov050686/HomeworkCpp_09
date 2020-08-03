#include "Task8.h"

void Task8::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

    std::string number;

    std::cout << "Введите римское число: ";
    std::getline(std::cin, number);

    number = RemoveSpaces(number);
    int a = RomToArab(number);

    if (CompareStrings(ToRoma(a), number))
    {
        std::cout << "Число: " << a << std::endl;
    }
    else
    {
        std::cout << "Ошибка ввода данных!!!" << std::endl;
    }
}

int Task8::RomToArab(std::string strNumber)
{
    std::map<char, int> dictionary = { {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}, {'0', 0} };
    int result = 0;
    char pef = '0';

    for (int i = strNumber.length() - 1; i >= 0; i--)
    {
        if (dictionary[strNumber[i]] >= dictionary[pef])
        {
            result += dictionary[strNumber[i]];
        }
        else
        {
            result -= dictionary[strNumber[i]];
        }

        pef = strNumber[i];
    }

    return result;
}

bool Task8::CompareStrings(std::string str1, std::string str2)
{
    if (str1.length() == str2.length())
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }

        return true;
    }

    return false;
}
