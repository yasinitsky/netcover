#ifndef NETCOVER_EXCEPTIONS_INI_INCORRECTFORMATEXCEPTION_H
#define NETCOVER_EXCEPTIONS_INI_INCORRECTFORMATEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::INI
{
    class IncorrectFormatException : public Exception
    {
        using Exception::Exception;
    }
}

#endif