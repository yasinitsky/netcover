#include <netcover/cli/Arguments.h>
#include <netcover/tools/String.h>

using namespace Netcover::CLI;

Arguments::Arguments(int argc, char* argv[])
{
    for(int i = 1; i < argc; i++)
    {
        args.push_back(std::string(argv[i]));
    }
}