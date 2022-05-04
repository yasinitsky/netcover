#ifndef NETCOVER_INI_ERRORS_H
#define NETCOVER_INI_ERRORS_H

namespace Netcover::INI
{
    class Errors
    {
        public:
            static const int FIELD_OUTSIDE_SECTION = 0;
            static const int KEY_EMPTY = 1;
            static const int VALUE_EMPTY = 2;
    };
}

#endif