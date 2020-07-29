#include "HomeWork.h"

void HomeWork::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	bool exit = false;
	std::string text = "Выберите пункт меню";
	std::string items[12] = { "Задача 1",
							  "Задача 2",
							  "Задача 3",
							  "Задача 4",
							  "Задача 5",
							  "Задача 6",
							  "Задача 7",
							  "Задача 8",
							  "Задача 9", 
		                      "Задача 10", 
		                      "Задача 11",
							  "Выход" };

	MenuController menu(items, 12);

	Task1 task1;
	Task2 task2;
	Task3 task3;
	Task4 task4;
	Task5 task5;
	Task6 task6;
	Task7 task7;
	Task8 task8;
	Task9 task9;
	Task10 task10;
	Task11 task11;

	while (!exit)
	{
		switch (menu.selectedMenuItem(text))
		{
		case 0:			
			task1.Run();
			break;
		case 1:			
			task2.Run();
			break;
		case 2:			
			task3.Run();
			break;
		case 3:			
			task4.Run();
			break;
		case 4:
			task5.Run();
			break;
		case 5:			
			task6.Run();
			break;
		case 6:			
			task7.Run();
			break;
		case 7:			
			task8.Run();
			break;
		case 8:			
			task9.Run();
			break;
		case 9:
			task10.Run();
			break;
		case 10:
			task11.Run();
			break;
		case 11:			
			exit = true;
			break;		
		}

		_getch();
	}	
}
