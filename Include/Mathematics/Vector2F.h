#pragma once

#include "Collections/Tuple.h"
#include "Collections/ArrayF.h"
#include "Math.h"

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct Vector2F
{
	ArrayF x;
	ArrayF y;
} Vector2F;


int Vector2F_Add(Vector2F* const _result, const size_t _resultIndex, 
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_AddScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex);

int Vector2F_Angle(ArrayF* const _result, const size_t _resultIndex,
	               const Vector2F* const _from, const size_t _fromIndex,
	               const Vector2F* const _to, const size_t _toIndex, size_t _count);

inline float Vector2F_AngleScalar(const Vector2F* const _from, const size_t _fromIndex,
	                              const Vector2F* const _to, const size_t _toIndex);

int Vector2F_Copy(const Vector2F* const _from, const size_t _fromIndex,
	              Vector2F* const _to, const size_t _toIndex, const size_t _count);

inline void Vector2F_CopyScalar(const Vector2F* const _from, const size_t _fromIndex,
						        Vector2F* const _to, const size_t _toIndex);

Vector2F* Vector2F_Create(const float _x, const float _y, const size_t _size);

Vector2F* Vector2F_CreateZero(const size_t _size);

void Vector2F_Destroy(Vector2F** _vector);

int Vector2F_Distance(ArrayF* const _result, const size_t _resultIndex,
	                  const Vector2F* const _from, const size_t _fromIndex,
	                  const Vector2F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector2F_DistanceScalar(const Vector2F* const _from, const size_t _fromIndex,
	                                 const Vector2F* const _to, const size_t _toIndex);

int Vector2F_DistanceSquared(ArrayF* const _result, const size_t _resultIndex,
	                         const Vector2F* const _from, const size_t _fromIndex,
	                         const Vector2F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector2F_DistanceSquaredScalar(const Vector2F* const _from, const size_t _leftIndex,
	                                        const Vector2F* const _to, const size_t _rightIndex);

int Vector2F_Divide(Vector2F* const _result, const size_t _resultIndex,
	                const Vector2F* const _left, const size_t _leftIndex,
	                const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_DivideScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                 const Vector2F* const _right, const size_t _rightIndex);

int Vector2F_Dot(ArrayF* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline float Vector2F_DotScalar(const Vector2F* const _left, const size_t _leftIndex,
	                            const Vector2F* const _right, const size_t _rightIndex);

inline Tuple2F Vector2F_DownScalar(void);

inline bool Vector2F_Equals(const Vector2F* const _left, const size_t _leftIndex,
	                        const Vector2F* const _right, const size_t _rightIndex);

inline Tuple2F Vector2F_Get(const Vector2F* const _vector, const size_t _index);

inline bool Vector2F_IsNull(const Vector2F* const _vector);

inline bool Vector2F_IsOutOfBounds(const Vector2F* const _vector, const size_t _index);

inline bool Vector2F_IsValid(const Vector2F* const _vector, const size_t _index);

inline Tuple2F Vector2F_LeftScalar(void);

int Vector2F_Length(ArrayF* const _result, const size_t _resultIndex,
	                const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count);

inline float Vector2F_LengthScalar(const Vector2F* const _vector, const size_t _index);

int Vector2F_LengthSquared(ArrayF* const _result, const size_t _resultIndex,
	                       const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count);

inline float Vector2F_LengthSquaredScalar(const Vector2F* const _vector, const size_t _index);

int Vector2F_Lerp(Vector2F* const _result, const size_t _resultIndex,
	              const Vector2F* const _left, const size_t _leftIndex,
	              const Vector2F* const _right, const size_t _rightIndex,
	              const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count);

inline Tuple2F Vector2F_LerpScalar(const Vector2F* const _left, const size_t _leftIndex,
	                               const Vector2F* const _right, const size_t _rightIndex,
	                               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex);

int Vector2F_LerpUnclamped(Vector2F* const _result, const size_t _resultIndex,
	                       const Vector2F* const _left, const size_t _leftIndex,
	                       const Vector2F* const _right, const size_t _rightIndex,
	                       const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count);

inline Tuple2F Vector2F_LerpUnclampedScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                        const Vector2F* const _right, const size_t _rightIndex,
	                                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex);

int Vector2F_Max(Vector2F* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_MaxScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex);

int Vector2F_Min(Vector2F* const _result, const size_t _resultIndex,
	             const Vector2F* const _left, const size_t _leftIndex,
	             const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_MinScalar(const Vector2F* const _left, const size_t _leftIndex,
	                              const Vector2F* const _right, const size_t _rightIndex);

int Vector2F_MoveTowards(Vector2F* const _result, const size_t _resultIndex,
	                     const Vector2F* const _current, const size_t _currentIndex,
	                     const Vector2F* const _target, const size_t _targetIndex,
	                     const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex, const size_t _count);

inline Tuple2F Vector2F_MoveTowardsScalar(const Vector2F* const _current, const size_t _currentIndex,
	                                      const Vector2F* const _target, const size_t _targetIndex,
	                                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex);

int Vector2F_Multiply(Vector2F* const _result, const size_t _resultIndex,
	                  const Vector2F* const _left, const size_t _leftIndex,
	                  const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_MultiplyScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                   const Vector2F* const _right, const size_t _rightIndex);

int Vector2F_Normalize(Vector2F* const _vector, const size_t _index, const size_t _count);

inline void Vector2F_NormalizeScalar(Vector2F* const _vector, const size_t _index);

inline Tuple2F Vector2F_OneScalar(void);

int Vector2F_Perpendicular(Vector2F* const _result, const size_t _resultIndex,
	                       const Vector2F* const _vector, const size_t _vectorIndex, const size_t _count);

inline Tuple2F Vector2F_PerpendicularScalar(const Vector2F* const _vector, const size_t _index);

int Vector2F_Reflect(Vector2F* const _result, const size_t _resultIndex,
	                 const Vector2F* const _inDirection, const size_t _inDirectionIndex,
	                 const Vector2F* const _inNormal, const size_t _inNormalIndex, const size_t _count);

inline Tuple2F Vector2F_ReflectScalar(const Vector2F* const _inDirection, const size_t _inDirectionIndex,
	                                  const Vector2F* const _inNormal, const size_t _inNormalIndex);

inline Tuple2F Vector2F_RightScalar(void);

inline void Vector2F_Set(Vector2F* const _vector, const size_t _index, const Tuple2F _value);

int Vector2F_SignedAngle(ArrayF* const _result, const size_t _resultIndex,
	                     const Vector2F* const _from, const size_t _fromIndex,
	                     const Vector2F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector2F_SignedAngleScalar(const Vector2F* const _from, const size_t _fromIndex,
	                                    const Vector2F* const _to, const size_t _toIndex);

int Vector2F_SmoothDamp(Vector2F* const _result, const size_t _resultIndex,
	                    const Vector2F* const _current, const size_t _currentIndex,
	                    const Vector2F* const _target, const size_t _targetIndex,
	                    Vector2F* const _currentVelocity, const size_t _currentVelocityIndex,
	                    const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                    const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                    const ArrayF* const _deltaTime, const size_t _deltaTimeIndex, const size_t _count);

inline Tuple2F Vector2F_SmoothDampScalar(const Vector2F* const _current, const size_t _currentIndex,
	                                     const Vector2F* const _target, const size_t _targetIndex,
	                                     Vector2F* const _currentVelocity, const size_t _currentVelocityIndex,
	                                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex);

int Vector2F_Subtract(Vector2F* const _result, const size_t _resultIndex,
	                  const Vector2F* const _left, const size_t _leftIndex,
	                  const Vector2F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple2F Vector2F_SubtractScalar(const Vector2F* const _left, const size_t _leftIndex,
	                                   const Vector2F* const _right, const size_t _rightIndex);

inline void Vector2F_ToString(char* _result, const size_t _resultSize, const Vector2F* const _vector, const size_t _index);

inline Tuple2F Vector2F_UpScalar(void);

inline Tuple2F Vector2F_ZeroScalar(void);


#ifdef __cplusplus
}
#endif