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

inline Tuple3F Vector3F_AddScalar(const Vector3F* const _left, const size_t _leftIndex,
	                              const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(left.x + right.x, left.y + right.y, left.z + right.z);
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

inline float Vector3F_AngleScalar(const Vector3F* const _from, const size_t _fromIndex,
	                              const Vector3F* const _to, const size_t _toIndex)
{
	float magnitudeProduct = SqrtF(Vector3F_LengthSquaredScalar(_from, _fromIndex) *
		Vector3F_LengthSquaredScalar(_to, _toIndex));

	if (magnitudeProduct != EPSILON)
	{
		float dotProductNormalized = ClampF(Vector3F_DotScalar(_from, _fromIndex, _to, _toIndex) /
			magnitudeProduct, -1.0F, 1.0F);

		return AcosF(dotProductNormalized) * (180.0F / 3.14159265F);
	}
	else
	{
		return 0.0F;
	}
}


inline Tuple3F Vector3F_BackScalar(void)
{
	return Tuple3F_Create(0.0F, 0.0F, -1.0F);
}


void Vector3F_Copy(const Vector3F* const _from, const size_t _fromIndex,
	               Vector3F* const _to, const size_t _toIndex, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector3F_CopyScalar(_from, i + _fromIndex, _to, i + _toIndex);
	}
}

inline void Vector3F_CopyScalar(const Vector3F* const _from, const size_t _fromIndex,
	                            Vector3F* const _to, const size_t _toIndex)
{
	const Tuple3F from = Vector3F_Get(_from, _fromIndex);

	Vector3F_Set(_to, _toIndex, from);
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

inline Tuple3F Vector3F_CrossScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
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

inline float Vector3F_DistanceScalar(const Vector3F* const _from, const size_t _fromIndex,
	                                 const Vector3F* const _to, const size_t _toIndex)
{
	const Tuple3F from = Vector3F_Get(_from, _fromIndex);
	const Tuple3F to = Vector3F_Get(_to, _toIndex);

	float x = from.x - to.x;
	float y = from.y - to.x;

	return SqrtF(x * x + y * y);
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

inline float Vector3F_DistanceSquaredScalar(const Vector3F* const _from, const size_t _fromIndex,
	                                        const Vector3F* const _to, const size_t _toIndex)
{
	const Tuple3F from = Vector3F_Get(_from, _fromIndex);
	const Tuple3F to = Vector3F_Get(_to, _toIndex);

	float x = from.x - to.x;
	float y = from.y - to.x;

	return (x * x + y * y);
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

inline Tuple3F Vector3F_DivideScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                 const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(AbsF(right.x) > EPSILON ? left.x / right.x : 0.0F,
		AbsF(right.y) > EPSILON ? left.y / right.y : 0.0F,
		AbsF(right.z) > EPSILON ? left.z / right.z : 0.0F);
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

inline float Vector3F_DotScalar(const Vector3F* const _left, const size_t _leftIndex,
	                            const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return (left.x * right.x + left.y * right.y);
}


inline Tuple3F Vector3F_DownScalar(void)
{
	return Tuple3F_Create(0.0F, -1.0F, 0.0F);
}


inline bool Vector3F_Equals(const Vector3F* const _left, const size_t _leftIndex,
	const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return (AbsF(left.x - right.x) < EPSILON) &&
		(AbsF(left.y - right.y) < EPSILON) &&
		(AbsF(left.z - right.z) < EPSILON);
}


inline Tuple3F Vector3F_ForwardScalar(void)
{
	return Tuple3F_Create(0.0F, 0.0F, 1.0F);
}


inline Tuple3F Vector3F_Get(const Vector3F* const _vector, const size_t _index)
{
	return Tuple3F_Create(ArrayF_Get(&_vector->x, _index), ArrayF_Get(&_vector->y, _index), ArrayF_Get(&_vector->z, _index));
}


inline bool Vector3F_IsNull(const Vector3F* const _vector)
{
	return (_vector == NULL || _vector->x.data == NULL || _vector->y.data == NULL || _vector->z.data == NULL);
}

inline bool Vector3F_IsOutOfBounds(const Vector3F* const _vector, const size_t _index)
{
	return _index >= _vector->x.size || _index >= _vector->y.size || _index >= _vector->z.size;
}

inline bool Vector3F_IsValid(const Vector3F* const _vector, const size_t _index)
{
	if (Vector3F_IsNull(_vector))
	{
		return false;
	}

	if (Vector3F_IsOutOfBounds(_vector, _index))
	{
		return false;
	}

	return true;
}


inline Tuple3F Vector3F_LeftScalar(void)
{
	return Tuple3F_Create(-1.0F, 0.0F, 0.0F);
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

inline float Vector3F_LengthScalar(const Vector3F* const _vector, const size_t _index)
{
	const Tuple3F vector = Vector3F_Get(_vector, _index);

	return SqrtF(vector.x * vector.x + vector.y * vector.y);
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

inline float Vector3F_LengthSquaredScalar(const Vector3F* const _vector, const size_t _index)
{
	const Tuple3F vector = Vector3F_Get(_vector, _index);

	return (vector.x * vector.x + vector.y * vector.y);
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

inline Tuple3F Vector3F_LerpScalar(const Vector3F* const _start, const size_t _startIndex,
	                               const Vector3F* const _end, const size_t _endIndex,
	                               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex)
{
	const Tuple3F start = Vector3F_Get(_start, _startIndex);
	const Tuple3F end = Vector3F_Get(_end, _endIndex);
	const float interpolationFactor = ArrayF_Get(_interpolationFactor, _interpolationFactorIndex);

	const float interpolationFactorClamped = Clamp01F(interpolationFactor);

	return Tuple3F_Create(start.x + (end.x - start.x) * interpolationFactorClamped,
		start.y + (end.y - start.y) * interpolationFactorClamped,
		start.z + (end.z - start.z) * interpolationFactorClamped);
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

inline Tuple3F Vector3F_LerpUnclampedScalar(const Vector3F* const _start, const size_t _startIndex,
	                                        const Vector3F* const _end, const size_t _endIndex,
	                                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex)
{
	const Tuple3F start = Vector3F_Get(_start, _startIndex);
	const Tuple3F end = Vector3F_Get(_end, _endIndex);
	const float interpolationFactor = ArrayF_Get(_interpolationFactor, _interpolationFactorIndex);

	return Tuple3F_Create(start.x + (end.x - start.x) * interpolationFactor,
		start.y + (end.y - start.y) * interpolationFactor,
		start.z + (end.z - start.z) * interpolationFactor);
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

inline Tuple3F Vector3F_MaxScalar(const Vector3F* const _left, const size_t _leftIndex,
	                              const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(MaxF(left.x, right.x),
		MaxF(left.y, right.y),
		MaxF(left.z, right.z));
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

inline Tuple3F Vector3F_MinScalar(const Vector3F* const _left, const size_t _leftIndex,
	                              const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(MinF(left.x, right.x),
		MinF(left.y, right.y),
		MinF(left.z, right.z));
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

inline Tuple3F Vector3F_MoveTowardsScalar(const Vector3F* const _current, const size_t _currentIndex,
	                                      const Vector3F* const _target, const size_t _targetIndex,
	                                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex)
{
	const Tuple3F current = Vector3F_Get(_current, _currentIndex);
	const Tuple3F target = Vector3F_Get(_target, _targetIndex);
	const float maxDistanceDelta = ArrayF_Get(_maxDistanceDelta, _maxDistanceDeltaIndex);

	const float toVectorX = target.x - current.x;
	const float toVectorY = target.y - current.y;
	const float toVectorZ = target.z - current.z;

	const float lengthSquared = toVectorX * toVectorX + toVectorY * toVectorY + toVectorZ * toVectorZ;

	if (lengthSquared == 0.0F || maxDistanceDelta >= 0.0F && lengthSquared <= maxDistanceDelta * maxDistanceDelta)
	{
		return Tuple3F_Create(target.x, target.y, target.z);
	}

	const float length = SqrtF(lengthSquared);

	return Tuple3F_Create(current.x + toVectorX / length * maxDistanceDelta,
		current.y + toVectorY / length * maxDistanceDelta,
		current.z + toVectorZ / length * maxDistanceDelta);
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

inline Tuple3F Vector3F_MultiplyScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                   const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(left.x * right.x, left.y * right.y, left.z * right.z);
}


void Vector3F_Normalize(Vector3F* const _vector, const size_t _index, const size_t _count)
{
	for (size_t i = 0; i < _count; i++)
	{
		Vector3F_NormalizeScalar(_vector, i + _index);
	}
}

inline void Vector3F_NormalizeScalar(Vector3F* const _vector, const size_t _index)
{
	Tuple3F vector = Vector3F_Get(_vector, _index);
	const float length = Vector3F_LengthScalar(_vector, _index);

	if (AbsF(length) > EPSILON)
	{
		vector.x /= length;
		vector.y /= length;
		vector.z /= length;
	}
	else
	{
		vector.x = 0.0F;
		vector.y = 0.0F;
		vector.z = 0.0F;
	}

	Vector3F_Set(_vector, _index, vector);
}


inline Tuple3F Vector3F_OneScalar(void)
{
	return Tuple3F_Create(1.0F, 1.0F, 1.0F);
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

inline Tuple3F Vector3F_ProjectScalar(const Vector3F* const _vector, const size_t _vectorIndex,
	                                  const Vector3F* const _onNormal, const size_t _onNormalIndex)
{
	const Tuple3F vector = Vector3F_Get(_vector, _vectorIndex);
	const Tuple3F onNormal = Vector3F_Get(_onNormal, _onNormalIndex);

	const float lengthSquared = Vector3F_DotScalar(_onNormal, _onNormalIndex, _onNormal, _onNormalIndex);

	if (lengthSquared < EPSILON)
	{
		return Vector3F_ZeroScalar();
	}
	else
	{
		const float dot = Vector3F_DotScalar(_vector, _vectorIndex, _onNormal, _onNormalIndex);

		return Tuple3F_Create(onNormal.x * dot / lengthSquared,
			onNormal.y * dot / lengthSquared,
			onNormal.y * dot / lengthSquared);
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

inline Tuple3F Vector3F_ProjectOnPlaneScalar(const Vector3F* const _vector, const size_t _vectorIndex,
	                                         const Vector3F* const _planeNormal, const size_t _planeNormalIndex)
{
	const Tuple3F vector = Vector3F_Get(_vector, _vectorIndex);
	const Tuple3F planeNormal = Vector3F_Get(_planeNormal, _planeNormalIndex);

	const float lengthSquared = Vector3F_DotScalar(_planeNormal, _planeNormalIndex, _planeNormal, _planeNormalIndex);

	if (lengthSquared < EPSILON)
	{
		return vector;
	}
	else
	{
		const float dot = Vector3F_DotScalar(_vector, _vectorIndex, _planeNormal, _planeNormalIndex);

		return Tuple3F_Create(vector.x - planeNormal.x * dot / lengthSquared,
			vector.y - planeNormal.y * dot / lengthSquared,
			vector.z - planeNormal.y * dot / lengthSquared);
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

inline Tuple3F Vector3F_ReflectScalar(const Vector3F* const _inDirection, const size_t _inDirectonIndex,
	                                  const Vector3F* const _inNormal, const size_t _inNormalIndex)
{
	const Tuple3F inDirection = Vector3F_Get(_inDirection, _inDirectonIndex);
	const Tuple3F inNormal = Vector3F_Get(_inNormal, _inNormalIndex);

	const float factor = -2.0F * Vector3F_DotScalar(_inDirection, _inDirectonIndex, _inNormal, _inNormalIndex);

	return Tuple3F_Create(factor * inNormal.x + inDirection.x,
		factor * inNormal.y + inDirection.y,
		factor * inNormal.z + inDirection.z);
}


inline Tuple3F Vector3F_RightScalar(void)
{
	return Tuple3F_Create(1.0F, 0.0F, 0.0F);
}


inline void Vector3F_Set(Vector3F* const _vector, const size_t _index, const Tuple3F _value)
{
	ArrayF_Set(&_vector->x, _index, _value.x);
	ArrayF_Set(&_vector->y, _index, _value.y);
	ArrayF_Set(&_vector->z, _index, _value.z);
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

inline float Vector3F_SignedAngleScalar(const Vector3F* const _from, const size_t _fromIndex,
	                                    const Vector3F* const _to, const size_t _toIndex)
{
	const Tuple3F from = Vector3F_Get(_from, _fromIndex);
	const Tuple3F to = Vector3F_Get(_to, _toIndex);

	float angle = Vector3F_AngleScalar(_from, _fromIndex, _to, _toIndex);
	float sign = SignF(from.x * to.y - from.y * to.x);

	return (angle * sign);
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

inline Tuple3F Vector3F_SmoothDampScalar(const Vector3F* const _current, const size_t _currentIndex,
	                                     const Vector3F* const _target, const size_t _targetIndex,
	                                     Vector3F* const _currentVelocity, const size_t _currentVelocityIndex,
	                                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex)
{
	const Tuple3F current = Vector3F_Get(_current, _currentIndex);
	Tuple3F target = Vector3F_Get(_target, _targetIndex);
	Tuple3F currentVelocity = Vector3F_Get(_currentVelocity, _currentVelocityIndex);
	float smoothTime = ArrayF_Get(_smoothTime, _smoothTimeIndex);
	const float maxSpeed = ArrayF_Get(_maxSpeed, _maxSpeedIndex);
	const float deltaTime = ArrayF_Get(_deltaTime, _deltaTimeIndex);

	smoothTime = MaxF(0.0001F, smoothTime);
	const float omega = 2.0F / smoothTime;

	const float x = omega * deltaTime;
	const float exp = 1.0F / (1.0F + x + 0.48F * x * x + 0.235F * x * x * x);

	float changeX = current.x - target.x;
	float changeY = current.y - target.y;
	float changeZ = current.z - target.z;
	const Tuple3F originalTo = target;

	const float maxChange = maxSpeed * smoothTime;

	const float maxChangeSquared = maxChange * maxChange;
	const float DistSquared = changeX * changeX + changeY * changeY + changeZ * changeZ;
	if (DistSquared > maxChangeSquared)
	{
		const float length = SqrtF(DistSquared);
		changeX = changeX / length * maxChange;
		changeY = changeY / length * maxChange;
		changeZ = changeZ / length * maxChange;
	}

	target.x = current.x - changeX;
	target.y = current.y - changeY;
	target.z = current.z - changeZ;

	const float tempX = (currentVelocity.x + omega * changeX) * deltaTime;
	const float tempY = (currentVelocity.y + omega * changeY) * deltaTime;
	const float tempZ = (currentVelocity.z + omega * changeZ) * deltaTime;

	currentVelocity.x = (currentVelocity.x - omega * tempX) * exp;
	currentVelocity.y = (currentVelocity.y - omega * tempY) * exp;
	currentVelocity.z = (currentVelocity.z - omega * tempZ) * exp;

	float outputX = target.x + (changeX + tempX) * exp;
	float outputY = target.y + (changeY + tempY) * exp;
	float outputZ = target.z + (changeZ + tempZ) * exp;

	const float origMinusCurrentX = originalTo.x - current.x;
	const float origMinusCurrentY = originalTo.y - current.y;
	const float origMinusCurrentZ = originalTo.z - current.z;
	const float outMinusOrigX = outputX - originalTo.x;
	const float outMinusOrigY = outputY - originalTo.y;
	const float outMinusOrigZ = outputZ - originalTo.z;

	if (origMinusCurrentX * outMinusOrigX + origMinusCurrentY * outMinusOrigY + origMinusCurrentZ * outMinusOrigZ > 0)
	{
		outputX = originalTo.x;
		outputY = originalTo.y;
		outputZ = originalTo.z;

		currentVelocity.x = (outputX - originalTo.x) / deltaTime;
		currentVelocity.y = (outputY - originalTo.y) / deltaTime;
		currentVelocity.z = (outputZ - originalTo.z) / deltaTime;
	}

	Vector3F_Set(_currentVelocity, _currentVelocityIndex, currentVelocity);

	return Tuple3F_Create(outputX, outputY, outputZ);
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

inline Tuple3F Vector3F_SubtractScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                   const Vector3F* const _right, const size_t _rightIndex)
{
	const Tuple3F left = Vector3F_Get(_left, _leftIndex);
	const Tuple3F right = Vector3F_Get(_right, _rightIndex);

	return Tuple3F_Create(left.x - right.x, left.y - right.y, left.z - right.z);
}


inline void Vector3F_ToString(char* const _result, const size_t _resultSize, const Vector3F* const _vector, const size_t _index)
{
	const Tuple3F vector = Vector3F_Get(_vector, _index);

	snprintf(_result, _resultSize, "(%.6f, %.6f, %.6f)", vector.x, vector.y, vector.z);
}


inline Tuple3F Vector3F_UpScalar(void)
{
	return Tuple3F_Create(0.0F, 1.0F, 0.0F);
}


inline Tuple3F Vector3F_ZeroScalar(void)
{
	return Tuple3F_Create(0.0F, 0.0F, 0.0F);
}