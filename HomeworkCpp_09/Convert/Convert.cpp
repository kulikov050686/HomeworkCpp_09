#include "Convert.h"

bool Convert::Numeral(char chr)
{
	return (chr == '0') ||
		   (chr == '1') ||
		   (chr == '2') ||
		   (chr == '3') ||
		   (chr == '4') ||
		   (chr == '5') ||
		   (chr == '6') ||
		   (chr == '7') ||
		   (chr == '8') ||
		   (chr == '9');
}

std::string Convert::RemoveSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	return str;
}

std::string Convert::RemoveZeros(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			str.erase(i, 1);
			i--;
		}
		else
		{
			break;
		}
	}

	return str;
}

bool Convert::ToInt(std::string strNumber, int& number)
{
	int sign = 1;
	int temp = 0;

	strNumber = RemoveSpaces(strNumber);

	if (strNumber[0] == '-')
	{
		strNumber.erase(0, 1);
		sign = -1;
	}
	else
	{
		if (strNumber[0] == '+')
		{
			strNumber.erase(0, 1);
			sign = 1;
		}
	}

	strNumber = RemoveZeros(strNumber);

	bool key = true;

	for (int i = 0; i < strNumber.length(); i++)
	{
		key = key && Numeral(strNumber[i]);
	}

	if (key)
	{
		int numeral = 0;

		for (int i = 0; i < strNumber.length(); i++)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * ((int)pow(10, strNumber.length() - 1 - i));
		}

		number = sign * temp;
		return true;
	}

	return false;
}

std::string Convert::ToString(int number)
{
	std::string outString;

	if (number != 0)
	{
		int sign = 1;

		if (number < 0)
		{
			number = -number;
			sign = -1;
		}

		int numberOfDigits = floor(log10(number)); // Разрядность числа

		int k = numberOfDigits;
		int n = 0;

		while (0 <= k)
		{
			n = (number / pow(10, k));
			outString += n | 0x30;
			number -= n * pow(10, k);
			k--;
		}

		if (sign == -1)
		{
			outString = "-" + outString;
		}
	}
	else
	{
		outString = "0";
	}

	return outString;
}

bool Convert::ToUint(std::string strNumber, unsigned int& number)
{	
	unsigned int temp = 0;

	strNumber = RemoveSpaces(strNumber);
	strNumber = RemoveZeros(strNumber);

	bool key = true;

	for (int i = 0; i < strNumber.length(); i++)
	{
		key = key && Numeral(strNumber[i]);
	}

	if (key)
	{
		int numeral = 0;

		for (int i = 0; i < strNumber.length(); i++)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * ((unsigned int)pow(10, strNumber.length() - 1 - i));
		}
		
		number = temp;
		return true;
	}

	return false;
}
