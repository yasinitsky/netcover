#ifndef NETCOVER_SOCKETS_RAW_TCPV4SOCKET_H
#define NETCOVER_SOCKETS_RAW_TCPV4SOCKET_H

#include <netcover/sockets/Socket.h>

#include <netinet/in.h>

namespace Netcover::Sockets::Raw
{
    class TCPv4Socket : public Socket<AF_INET, SOCK_RAW, IPPROTO_TCP>
    {
        public:
            using Socket::Socket;
    };
}

#endif