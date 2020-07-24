#pragma once
#include "Task4.h"
#include "Task6.h"

/// <summary>
/// Задача 9
/// </summary>
class Task9 : public Task4 , public Task6
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Первое действительное число в виде строки
	/// </summary>
	std::string strNumber1;

	/// <summary>
	/// Второе дейтсвительное число в виде строки
	/// </summary>
	std::string strNumber2;

	/// <summary>
	/// Возвращает слово из строки по соответствующему номеру
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="number"> Номер слова в строке </param>	
	std::string StringWord(std::string str, int number);

	/// <summary>
	/// Преобразует строку в вещественное число
	/// </summary>
	/// <param name="strNumber"> Вещественное число в виде строки </param>
	/// <param name="number"> Вещественное число </param>
	bool ToDouble(std::string strNumber, double& number);
};

