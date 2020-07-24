#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 2
/// </summary>
class Task2 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:	

	/// <summary>
	/// Проверяет является ли сторока целым числом
	/// </summary>
	/// <param name="number"> Число в виде строки </param>	
	bool NumberCheck(std::string number);
};

