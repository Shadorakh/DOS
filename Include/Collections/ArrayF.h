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

bool ArrayF_Equals(const ArrayF* const _left, const size_t _leftIndex, 
	               const ArrayF* const _right, const size_t _rightIndex);

void ArrayF_Fill(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

size_t ArrayF_FindIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

size_t ArrayF_FindLastIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count);

float ArrayF_Get(const ArrayF* const _array, const size_t _index);

size_t ArrayF_GetSize(const ArrayF* const _array);

bool ArrayF_IsNull(const ArrayF* const _array);

float ArrayF_Max(const ArrayF* const _array, const size_t _index, const size_t _count);

float ArrayF_Min(const ArrayF* const _array, const size_t _index, const size_t _count);

void ArrayF_Reverse(const ArrayF* const _array, const size_t _index, const size_t _count);

void ArrayF_Set(ArrayF* const _array, const size_t _index, const float _value);

void ArrayF_ToString(char* _result, const size_t _resultSize, const ArrayF* const _array, const size_t _index);



inline bool ArrayF_Equals(const ArrayF* const _left, const size_t _leftIndex,
	                      const ArrayF* const _right, const size_t _rightIndex)
{
	const float left = ArrayF_Get(_left, _leftIndex);
	const float right = ArrayF_Get(_right, _rightIndex);

	return (AbsF(left) < EPSILON) && (AbsF(right) < EPSILON);
}

inline void ArrayF_Set(ArrayF* const _array, const size_t _index, const float _value)
{
	if (_index >= ArrayF_GetSize(_array))
	{
		printf("[ERROR] Out of range\n");
		exit(EXIT_FAILURE);
	}

	_array->data[_index] = _value;
}

inline float ArrayF_Get(const ArrayF* const _array, const size_t _index)
{
	if (_index >= ArrayF_GetSize(_array))
	{
		printf("[ERROR] Out of range\n");
		exit(EXIT_FAILURE);
	}

	return _array->data[_index];
}

inline size_t ArrayF_GetSize(const ArrayF* const _array)
{
	return _array->size;
}

inline bool ArrayF_IsNull(const ArrayF* const _array)
{
	return (_array == NULL || _array->data == NULL);
}

inline void ArrayF_ToString(char* _result, const size_t _resultSize, const ArrayF* const _array, const size_t _index)
{
	snprintf(_result, _resultSize, "%.6f", ArrayF_Get(_array, _index));
}

#ifdef __cplusplus
}
#endif