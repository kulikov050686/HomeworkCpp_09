#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 6
/// </summary>
class Task6 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

protected:

	/// <summary>
	/// Определяет количество слов в тексте
	/// </summary>
	/// <param name="str"> Текст </param>	
	int WordCount(std::string str);
};

