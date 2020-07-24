#pragma once
#include "TaskBase.h"

/// <summary>
/// Задача 8
/// </summary>
class Task8 : public TaskBase
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

private:

	/// <summary>
	/// Максимальная позиция повторяющегося символа M
	/// </summary>
	int max_M;

	/// <summary>
	/// Максимальная позиция повторяющегося символа C
	/// </summary>
	int max_C;

	/// <summary>
	/// Максимальная позиция повторяющегося символа X
	/// </summary>
	int max_X;

	/// <summary>
	/// Максимальная позиция повторяющегося символа I
	/// </summary>
	int max_I;

	/// <summary>
	/// Позиция не повторяющегося символа D
	/// </summary>
	int pos_D;

	/// <summary>
	/// Позиция не повторяющегося символа L
	/// </summary>
	int pos_L;

	/// <summary>
	/// Позиция не повторяющегося символа V
	/// </summary>
	int pos_V;

	/// <summary>
	/// Минимальная позиция повторяющегося символа M
	/// </summary>
	int min_M; // 

	/// <summary>
	/// Минимальная позиция повторяющегося символа C
	/// </summary>
	int min_C;

	/// <summary>
	/// Минимальная позиция повторяющегося символа X
	/// </summary>
	int min_X;

	/// <summary>
	/// Минимальная позиция повторяющегося символа I
	/// </summary>
	int min_I;

	/// <summary>
	/// Количество символов M
	/// </summary>
	int numberOfCharacters_M;

	/// <summary>
	/// Количество символов D
	/// </summary>
	int numberOfCharacters_D;

	/// <summary>
	/// Количество символов C
	/// </summary>
	int numberOfCharacters_C;

	/// <summary>
	/// Количество символов L
	/// </summary>
	int numberOfCharacters_L;

	/// <summary>
	/// Количество символов X
	/// </summary>
	int numberOfCharacters_X;

	/// <summary>
	/// Количество символов V
	/// </summary>
	int numberOfCharacters_V;

	/// <summary>
	/// Количество символов I
	/// </summary>
	int numberOfCharacters_I;

	/// <summary>
	/// Проверка корректности ввода римского числа
	/// </summary>
	/// <param name="str"> Строка для проверки </param>	
	bool CorrectInput(std::string str);

	/// <summary>
	/// Проверка символа
	/// </summary>
	/// <param name="chr"> Символ </param>	
	bool AllowedSymbol(char chr);

	/// <summary>
	/// Проверяет есть ли в строке подряд повторяющиеся символы
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="chr"> Повторяющийся символ </param>	
	bool RepeatingInRow(std::string str, char chr);

	/// <summary>
	/// Количество повторяющихся в строке подряд символов
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="chr"> Повторяющийся символ </param>	
	int NumberRepeats(std::string str, char chr);

	/// <summary>
	/// Проверяет правильность расположения символов в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool LocationCheck(std::string strNumber);

	/// <summary>
	/// Переводит римское число в арабское
	/// </summary>
	/// <param name="strNumber"> Строка содержащая римское число </param>	
	int RomToArab(std::string strNumber);

	/// <summary>
	/// Максимальная позиция символа в строке
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="chr"> Символ </param>	
	int MaximumPosition(std::string str, char chr);

	/// <summary>
	/// Минимальная позиция символа в строке
	/// </summary>
	/// <param name="str"> Строка </param>
	/// <param name="chr"> Символ </param>	
	int MinimumPosition(std::string str, char chr);

	/// <summary>
	/// Инициализация глобальных переменных
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	void Init(std::string strNumber);

	/// <summary>
	/// Проверка позиции символа М в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_M(std::string strNumber);

	/// <summary>
	/// Проверка позиции символа D в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_D(std::string strNumber);

	/// <summary>
	/// Проверка позиции символа C в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_C(std::string strNumber);

	/// <summary>
	/// Проверка позиции символа L в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_L(std::string strNumber);

	/// <summary>
	/// Проверка позиции символа X в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_X(std::string strNumber);

	// <summary>
	/// Проверка позиции символа L в римском числе
	/// </summary>
	/// <param name="strNumber"> Римское число </param>	
	bool PositionCheck_V(std::string strNumber);
};
