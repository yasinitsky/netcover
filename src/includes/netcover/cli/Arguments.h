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
        private:
            std::vector<std::string> args;
            std::vector<std::string> flags;
    };
}