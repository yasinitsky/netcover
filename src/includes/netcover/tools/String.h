#ifndef NETCOVER_TOOLS_STRING_H
#define NETCOVER_TOOLS_STRING_H

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

namespace Netcover::Tools::String
{
    void trim(std::string& str);
    void pop_front(std::string& str);
}

#endif