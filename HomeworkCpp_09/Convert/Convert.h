#pragma once
#include <iostream>

class Convert
{
private:

	/// Проверяет является ли символ цифрой
	static bool Numeral(char chr);

	/// Удаляет все пробелы в строке
	static std::string RemoveSpaces(std::string str);

	/// Удаляет нули стоящие перед целым числом
	static std::string RemoveZeros(std::string str);

public:

	/// Преобразует строку в целое число
	static bool ToInt(std::string strNumber, int& number);

	/// Преобразует целое число в строку
	static std::string ToString(int number);

	/// Преобразует строку в целое число без знака
	static bool ToUint(std::string strNumber, unsigned int& number);
};
