#include <netcover/cli/Arguments.h>

using namespace Netcover::CLI;

Arguments::Arguments(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++)
    {
        args.push_back(std::string(argv[i]));
    }
}