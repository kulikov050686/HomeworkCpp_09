#pragma once
#include "Task7.h"

/// <summary>
/// Задача 8
/// </summary>
class Task8 : public Task7
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Переводит римское число в арабское
	/// </summary>
	/// <param name="strNumber"> Строка содержащая римское число </param>	
	int RomToArab(std::string strNumber);

	/// <summary>
	/// Сравнивает две строки
	/// </summary>
	/// <param name="str1"> Строка 1 </param>
	/// <param name="str2"> Строка 2 </param>	
	bool CompareStrings(std::string str1, std::string str2);
};
