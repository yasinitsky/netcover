#include <vector>
#include <string>
#include <unordered_map>

namespace Netcover::CLI
{
    class Arguments
    {
        public:
            Arguments(int argc, char* argv[]);
            void parseFlags();
            std::vector<std::string> operator*() { return flags; }
            void setFlagList(std::pair<std::string, std::string>);
        private:
            std::vector<std::string> args;
            std::vector<std::string> flags;
    };
}