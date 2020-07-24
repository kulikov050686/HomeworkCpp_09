#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 5 
/// </summary>
class Task5 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Проверяет есть ли в строке подряд повторяющиеся символы
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="chr"> Повторяющийся символ </param>	
	bool RepeatingInRow(std::string str, char chr);

	/// <summary>
	/// Проверяет является ли символ допустимым для первой части адреса
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool ValidCharacterFirstPart(char chr);

	/// <summary>
	/// Проверяет является ли символ допустимым для второй части адреса
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool ValidCharacterSecondPart(char chr);
};

