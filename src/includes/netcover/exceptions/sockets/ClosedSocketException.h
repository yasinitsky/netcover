#ifndef NETCOVER_EXCEPTIONS_SOCKETS_CLOSEDSOCKETEXCEPTION_H
#define NETCOVER_EXCEPTIONS_SOCKETS_CLOSEDSOCKETEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::Sockets
{
    class ClosedSocketException : public Exception
    {
        using Exception::Exception;
    };
}

#endif