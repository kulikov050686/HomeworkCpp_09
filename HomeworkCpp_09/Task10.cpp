#include "Task10.h"

void Task10::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

    std::string number;
    std::map<char, int> dictionary = { {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}, {'0', 0}, {'Z', 1001} };

    int result = 0;
    char pef = 'Z';
    bool key = true;
    bool flag1 = true;
    bool flag2 = true;
    int pefpef = 0;
    int counter = 0;

    std::cout << "Введите римское число: ";
    std::getline(std::cin, number);

    number = RemoveSpaces(number);

    for (int i = 0; i < number.length() && key; i++)
    {
        bool a = Convert::ToString(dictionary[number[i]])[0] == '1';

        if (dictionary[number[i]] < dictionary[pef] && flag2)
        {
            counter = 0;
        }
        else if (dictionary[number[i]] < dictionary[pef] && !flag2)
        {
            if ((dictionary[number[i]] != pefpef) && (dictionary[number[i]] / pefpef != (dictionary[pef] + pefpef) / (2 * pefpef)))
            {
                flag2 = true;
            }
            else
            {
                std::cout << "Error!!!" << std::endl;
                key = false;
            }
        }
        else if (dictionary[number[i]] == dictionary[pef] && flag2 && a && counter < 2)
        {
            counter++;
        }
        else if (dictionary[number[i]] > dictionary[pef] && flag2)
        {
            flag2 = false;
            pefpef = dictionary[pef];
        }
        else
        {
            std::cout << "Error!!!" << std::endl;
            key = false;
            break;
        }

        pef = number[i];
    }

    pef = '0';

    for (int i = number.length() - 1; i >= 0 && key; i--)
    {
        bool k = (dictionary[pef] / dictionary[number[i]] == 5) || (dictionary[pef] / dictionary[number[i]] == 10);
        bool m = (dictionary[pef] - dictionary[number[i]] != 45) && (dictionary[pef] - dictionary[number[i]] != 450);

        if (dictionary[number[i]] > dictionary[pef])
        {
            result += dictionary[number[i]];
            flag1 = true;
        }
        else if (dictionary[number[i]] == dictionary[pef] && flag1)
        {
            result += dictionary[number[i]];
        }
        else if (k && m && flag1)
        {
            result -= dictionary[number[i]];
            flag1 = false;
        }
        else
        {
            std::cout << "Error!!!" << std::endl;
            key = false;
            break;
        }

        pef = number[i];
    }

    if (key) std::cout << result << std::endl;
}
