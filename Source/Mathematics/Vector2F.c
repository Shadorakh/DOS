#include "Mathematics/Vector2F.h"

#include <stdlib.h>


void Vector2F_Add(Vector2F* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_AddScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector2F_Angle(ArrayF* const _result, const size_t _resultIndex,
	                const Vector2F* const _from, const size_t _fromIndex,
	                const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float angle = Vector2F_AngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, angle);
	}
}

void Vector2F_Copy(const Vector2F* const _from, const size_t _fromIndex,
	               Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector2F_CopyScalar(_from, i + _fromIndex, _to, i + _toIndex);
	}
}

Vector2F* Vector2F_Create(const float _x, const float _y, const size_t _size)
{
	Vector2F* vector = (Vector2F*)_aligned_malloc(sizeof(Vector2F), 64);
	if (vector == NULL)
	{
		printf("[ERROR] Failed to allocate memory for Vector2F\n");
		exit(EXIT_FAILURE);
	}

	float* block = (float*)_aligned_malloc(2 * _size * sizeof(float), 64);
	if (block == NULL)
	{
		printf("[ERROR] Failed to allocate a block of memory for Vector2F\n");
		_aligned_free(vector);
		exit(EXIT_FAILURE);
	}

	vector->x.data = block + _size * 0;
	vector->y.data = block + _size * 1;

	for (size_t i = 0; i < _size; i++)
	{
		ArrayF_Set(&vector->x, i, _x);
		ArrayF_Set(&vector->y, i, _y);
	}

	vector->x.size = _size;
	vector->y.size = _size;

	return vector;
}

Vector2F* Vector2F_CreateZero(const size_t _size)
{
	return Vector2F_Create(0.0F, 0.0F, _size);
}

void Vector2F_Destroy(Vector2F** _vector)
{
	if (_vector != NULL && *_vector != NULL)
	{
		_aligned_free((*_vector)->x.data);
		_aligned_free(*_vector);
		*_vector = NULL;
	}
}

void Vector2F_Distance(ArrayF* const _result, const size_t _resultIndex,
	                   const Vector2F* const _from, const size_t _fromIndex,
	                   const Vector2F* const _to, const size_t _toIndex, size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float distance = Vector2F_DistanceScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distance);
	}
}

void Vector2F_DistanceSquared(ArrayF* const _result, const size_t _resultIndex,
	                          const Vector2F* const _from, const size_t _fromIndex,
	                          const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float distanceSquared = Vector2F_DistanceSquaredScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distanceSquared);
	}
}

void Vector2F_Divide(Vector2F* const _result, const size_t _resultIndex,
	                 const Vector2F* const _left, const size_t _leftIndex,
	                 const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_DivideScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector2F_Dot(ArrayF* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float dot = Vector2F_DotScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		ArrayF_Set(_result, i + _resultIndex, dot);
	}
}

void Vector2F_Length(ArrayF* const _result, const size_t _resultIndex,
	                 const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float length = Vector2F_LengthScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, length);
	}
}

void Vector2F_LengthSquared(ArrayF* const _result, const size_t _resultIndex,
	                        const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float lengthSquared = Vector2F_LengthSquaredScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, lengthSquared);
	}
}

void Vector2F_Lerp(Vector2F* const _result, const size_t _resultIndex,
	               const Vector2F* const _left, const size_t _leftIndex,
	               const Vector2F* const _right, const size_t _rightIndex,
	               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F lerp = Vector2F_LerpScalar(_left, i + _leftIndex, _right, i + _rightIndex, 
			                               _interpolationFactor, i + _interpolationFactorIndex);
		Vector2F_Set(_result, i + _resultIndex, lerp);
	}
}

void Vector2F_LerpUnclamped(Vector2F* const _result, const size_t _resultIndex,
	                        const Vector2F* const _left, const size_t _leftIndex,
	                        const Vector2F* const _right, const size_t _rightIndex,
	                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F lerpUnclamped = Vector2F_LerpUnclampedScalar(_left, i + _leftIndex, _right, i + _rightIndex, 
			                                                       _interpolationFactor, i + _interpolationFactorIndex);
		Vector2F_Set(_result, i + _resultIndex, lerpUnclamped);
	}
}

void Vector2F_Max(Vector2F* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F max = Vector2F_MaxScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, max);
	}
}

void Vector2F_Min(Vector2F* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F min = Vector2F_MinScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, min);
	}
}

void Vector2F_MoveTowards(Vector2F* const _result, const size_t _resultIndex,
	                      const Vector2F* const _current, const size_t _currentIndex,
	                      const Vector2F* const _target, const size_t _targetIndex,
	                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F moveTowards = Vector2F_MoveTowardsScalar(_current, i + _currentIndex, _target, i + _targetIndex, 
			                                                   _maxDistanceDelta, i + _maxDistanceDeltaIndex);
		Vector2F_Set(_result, i + _resultIndex, moveTowards);
	}
}

void Vector2F_Multiply(Vector2F* const _result, const size_t _resultIndex,
	                   const Vector2F* const _left, const size_t _leftIndex,
	                   const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_MultiplyScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector2F_Normalize(Vector2F* const _vector, const size_t _index, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector2F_NormalizeScalar(_vector, i + _index);
	}
}

void Vector2F_Perpendicular(Vector2F* const _result, const size_t _resultIndex,
	                        const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F perpendicular = Vector2F_PerpendicularScalar(_vector, i + _vectorIndex);
		Vector2F_Set(_result, i + _resultIndex, perpendicular);
	}
}

void Vector2F_Reflect(Vector2F* const _result, const size_t _resultIndex,
	                  const Vector2F* const _inDirection, const size_t _inDirectionIndex,
	                  const Vector2F* const _inNormal, const size_t _inNormalIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_ReflectScalar(_inDirection, i + _inDirectionIndex, _inNormal, i + _inNormalIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector2F_SignedAngle(ArrayF* const _result, const size_t _resultIndex,
	                      const Vector2F* const _from, const size_t _fromIndex,
	                      const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float signedAngle = Vector2F_SignedAngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, signedAngle);
	}
}

void Vector2F_SmoothDamp(Vector2F* const _result, const size_t _resultIndex,
	                     const Vector2F* const _current, const size_t _currentIndex,
	                     const Vector2F* const _target, const size_t _targetIndex,
	                     Vector2F* const _currentVelocity, const size_t _currentVelocityIndex,
	                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F smoothDamp = Vector2F_SmoothDampScalar(_current, i + _currentIndex, _target, i + _targetIndex,
			                                                 _currentVelocity, i + _currentVelocityIndex, _smoothTime, i + _smoothTimeIndex, 
			                                                 _maxSpeed, i + _maxSpeedIndex, _deltaTime, i + _deltaTimeIndex);
		Vector2F_Set(_result, i + _resultIndex, smoothDamp);
	}
}

void Vector2F_Subtract(Vector2F* const _result, const size_t _resultIndex,
	                   const Vector2F* const _left, const size_t _leftIndex,
	                   const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_SubtractScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}
}