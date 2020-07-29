#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 7
/// </summary>
class Task7 : public TaskBase
{
public: 

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

protected:

	/// <summary>
	/// Преобразует число в строку в виде римской цифры
	/// </summary>
	/// <param name="number"> Число </param>	
	std::string RomanNumeral(int number);

	/// <summary>
	/// Преобразует число в римское число в виде строки
	/// </summary>
	/// <param name="number"> Число </param>	
	std::string ToRoma(int number);
};
