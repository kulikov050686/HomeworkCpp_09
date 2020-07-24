#pragma once
#include <iostream>

class Convert
{
private:

	/// ��������� �������� �� ������ ������
	static bool Numeral(char chr);

	/// ������� ��� ������� � ������
	static std::string RemoveSpaces(std::string str);

	/// ������� ���� ������� ����� ����� ������
	static std::string RemoveZeros(std::string str);

public:

	/// ����������� ������ � ����� �����
	static bool ToInt(std::string strNumber, int& number);

	/// ����������� ����� ����� � ������
	static std::string ToString(int number);

	/// ����������� ������ � ����� ����� ��� �����
	static bool ToUint(std::string strNumber, unsigned int& number);
};
