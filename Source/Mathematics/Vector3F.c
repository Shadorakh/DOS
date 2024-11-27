#include "Mathematics/Vector3F.h"

#include <stdlib.h>


void Vector3F_Add(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F vector = Vector3F_AddScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector3F_Angle(ArrayF* const _result, const size_t _resultIndex,
	                const Vector3F* const _from, const size_t _fromIndex,
	                const Vector3F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float angle = Vector3F_AngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, angle);
	}
}

void Vector3F_Copy(const Vector3F* const _from, const size_t _fromIndex,
	               Vector3F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector3F_CopyScalar(_from, i + _fromIndex, _to, i + _toIndex);
	}
}

Vector3F* Vector3F_Create(const float _x, const float _y, const float _z, const size_t _size)
{
	Vector3F* vector = (Vector3F*)_aligned_malloc(sizeof(Vector3F), 64);
	if (vector == NULL)
	{
		printf("[ERROR] Failed to allocate memory for Vector3F\n");
		exit(EXIT_FAILURE);
	}

	float* block = (float*)_aligned_malloc(3 * _size * sizeof(float), 64);
	if (block == NULL)
	{
		printf("[ERROR] Failed to allocate a block of memory for Vector3F\n");
		_aligned_free(vector);
		exit(EXIT_FAILURE);
	}

	vector->x.data = block + _size * 0;
	vector->y.data = block + _size * 1;
	vector->z.data = block + _size * 2;

	for (size_t i = 0; i < _size; i++)
	{
		ArrayF_Set(&vector->x, i, _x);
		ArrayF_Set(&vector->y, i, _y);
		ArrayF_Set(&vector->z, i, _z);
	}

	vector->x.size = _size;
	vector->y.size = _size;
	vector->z.size = _size;

	return vector;
}

Vector3F* Vector3F_CreateZero(const size_t _size)
{
	return Vector3F_Create(0.0F, 0.0F, 0.0F, _size);
}

void Vector3F_Cross(Vector3F* const _result, const size_t _resultIndex, 
	                const Vector3F* const _left, const size_t _leftIndex, 
	                const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F cross = Vector3F_CrossScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, cross);
	}
}

void Vector3F_Destroy(Vector3F** _vector)
{
	if (_vector != NULL && *_vector != NULL)
	{
		_aligned_free((*_vector)->x.data);
		_aligned_free(*_vector);
		*_vector = NULL;
	}
}

void Vector3F_Distance(ArrayF* const _result, const size_t _resultIndex,
	                   const Vector3F* const _from, const size_t _fromIndex,
	                   const Vector3F* const _to, const size_t _toIndex, size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float distance = Vector3F_DistanceScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distance);
	}
}

void Vector3F_DistanceSquared(ArrayF* const _result, const size_t _resultIndex,
	                          const Vector3F* const _from, const size_t _fromIndex,
	                          const Vector3F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float distanceSquared = Vector3F_DistanceSquaredScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distanceSquared);
	}
}

void Vector3F_Divide(Vector3F* const _result, const size_t _resultIndex,
	                 const Vector3F* const _left, const size_t _leftIndex,
	                 const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F vector = Vector3F_DivideScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector3F_Dot(ArrayF* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float dot = Vector3F_DotScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		ArrayF_Set(_result, i + _resultIndex, dot);
	}
}

void Vector3F_Length(ArrayF* const _result, const size_t _resultIndex,
	                 const Vector3F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float length = Vector3F_LengthScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, length);
	}
}

void Vector3F_LengthSquared(ArrayF* const _result, const size_t _resultIndex,
	                        const Vector3F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float lengthSquared = Vector3F_LengthSquaredScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, lengthSquared);
	}
}

void Vector3F_Lerp(Vector3F* const _result, const size_t _resultIndex,
	               const Vector3F* const _left, const size_t _leftIndex,
	               const Vector3F* const _right, const size_t _rightIndex,
	               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F lerp = Vector3F_LerpScalar(_left, i + _leftIndex, _right, i + _rightIndex,
			                                     _interpolationFactor, i + _interpolationFactorIndex);
		Vector3F_Set(_result, i + _resultIndex, lerp);
	}
}

void Vector3F_LerpUnclamped(Vector3F* const _result, const size_t _resultIndex,
	                        const Vector3F* const _left, const size_t _leftIndex,
	                        const Vector3F* const _right, const size_t _rightIndex,
	                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F lerpUnclamped = Vector3F_LerpUnclampedScalar(_left, i + _leftIndex, _right, i + _rightIndex,
			                                                       _interpolationFactor, i + _interpolationFactorIndex);
		Vector3F_Set(_result, i + _resultIndex, lerpUnclamped);
	}
}

void Vector3F_Max(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F max = Vector3F_MaxScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, max);
	}
}

void Vector3F_Min(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F min = Vector3F_MinScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, min);
	}
}

void Vector3F_MoveTowards(Vector3F* const _result, const size_t _resultIndex,
	                      const Vector3F* const _current, const size_t _currentIndex,
	                      const Vector3F* const _target, const size_t _targetIndex,
	                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F moveTowards = Vector3F_MoveTowardsScalar(_current, i + _currentIndex, _target, i + _targetIndex,
			                                                   _maxDistanceDelta, i + _maxDistanceDeltaIndex);
		Vector3F_Set(_result, i + _resultIndex, moveTowards);
	}
}

void Vector3F_Multiply(Vector3F* const _result, const size_t _resultIndex,
	                   const Vector3F* const _left, const size_t _leftIndex,
	                   const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F vector = Vector3F_MultiplyScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector3F_Normalize(Vector3F* const _vector, const size_t _index, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector3F_NormalizeScalar(_vector, i + _index);
	}
}

void Vector3F_Project(Vector3F* const _result, const size_t _resultIndex,
	                  const Vector3F* const _vector, const size_t _vectorIndex,
	                  const Vector3F* const _onNormal, const size_t _onNormalIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F project = Vector3F_ProjectScalar(_vector, i + _vectorIndex, _onNormal, i + _onNormalIndex);
		Vector3F_Set(_result, i + _resultIndex, project);
	}
}

void Vector3F_ProjectOnPlane(Vector3F* const _result, const size_t _resultIndex,
	                         const Vector3F* const _vector, const size_t _vectorIndex,
	                         const Vector3F* const _planeNormal, const size_t _planeNormalIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F projectOnPlane = Vector3F_ProjectOnPlaneScalar(_vector, i + _vectorIndex, _planeNormal, i + _planeNormalIndex);
		Vector3F_Set(_result, i + _resultIndex, projectOnPlane);
	}
}

void Vector3F_Reflect(Vector3F* const _result, const size_t _resultIndex,
	                  const Vector3F* const _inDirection, const size_t _inDirectionIndex,
	                  const Vector3F* const _inNormal, const size_t _inNormalIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F vector = Vector3F_ReflectScalar(_inDirection, i + _inDirectionIndex, _inNormal, i + _inNormalIndex);
		Vector3F_Set(_result, i + _resultIndex, vector);
	}
}

void Vector3F_SignedAngle(ArrayF* const _result, const size_t _resultIndex,
	                      const Vector3F* const _from, const size_t _fromIndex,
	                      const Vector3F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const float signedAngle = Vector3F_SignedAngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, signedAngle);
	}
}

void Vector3F_SmoothDamp(Vector3F* const _result, const size_t _resultIndex,
	                     const Vector3F* const _current, const size_t _currentIndex,
	                     const Vector3F* const _target, const size_t _targetIndex,
	                     Vector3F* const _currentVelocity, const size_t _currentVelocityIndex,
	                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F smoothDamp = Vector3F_SmoothDampScalar(_current, i + _currentIndex, _target, i + _targetIndex,
			                                                 _currentVelocity, i + _currentVelocityIndex, _smoothTime, i + _smoothTimeIndex,
			                                                 _maxSpeed, i + _maxSpeedIndex, _deltaTime, i + _deltaTimeIndex);
		Vector3F_Set(_result, i + _resultIndex, smoothDamp);
	}
}

void Vector3F_Subtract(Vector3F* const _result, const size_t _resultIndex,
	                   const Vector3F* const _left, const size_t _leftIndex,
	                   const Vector3F* const _right, const size_t _rightIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		const Tuple3F vector = Vector3F_SubtractScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector3F_Set(_result, i + _resultIndex, vector);
	}
}