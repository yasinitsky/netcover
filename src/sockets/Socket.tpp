#include <netcover/exceptions/general/SyscallException.h>
#include <netcover/exceptions/sockets/MissingBufferException.h>
#include <netcover/exceptions/sockets/InsufficientBufferSizeException.h>
#include <netcover/exceptions/sockets/ClosedSocketException.h>

#include <errno.h>
#include <unistd.h>

using namespace Netcover::Sockets;

template <int FAMILY, int TYPE, int PROTOCOL>
Socket<FAMILY, TYPE, PROTOCOL>::Socket()
{
    socketFD = socket(SOCKET_FAMILY, SOCKET_TYPE, SOCKET_PROTOCOL);

    if(socketFD == -1)
        throw Exceptions::General::SyscallException("Cannot create new socket.", errno);
}

template <int FAMILY, int TYPE, int PROTOCOL>
void Socket<FAMILY, TYPE, PROTOCOL>::setBuffer(Buffer<unsigned char>* buffer)
{
    this->buffer = buffer;
}

template <int FAMILY, int TYPE, int PROTOCOL>
ssize_t Socket<FAMILY, TYPE, PROTOCOL>::read(size_t length, int flags)
{
    if(socketFD == -1)
        throw Exceptions::Sockets::ClosedSocketException("Cannot read from closed socket.");

    if(buffer == nullptr)
        throw Exceptions::Sockets::MissingBufferException("You need to set up buffer before reading from socket.");

    if(length >= buffer->getSize())
        throw Exceptions::Sockets::InsufficientBufferSizeException("Cannot read more bytes than buffer can contain.");

    ssize_t bytesReceived = recv(socketFD, (void*) buffer->getAddress(), length, flags);

    if(bytesReceived == -1)
        throw Exceptions::General::SyscallException("Cannot read from socket.", errno);

    return bytesReceived;
}

template <int FAMILY, int TYPE, int PROTOCOL>
Socket<FAMILY, TYPE, PROTOCOL>::~Socket()
{
    if(socketFD == -1)
        return;

    close(socketFD);
}
