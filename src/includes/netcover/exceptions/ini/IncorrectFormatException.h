#ifndef NETCOVER_EXCEPTIONS_INI_INCORRECTFORMATEXCEPTION_H
#define NETCOVER_EXCEPTIONS_INI_INCORRECTFORMATEXCEPTION_H

#include <netcover/exceptions/Exception.h>

namespace Netcover::Exceptions::INI
{
    class IncorrectFormatException : public Exception
    {
        public:
            IncorrectFormatException(const char* description, int err = 0, int line = 0) : Exception(description, err), line(line) {}
            int lineID() { return line; }
        private:
            int line;
    };
}

#endif