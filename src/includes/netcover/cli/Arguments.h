#include <vector>
#include <string>
#include <unordered_map>
#include <pair>

namespace Netcover::CLI
{
    class Arguments
    {
        public:
            Arguments(int argc, char* argv[]);
            void parseFlags(std::vector<std::pair<std::string, std::string>> flagList);
        private:
            std::vector<std::string> args;
            std::unordered_map<std::string, bool> flags;
    };
}