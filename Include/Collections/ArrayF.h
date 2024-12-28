#pragma once

#include "Mathematics/Math.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct ArrayF
{
	float* data;
	size_t size;
} ArrayF;


bool ArrayF_Contains(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

void ArrayF_Copy(const ArrayF* const _from, const size_t _fromIndex,
	             ArrayF* const _to, const size_t _toIndex, const size_t _count);

ArrayF* ArrayF_Create(const float _value, const size_t _size);

void ArrayF_Destroy(ArrayF** _array);

inline bool ArrayF_Equals(const ArrayF* const _left, const size_t _leftIndex, 
	               const ArrayF* const _right, const size_t _rightIndex);

void ArrayF_Fill(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

size_t ArrayF_FindIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

size_t ArrayF_FindLastIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

inline float ArrayF_Get(const ArrayF* const _array, const size_t _index);

inline size_t ArrayF_GetSize(const ArrayF* const _array);

inline bool ArrayF_IsNull(const ArrayF* const _array);

inline bool ArrayF_IsOutOfBounds(const ArrayF* const _array, const size_t _index);

inline bool ArrayF_IsValid(const ArrayF* const _array, const size_t _index);

float ArrayF_Max(const ArrayF* const _array, const size_t _index, const size_t _count);

float ArrayF_Min(const ArrayF* const _array, const size_t _index, const size_t _count);

void ArrayF_Reverse(const ArrayF* const _array, const size_t _index, const size_t _count);

inline void ArrayF_Set(ArrayF* const _array, const size_t _index, const float _value);

inline void ArrayF_ToString(char* _result, const size_t _resultSize, const ArrayF* const _array, const size_t _index);


#ifdef __cplusplus
}
#endif