#include "Mathematics/Vector2F.h"

#include <stdlib.h>


int Vector2F_Add(Vector2F* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) || 
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) || 
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_AddScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}

	return 0;
}

inline Tuple2F Vector2F_AddScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(left.x + right.x, left.y + right.y);
}


int Vector2F_Angle(ArrayF* const _result, const size_t _resultIndex,
	               const Vector2F* const _from, const size_t _fromIndex,
	               const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_from, _fromIndex + _count - 1) ||
		!Vector2F_IsValid(_to, _toIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float angle = Vector2F_AngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, angle);
	}

	return 0;
}

inline float Vector2F_AngleScalar(const Vector2F* const _from, const size_t _fromIndex,
	                              const Vector2F* const _to, const size_t _toIndex)
{
	const float magnitudeProduct = SqrtF(Vector2F_LengthSquaredScalar(_from, _fromIndex) *
		Vector2F_LengthSquaredScalar(_to, _toIndex));

	if (magnitudeProduct != EPSILON)
	{
		const float dotProductNormalized = ClampF(Vector2F_DotScalar(_from, _fromIndex, _to, _toIndex) /
			magnitudeProduct, -1.0F, 1.0F);

		return AcosF(dotProductNormalized) * (180.0F / 3.14159265F);
	}
	else
	{
		return 0.0F;
	}
}


int Vector2F_Copy(const Vector2F* const _from, const size_t _fromIndex,
	              Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_from, _fromIndex + _count - 1) ||
		!Vector2F_IsValid(_to, _toIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		Vector2F_CopyScalar(_from, i + _fromIndex, _to, i + _toIndex);
	}

	return 0;
}

inline void Vector2F_CopyScalar(const Vector2F* const _from, const size_t _fromIndex,
	                            Vector2F* const _to, const size_t _toIndex)
{
	const Tuple2F from = Vector2F_Get(_from, _fromIndex);

	Vector2F_Set(_to, _toIndex, from);
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

int Vector2F_Distance(ArrayF* const _result, const size_t _resultIndex,
	                  const Vector2F* const _from, const size_t _fromIndex,
	                  const Vector2F* const _to, const size_t _toIndex, size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_from, _fromIndex + _count - 1) ||
		!Vector2F_IsValid(_to, _toIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float distance = Vector2F_DistanceScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distance);
	}

	return 0;
}

inline float Vector2F_DistanceScalar(const Vector2F* const _from, const size_t _fromIndex,
	                                 const Vector2F* const _to, const size_t _toIndex)
{
	const Tuple2F from = Vector2F_Get(_from, _fromIndex);
	const Tuple2F to = Vector2F_Get(_to, _toIndex);

	const float x = from.x - to.x;
	const float y = from.y - to.x;

	return SqrtF(x * x + y * y);
}


int Vector2F_DistanceSquared(ArrayF* const _result, const size_t _resultIndex,
	                         const Vector2F* const _from, const size_t _fromIndex,
	                         const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_from, _fromIndex + _count - 1) ||
		!Vector2F_IsValid(_to, _toIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float distanceSquared = Vector2F_DistanceSquaredScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, distanceSquared);
	}

	return 0;
}

inline float Vector2F_DistanceSquaredScalar(const Vector2F* const _from, const size_t _fromIndex,
	                                        const Vector2F* const _to, const size_t _toIndex)
{
	const Tuple2F from = Vector2F_Get(_from, _fromIndex);
	const Tuple2F to = Vector2F_Get(_to, _toIndex);

	const float x = from.x - to.x;
	const float y = from.y - to.x;

	return (x * x + y * y);
}


int Vector2F_Divide(Vector2F* const _result, const size_t _resultIndex,
	                const Vector2F* const _left, const size_t _leftIndex,
	                const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_DivideScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}

	return 0;
}

inline Tuple2F Vector2F_DivideScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                 const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(AbsF(right.x) > EPSILON ? left.x / right.x : 0.0F,
		                  AbsF(right.y) > EPSILON ? left.y / right.y : 0.0F);
}


int Vector2F_Dot(ArrayF* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float dot = Vector2F_DotScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		ArrayF_Set(_result, i + _resultIndex, dot);
	}

	return 0;
}

inline float Vector2F_DotScalar(const Vector2F* const _left, const size_t _leftIndex,
	                            const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return (left.x * right.x + left.y * right.y);
}


inline Tuple2F Vector2F_DownScalar(void)
{
	return Tuple2F_Create(0.0F, -1.0F);
}


inline bool Vector2F_Equals(const Vector2F* const _left, const size_t _leftIndex,
	                        const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return (AbsF(left.x - right.x) < EPSILON) &&
		(AbsF(left.y - right.y) < EPSILON);
}


inline Tuple2F Vector2F_Get(const Vector2F* const _vector, const size_t _index)
{
	return Tuple2F_Create(ArrayF_Get(&_vector->x, _index), ArrayF_Get(&_vector->y, _index));
}


inline bool Vector2F_IsNull(const Vector2F* const _vector)
{
	return (_vector == NULL || _vector->x.data == NULL || _vector->y.data == NULL);
}

inline bool Vector2F_IsOutOfBounds(const Vector2F* const _vector, const size_t _index)
{
	return _index >= _vector->x.size || _index >= _vector->y.size;
}

inline bool Vector2F_IsValid(const Vector2F* const _vector, const size_t _index)
{
	if (Vector2F_IsNull(_vector))
	{
		return false;
	}

	if (Vector2F_IsOutOfBounds(_vector, _index))
	{
		return false;
	}

	return true;
}


inline Tuple2F Vector2F_LeftScalar(void)
{
	return Tuple2F_Create(-1.0F, 0.0F);
}


int Vector2F_Length(ArrayF* const _result, const size_t _resultIndex,
	                const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_vector, _vectorIndex + _count - 1))
	{
		return 1;
	}
	for (size_t i = 0; i < _count; i++)
	{
		const float length = Vector2F_LengthScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, length);
	}

	return 0;
}

inline float Vector2F_LengthScalar(const Vector2F* const _vector, const size_t _index)
{
	const Tuple2F vector = Vector2F_Get(_vector, _index);

	return SqrtF(vector.x * vector.x + vector.y * vector.y);
}


int Vector2F_LengthSquared(ArrayF* const _result, const size_t _resultIndex,
	                       const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	if (!ArrayF_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_vector, _vectorIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float lengthSquared = Vector2F_LengthSquaredScalar(_vector, i + _vectorIndex);
		ArrayF_Set(_result, i + _resultIndex, lengthSquared);
	}

	return 0;
}

inline float Vector2F_LengthSquaredScalar(const Vector2F* const _vector, const size_t _index)
{
	const Tuple2F vector = Vector2F_Get(_vector, _index);

	return (vector.x * vector.x + vector.y * vector.y);
}


int Vector2F_Lerp(Vector2F* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex,
	              const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1) || 
		!ArrayF_IsValid(_interpolationFactor, _interpolationFactorIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F lerp = Vector2F_LerpScalar(_left, i + _leftIndex, _right, i + _rightIndex, 
			                               _interpolationFactor, i + _interpolationFactorIndex);
		Vector2F_Set(_result, i + _resultIndex, lerp);
	}

	return 0;
}

inline Tuple2F Vector2F_LerpScalar(const Vector2F* const _start, const size_t _startIndex,
	                               const Vector2F* const _end, const size_t _endIndex,
	                               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex)
{
	const Tuple2F start = Vector2F_Get(_start, _startIndex);
	const Tuple2F end = Vector2F_Get(_end, _endIndex);
	const float interpolationFactor = ArrayF_Get(_interpolationFactor, _interpolationFactorIndex);

	const float interpolationFactorClamped = Clamp01F(interpolationFactor);

	return Tuple2F_Create(start.x + (end.x - start.x) * interpolationFactorClamped,
		start.y + (end.y - start.y) * interpolationFactorClamped);
}


int Vector2F_LerpUnclamped(Vector2F* const _result, const size_t _resultIndex,
	                       const Vector2F* const _left, const size_t _leftIndex,
	                       const Vector2F* const _right, const size_t _rightIndex,
	                       const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1) ||
		!ArrayF_IsValid(_interpolationFactor, _interpolationFactorIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F lerpUnclamped = Vector2F_LerpUnclampedScalar(_left, i + _leftIndex, _right, i + _rightIndex, 
			                                                       _interpolationFactor, i + _interpolationFactorIndex);
		Vector2F_Set(_result, i + _resultIndex, lerpUnclamped);
	}

	return 0;
}

inline Tuple2F Vector2F_LerpUnclampedScalar(const Vector2F* const _start, const size_t _startIndex,
	                                        const Vector2F* const _end, const size_t _endIndex,
	                                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex)
{
	const Tuple2F start = Vector2F_Get(_start, _startIndex);
	const Tuple2F end = Vector2F_Get(_end, _endIndex);
	const float interpolationFactor = ArrayF_Get(_interpolationFactor, _interpolationFactorIndex);

	return Tuple2F_Create(start.x + (end.x - start.x) * interpolationFactor,
		start.y + (end.y - start.y) * interpolationFactor);
}


int Vector2F_Max(Vector2F* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F max = Vector2F_MaxScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, max);
	}

	return 0;
}

inline Tuple2F Vector2F_MaxScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(MaxF(left.x, right.x),
		MaxF(left.y, right.y));
}


int Vector2F_Min(Vector2F* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F min = Vector2F_MinScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, min);
	}

	return 0;
}

inline Tuple2F Vector2F_MinScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(MinF(left.x, right.x),
		MinF(left.y, right.y));
}

int Vector2F_MoveTowards(Vector2F* const _result, const size_t _resultIndex,
	                     const Vector2F* const _current, const size_t _currentIndex,
	                     const Vector2F* const _target, const size_t _targetIndex,
	                     const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_current, _currentIndex + _count - 1) ||
		!Vector2F_IsValid(_target, _targetIndex + _count - 1) ||
		!ArrayF_IsValid(_maxDistanceDelta, _maxDistanceDeltaIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F moveTowards = Vector2F_MoveTowardsScalar(_current, i + _currentIndex, _target, i + _targetIndex, 
			                                                   _maxDistanceDelta, i + _maxDistanceDeltaIndex);
		Vector2F_Set(_result, i + _resultIndex, moveTowards);
	}

	return 0;
}

inline Tuple2F Vector2F_MoveTowardsScalar(const Vector2F* const _current, const size_t _currentIndex,
	                                      const Vector2F* const _target, const size_t _targetIndex,
	                                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex)
{
	const Tuple2F current = Vector2F_Get(_current, _currentIndex);
	const Tuple2F target = Vector2F_Get(_target, _targetIndex);
	const float maxDistanceDelta = ArrayF_Get(_maxDistanceDelta, _maxDistanceDeltaIndex);

	const float x = target.x - current.x;
	const float y = target.y - current.y;
	const float lengthSquared = x * x + y * y;

	if (lengthSquared == 0.0F || maxDistanceDelta >= 0.0F && lengthSquared <= maxDistanceDelta * maxDistanceDelta)
	{
		return Tuple2F_Create(target.x, target.y);
	}

	const float length = SqrtF(lengthSquared);

	return Tuple2F_Create(current.x + x / length * maxDistanceDelta, current.y + y / length * maxDistanceDelta);
}


int Vector2F_Multiply(Vector2F* const _result, const size_t _resultIndex,
	                  const Vector2F* const _left, const size_t _leftIndex,
	                  const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_MultiplyScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}

	return 0;
}

inline Tuple2F Vector2F_MultiplyScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                   const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(left.x * right.x, left.y * right.y);
}


int Vector2F_Normalize(Vector2F* const _vector, const size_t _index, const size_t _count)
{
	if (!Vector2F_IsValid(_vector, _index + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		Vector2F_NormalizeScalar(_vector, i + _index);
	}

	return 0;
}

inline void Vector2F_NormalizeScalar(Vector2F* const _vector, const size_t _index)
{
	Tuple2F vector = Vector2F_Get(_vector, _index);
	const float length = Vector2F_LengthScalar(_vector, _index);

	if (AbsF(length) > EPSILON)
	{
		vector.x /= length;
		vector.y /= length;
	}
	else
	{
		vector.x = 0.0F;
		vector.y = 0.0F;
	}

	Vector2F_Set(_vector, _index, vector);
}


inline Tuple2F Vector2F_OneScalar(void)
{
	return Tuple2F_Create(1.0F, 1.0F);
}


int Vector2F_Perpendicular(Vector2F* const _result, const size_t _resultIndex,
	                       const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_vector, _vectorIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F perpendicular = Vector2F_PerpendicularScalar(_vector, i + _vectorIndex);
		Vector2F_Set(_result, i + _resultIndex, perpendicular);
	}

	return 0;
}

inline Tuple2F Vector2F_PerpendicularScalar(const Vector2F* const _vector, const size_t _index)
{
	const Tuple2F vector = Vector2F_Get(_vector, _index);

	return Tuple2F_Create(-vector.y, vector.x);
}


int Vector2F_Reflect(Vector2F* const _result, const size_t _resultIndex,
	                 const Vector2F* const _inDirection, const size_t _inDirectionIndex,
	                 const Vector2F* const _inNormal, const size_t _inNormalIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_inDirection, _inDirectionIndex + _count - 1) ||
		!Vector2F_IsValid(_inNormal, _inNormalIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_ReflectScalar(_inDirection, i + _inDirectionIndex, _inNormal, i + _inNormalIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}

	return 0;
}

inline Tuple2F Vector2F_ReflectScalar(const Vector2F* const _inDirection, const size_t _inDirectonIndex,
	                                  const Vector2F* const _inNormal, const size_t _inNormalIndex)
{
	const Tuple2F inDirection = Vector2F_Get(_inDirection, _inDirectonIndex);
	const Tuple2F inNormal = Vector2F_Get(_inNormal, _inNormalIndex);

	const float factor = -2.0F * Vector2F_DotScalar(_inDirection, _inDirectonIndex, _inNormal, _inNormalIndex);

	return Tuple2F_Create(factor * inNormal.x + inDirection.x,
		factor * inNormal.y + inDirection.y);
}


inline Tuple2F Vector2F_RightScalar(void)
{
	return Tuple2F_Create(1.0F, 0.0F);
}


inline void Vector2F_Set(Vector2F* const _vector, const size_t _index, const Tuple2F _value)
{
	ArrayF_Set(&_vector->x, _index, _value.x);
	ArrayF_Set(&_vector->y, _index, _value.y);
}


int Vector2F_SignedAngle(ArrayF* const _result, const size_t _resultIndex,
	                     const Vector2F* const _from, const size_t _fromIndex,
	                     const Vector2F* const _to, const size_t _toIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_from, _fromIndex + _count - 1) ||
		!Vector2F_IsValid(_to, _toIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const float signedAngle = Vector2F_SignedAngleScalar(_from, i + _fromIndex, _to, i + _toIndex);
		ArrayF_Set(_result, i + _resultIndex, signedAngle);
	}

	return 0;
}

inline float Vector2F_SignedAngleScalar(const Vector2F* const _from, const size_t _fromIndex,
	                                    const Vector2F* const _to, const size_t _toIndex)
{
	const Tuple2F from = Vector2F_Get(_from, _fromIndex);
	const Tuple2F to = Vector2F_Get(_to, _toIndex);

	return (Vector2F_AngleScalar(_from, _fromIndex, _to, _toIndex) *
		SignF(from.x * to.y - from.y * to.x));
}


int Vector2F_SmoothDamp(Vector2F* const _result, const size_t _resultIndex,
	                    const Vector2F* const _current, const size_t _currentIndex,
	                    const Vector2F* const _target, const size_t _targetIndex,
	                    Vector2F* const _currentVelocity, const size_t _currentVelocityIndex,
	                    const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                    const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                    const ArrayF* const _deltaTime, const size_t _deltaTimeIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_current, _currentIndex + _count - 1) ||
		!Vector2F_IsValid(_target, _targetIndex + _count - 1) ||
		!Vector2F_IsValid(_currentVelocity, _currentVelocityIndex + _count - 1) || 
		!ArrayF_IsValid(_smoothTime, _smoothTimeIndex + _count - 1) ||
		!ArrayF_IsValid(_maxSpeed, _maxSpeedIndex + _count - 1) ||
		!ArrayF_IsValid(_deltaTime, _deltaTimeIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F smoothDamp = Vector2F_SmoothDampScalar(_current, i + _currentIndex, _target, i + _targetIndex,
			                                                 _currentVelocity, i + _currentVelocityIndex, _smoothTime, i + _smoothTimeIndex, 
			                                                 _maxSpeed, i + _maxSpeedIndex, _deltaTime, i + _deltaTimeIndex);
		Vector2F_Set(_result, i + _resultIndex, smoothDamp);
	}

	return 0;
}

inline Tuple2F Vector2F_SmoothDampScalar(const Vector2F* const _current, const size_t _currentIndex,
	                                     const Vector2F* const _target, const size_t _targetIndex,
	                                     Vector2F* const _currentVelocity, const size_t _currentVelocityIndex,
	                                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex)
{
	const Tuple2F current = Vector2F_Get(_current, _currentIndex);
	Tuple2F target = Vector2F_Get(_target, _targetIndex);
	Tuple2F currentVelocity = Vector2F_Get(_currentVelocity, _currentVelocityIndex);
	float smoothTime = ArrayF_Get(_smoothTime, _smoothTimeIndex);
	const float maxSpeed = ArrayF_Get(_maxSpeed, _maxSpeedIndex);
	const float deltaTime = ArrayF_Get(_deltaTime, _deltaTimeIndex);

	smoothTime = MaxF(0.0001F, smoothTime);
	const float omega = 2.0F / smoothTime;

	const float x = omega * deltaTime;
	const float exp = 1.0F / (1.0F + x + 0.48F * x * x + 0.235F * x * x * x);

	float changeX = current.x - target.x;
	float changeY = current.y - target.y;
	const Tuple2F originalTo = Tuple2F_Create(target.x, target.y);

	const float maxChange = maxSpeed * smoothTime;

	const float maxChangeSquared = maxChange * maxChange;
	const float DistSquared = changeX * changeX + changeY * changeY;

	if (DistSquared > maxChangeSquared)
	{
		const float length = SqrtF(DistSquared);
		changeX = changeX / length * maxChange;
		changeY = changeY / length * maxChange;
	}

	target.x = current.x - changeX;
	target.y = current.y - changeY;

	const float tempX = (currentVelocity.x + omega * changeX) * deltaTime;
	const float tempY = (currentVelocity.y + omega * changeY) * deltaTime;

	currentVelocity.x = (currentVelocity.x - omega * tempX) * exp;
	currentVelocity.y = (currentVelocity.y - omega * tempY) * exp;

	float outputX = target.x + (changeX + tempX) * exp;
	float outputY = target.y + (changeY + tempY) * exp;

	const float origMinusCurrentX = originalTo.x - current.x;
	const float origMinusCurrentY = originalTo.y - current.y;
	const float outMinusOrigX = outputX - originalTo.x;
	const float outMinusOrigY = outputY - originalTo.y;

	if (origMinusCurrentX * outMinusOrigX + origMinusCurrentY * outMinusOrigY > 0)
	{
		outputX = originalTo.x;
		outputY = originalTo.y;

		currentVelocity.x = (outputX - originalTo.x) / deltaTime;
		currentVelocity.y = (outputY - originalTo.y) / deltaTime;
	}

	Vector2F_Set(_currentVelocity, _currentVelocityIndex, currentVelocity);

	return Tuple2F_Create(outputX, outputY);
}


int Vector2F_Subtract(Vector2F* const _result, const size_t _resultIndex,
	                  const Vector2F* const _left, const size_t _leftIndex,
	                  const Vector2F* const _right, const size_t _rightIndex, const size_t _count)
{
	if (!Vector2F_IsValid(_result, _resultIndex + _count - 1) ||
		!Vector2F_IsValid(_left, _leftIndex + _count - 1) ||
		!Vector2F_IsValid(_right, _rightIndex + _count - 1))
	{
		return 1;
	}

	for (size_t i = 0; i < _count; i++)
	{
		const Tuple2F vector = Vector2F_SubtractScalar(_left, i + _leftIndex, _right, i + _rightIndex);
		Vector2F_Set(_result, i + _resultIndex, vector);
	}

	return 0;
}

inline Tuple2F Vector2F_SubtractScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                   const Vector2F* const _right, const size_t _rightIndex)
{
	const Tuple2F left = Vector2F_Get(_left, _leftIndex);
	const Tuple2F right = Vector2F_Get(_right, _rightIndex);

	return Tuple2F_Create(left.x - right.x, left.y - right.y);
}


inline void Vector2F_ToString(char* const _result, const size_t _resultSize, const Vector2F* const _vector, const size_t _index)
{
	const Tuple2F vector = Vector2F_Get(_vector, _index);

	snprintf(_result, _resultSize, "(%.6f, %.6f)", vector.x, vector.y);
}


inline Tuple2F Vector2F_UpScalar(void)
{
	return Tuple2F_Create(0.0F, 1.0F);
}


inline Tuple2F Vector2F_ZeroScalar(void)
{
	return Tuple2F_Create(0.0F, 0.0F);
}