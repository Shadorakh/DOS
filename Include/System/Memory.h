#pragma once

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


int Memory_Alloc(void** _result, const size_t _size);

int Memory_Copy(const void* const _from, void* const _to, const size_t _size);

int Memory_Duplicate(void** _result, const void* const _source, const size_t _size);

int Memory_Free(void** _value);

int Memory_Set(void* const _destination, const int _value, const size_t _size);

int Memory_SetZero(void* const _destination, const size_t _size);


#ifdef __cplusplus
}
#endif