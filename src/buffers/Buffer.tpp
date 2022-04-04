#include <netcover/exceptions/general/SyscallException.h>
#include <netcover/exceptions/buffers/OutOfBoundsException.h>

#include <errno.h>
#include <stdlib.h>

using namespace Netcover::Buffers;

template <typename T>
Buffer<T>::Buffer(unsigned int size)
{
    data = (BufferMember*) calloc(size, sizeof(BufferMember));

    if(data == NULL)
        throw Exceptions::General::SyscallException("Cannot allocate memory for buffer.", errno);

    this->size = size;
}

template <typename T>
typename Buffer<T>::BufferMember& Buffer<T>::operator[](unsigned int index)
{
    if(index >= size)
        throw Exceptions::Buffers::OutOfBoundsException("Trying to access unaccessible index.");

    return data[index];
}

template <typename T>
Buffer<T>::~Buffer()
{
    if(size == 0)
        return;

    free(data);
}