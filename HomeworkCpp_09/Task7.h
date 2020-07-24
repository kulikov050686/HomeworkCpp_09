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

private:

	/// <summary>
	/// Преобразует число в строку в виде римской цифры
	/// </summary>
	/// <param name="number"> Число </param>	
	std::string RomanNumeral(int number);
};
