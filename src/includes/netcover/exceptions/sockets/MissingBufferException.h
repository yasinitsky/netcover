#ifndef NETCOVER_EXCEPTIONS_SOCKETS_MISSINGBUFFEREXCEPTION_H
#define NETCOVER_EXCEPTIONS_SOCKETS_MISSINGBUFFEREXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::Sockets
{
    class MissingBufferException : public Exception
    {
        using Exception::Exception;
    };
}

#endif