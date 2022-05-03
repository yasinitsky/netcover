#include <netcover/tools/String.h>

using namespace Netcover::Tools::String;

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
    }).base(), s.end());
}

inline void trim(std::string& str)
{
    ltrim(str);
    rtrim(str);
}