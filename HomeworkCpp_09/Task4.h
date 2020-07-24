#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 4
/// </summary>
class Task4 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

protected:

	/// <summary>
	/// Проверяет является ли сторока действительным числом
	/// </summary>
	/// <param name="number"> Число в виде строки </param>	
	bool NumberCheck(std::string number);
	
	/// <summary>
	/// Удаляет нули стоящие перед действительным числом
	/// </summary>
	/// <param name="str"> Число в виде строки </param>	
	static std::string RemoveZeros(std::string str);
};

