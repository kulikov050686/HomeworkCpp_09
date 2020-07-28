#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include "Convert/Convert.h"

/// <summary>
/// Базовый класс задачи
/// </summary>
class TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	virtual void Run() = 0;

	/// <summary>
	/// Удаляет пробелы в строке 
	/// </summary>
	/// <param name="str"> Строка </param>	
	std::string RemoveSpaces(std::string str);

	/// <summary>
	/// Проверяет является ли символ цифрой
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool Numeral(char chr);

	/// <summary>
	/// Количечество символов в строке
	/// </summary>
	/// <param name="str"> Строка </param>	
	int NumberOfSymbols(std::string str, const char chr);
};
