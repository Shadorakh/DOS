#include "Collections/ArrayF.h"

#include <stdlib.h>


bool ArrayF_Contains(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		if (ArrayF_Get(_array, i + _index) == _value)
		{
			return true;
		}
	}

	return false;
}

void ArrayF_Copy(const ArrayF* const _from, const size_t _fromIndex, ArrayF* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		ArrayF_Set(_to, i + _toIndex, ArrayF_Get(_from, i + _fromIndex));
	}
}

ArrayF* ArrayF_Create(const float _value, const size_t _size)
{
	ArrayF* array = (ArrayF*)_aligned_malloc(sizeof(ArrayF), 64);
	if (array == NULL) 
	{
		printf("[ERROR] Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	float* block = (float*)_aligned_malloc(_size * sizeof(float), 64);
	if (block == NULL) 
	{
		printf("[ERROR] Failed to allocate a block of memory\n");
		_aligned_free(array);
		exit(EXIT_FAILURE);
	}

	array->data = block;
	array->size = _size;

	for (size_t i = 0; i < _size; i++)
	{
		ArrayF_Set(array, i, _value);
	}

	return array;
}

void ArrayF_Destroy(ArrayF** _array)
{
	if (_array != NULL && *_array != NULL)
	{
		_aligned_free((*_array)->data);
		_aligned_free(*_array);
		(*_array)->data = NULL;
		*_array = NULL;
		printf("Successful memory release!\n");
	}
}

inline bool ArrayF_Equals(const ArrayF* const _left, const size_t _leftIndex,
	                      const ArrayF* const _right, const size_t _rightIndex)
{
	const float left = ArrayF_Get(_left, _leftIndex);
	const float right = ArrayF_Get(_right, _rightIndex);

	return (AbsF(left) < EPSILON) && (AbsF(right) < EPSILON);
}

void ArrayF_Fill(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		ArrayF_Set(_array, i + _index, _value);
	}
}

size_t ArrayF_FindIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		if (ArrayF_Get(_array, i + _index) == _value)
		{
			return i + _index;
		}
	}

	return -1;
}

size_t ArrayF_FindLastIndex(const ArrayF* const _array, const size_t _index, const float _value, const size_t _count)
{
	for (size_t i = _count - 1; i > 0; i--)
	{
		if (ArrayF_Get(_array, i + _index) == _value)
		{
			return i + _index;
		}
	}

	return -1;
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

float ArrayF_Max(const ArrayF* const _array, const size_t _index, const size_t _count)
{
	float max = ArrayF_Get(_array, 0);

	for (size_t i = 0; i < _count; i++)
	{
		if (ArrayF_Get(_array, i + _index) > max)
		{
			max = ArrayF_Get(_array, i + _index);
		}
	}

	return max;
}

float ArrayF_Min(const ArrayF* const _array, const size_t _index, const size_t _count)
{
	float min = ArrayF_Get(_array, 0);

	for (size_t i = 0; i < _count; i++)
	{
		if (ArrayF_Get(_array, i + _index) < min)
		{
			min = ArrayF_Get(_array, i + _index);
		}
	}

	return min;
}

void ArrayF_Reverse(const ArrayF* const _array, const size_t _index, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		ArrayF_Set(_array, i + _index, ArrayF_Get(_array, _count - (1 + i)));
	}
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

inline void ArrayF_ToString(char* _result, const size_t _resultSize, const ArrayF* const _array, const size_t _index)
{
	snprintf(_result, _resultSize, "%.6f", ArrayF_Get(_array, _index));
}