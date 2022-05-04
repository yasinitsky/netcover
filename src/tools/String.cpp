#include <netcover/tools/String.h>

static inline void ltrim(std::string& str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch){
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string& str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){
        return !std::isspace(ch);
    }).base(), str.end());
}

void Netcover::Tools::String::trim(std::string& str)
{
    ltrim(str);
    rtrim(str);
}

void Netcover::Tools::String::pop_front(std::string& str)
{
    str.erase(0, 1);
}