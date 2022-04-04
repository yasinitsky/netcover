#ifndef NETCOVER_EXCEPTIONS_SOCKETS_INSUFFICIENTBUFFERSIZEEXCEPTION_H
#define NETCOVER_EXCEPTIONS_SOCKETS_INSUFFICIENTBUFFERSIZEEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::Sockets
{
    class InsufficientBufferSizeException : public Exception
    {
        using Exception::Exception;
    };
}

#endif