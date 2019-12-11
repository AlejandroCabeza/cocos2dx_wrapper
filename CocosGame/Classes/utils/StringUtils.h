#ifndef __STRINGUTILS_H__
#define __STRINGUTILS_H__

#include <vector>
#include <string>

class StringUtils
{
public:
	static std::vector<std::string> tokenizeString(const char* str, char delimiter);
};

#endif