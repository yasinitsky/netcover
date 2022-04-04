#ifndef NETCOVER_EXCEPTIONS_BUFFERS_OUTOFBOUNDEXCEPTION_H
#define NETCOVER_EXCEPTIONS_BUFFERS_OUTOFBOUNDEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::Buffers
{
    class OutOfBoundsException : public Exception
    {
        using Exception::Exception;
    };
}

#endif