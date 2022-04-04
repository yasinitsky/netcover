#ifndef NETCOVER_EXCEPTIONS_EXCEPTION_H
#define NETCOVER_EXCEPTIONS_EXCEPTION_H

#include <stdexcept>

namespace Netcover
{
    namespace Exceptions
    {
        class Exception : public std::exception
        {
            public:
                Exception(const char* description, int err = 0) : description((char*) description), err(err) {}
                const char* what() const throw() { return (const char*) description; }
                int errID() { return err; }
            
            private:
                char* description;
                int err;
        };
    }
}

#endif