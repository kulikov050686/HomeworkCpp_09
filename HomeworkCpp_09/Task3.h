#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 3
/// </summary>
class Task3 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Проверка корректности ввода строки
	/// </summary>
	/// <param name="str"> Строка для проверки </param>	
	bool CorrectInput(std::string str);

	/// <summary>
	/// Проверка символа
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool AllowedSymbol(char chr);

	/// <summary>
	/// Проверяет победу крестиков
	/// </summary>	
	bool Victory(const std::string *str, const char chr);	
};

