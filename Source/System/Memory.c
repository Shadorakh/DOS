#include "System/Memory.h"

#include <stdio.h>
#include <string.h>


int Memory_Alloc(void** _result, const size_t _size)
{
    if (_result == NULL)
    {
        fprintf(stderr, "Error: Null pointer\n");
        return 1;
    }

    size_t alignment = 64;

    void* rawPointer = malloc(_size + alignment - 1 + sizeof(void*));

    if (rawPointer == NULL) 
    {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        return 1;
    }

    uintptr_t rawAddress = (uintptr_t)rawPointer + sizeof(void*);
    uintptr_t alignedAddress = (rawAddress + alignment - 1) & ~(alignment - 1);

    ((void**)alignedAddress)[-1] = rawPointer;

    *_result = (void*)alignedAddress;

    return 0;
}

int Memory_Copy(const void* const _from, void* const _to, const size_t _size)
{
    if (_from == NULL || _to == NULL)
    {
        fprintf(stderr, "Error: Null pointer\n");
        return 1;
    }

    memmove(_to, _from, _size);

    return 0;
}

int Memory_Duplicate(void** _result, const void* const _source, const size_t _size)
{
    if (_source == NULL)
    {
        fprintf(stderr, "Error: Null pointer\n");
        return 1;
    }

    if (Memory_Alloc(_result, _size) != 0)
    {
        return 1;
    }

    memcpy(*_result, _source, _size);
    return 0;
}

int Memory_Free(void** _value)
{
    if (_value == NULL || *_value == NULL)
    {
        fprintf(stderr, "Error: Null pointer\n");
        return 1;
    }

    free(((void**)(*_value))[-1]);
    *_value = NULL;

    return 0;
}

int Memory_Set(void* const _destination, const int _value, const size_t _size)
{
    if (_destination == NULL) 
    {
        fprintf(stderr, "Error: Null pointer\n");
        return 1;
    }

    memset(_destination, _value, _size);
    return 0;
}

int Memory_SetZero(void* const _destination, const size_t _size)
{
    return Memory_Set(_destination, 0, _size);
}
