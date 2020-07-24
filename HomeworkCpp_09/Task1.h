#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 1
/// </summary>
class Task1 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Вывод правильного окончания минут
	/// </summary>
	/// <param name="minutes"> Количество минут </param>	
	std::string OutputMinutes(int minutes);

	/// <summary>
	/// Вывод правильного окончания часов
	/// </summary>
	/// <param name="hours"> Количество часов </param>	
	std::string OutputHours(int hours);
};
