#include <vector>
#include <string>
#include <unordered_map>

namespace Netcover::CLI
{
    class Arguments
    {
        public:
            Arguments(int argc, char* argv[]);
        private:
            std::vector<std::string> args;
    };
}