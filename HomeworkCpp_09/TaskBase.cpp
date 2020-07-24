#include "TaskBase.h"

std::string TaskBase::RemoveSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	return str;
}

bool TaskBase::Numeral(char chr)
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

int TaskBase::NumberOfSymbols(std::string str, const char chr)
{
	int k = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == chr) k++;
	}

	return k;
}
