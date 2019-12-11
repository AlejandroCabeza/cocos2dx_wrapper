#include "StringUtils.h"

#include "Globals.h"

std::vector<std::string> StringUtils::tokenizeString(const char* str, char delimiter)
{
	ASSERT_MSG(str, "String to tokenize is null");

	std::vector<std::string> tokenizedString;

	do
	{
		const char *begin = str;

		while (*str != delimiter && *str) str++;
		tokenizedString.push_back(std::string(begin, str));

	} while (0 != *str++);

	return tokenizedString;
}
