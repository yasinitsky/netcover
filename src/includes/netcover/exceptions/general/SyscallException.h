#ifndef NETCOVER_EXCEPTIONS_GENERAL_SYSCALLEXCEPTION_H
#define NETCOVER_EXCEPTIONS_GENERAL_SYSCALLEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::General
{
    class SyscallException : public Exception
    {
        using Exception::Exception;
    };
}

#endif