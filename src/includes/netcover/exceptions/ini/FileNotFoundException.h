#ifndef NETCOVER_EXCEPTIONS_INI_FILENOTFOUNDEXCEPTION_H
#define NETCOVER_EXCEPTIONS_INI_FILENOTFOUNDEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::INI
{
    class FileNotFoundException : public Exception
    {
        using Exception::Exception;
    };
}

#endif