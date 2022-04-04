#ifndef NETCOVER_BUFFERS_BUFFER_H
#define NETCOVER_BUFFERS_BUFFER_H

namespace Netcover
{
    namespace Buffers
    {
        template <typename T>
        class Buffer
        {
            typedef T BufferMember;

            public:
                Buffer(unsigned int size);
                BufferMember* getAddress() { return data; }
                unsigned int getSize() { return size; }
                BufferMember& operator[](unsigned int index);
                ~Buffer();

            private:
                BufferMember* data = nullptr;
                unsigned int size = 0;
        };
    }
}

#include "../buffers/Buffer.tpp"

#endif