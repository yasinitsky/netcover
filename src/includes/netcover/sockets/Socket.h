#ifndef NETCOVER_SOCKETS_SOCKET_H
#define NETCOVER_SOCKETS_SOCKET_H

#include <netcover/buffers/Buffer.h>

#include <sys/socket.h>

namespace Netcover
{
    namespace Sockets
    {
        template <int FAMILY, int TYPE, int PROTOCOL>
        class Socket
        {
            public:
                Socket();
                void setBuffer(Buffers::Buffer<unsigned char>* buffer);
                ssize_t read(size_t length, int flags = 0);
                Buffer<unsigned char>* getBuffer() { return buffer; }
                int getSocketFD() { return socketFD; }
                ~Socket();
            private:
                static const int SOCKET_FAMILY = FAMILY;
                static const int SOCKET_TYPE = TYPE;
                static const int SOCKET_PROTOCOL = PROTOCOL;

                int socketFD = -1;
                Buffers::Buffer<unsigned char>* buffer = nullptr;
        };
    }
}

#include "../sockets/Socket.tpp"

#endif