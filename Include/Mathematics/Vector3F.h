#pragma once

#include "Collections/Tuple.h"
#include "Collections/ArrayF.h"
#include "Math.h"

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Vector3F
{
	ArrayF x;
	ArrayF y;
	ArrayF z;
} Vector3F;


void Vector3F_Add(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_AddScalar(const Vector3F* const _left, const size_t _leftIndex,
	                              const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_Angle(ArrayF* const _result, const size_t _resultIndex,
	                const Vector3F* const _from, const size_t _fromIndex,
	                const Vector3F* const _to, const size_t _toIndex, size_t _count);

inline float Vector3F_AngleScalar(const Vector3F* const _from, const size_t _fromIndex,
	                              const Vector3F* const _to, const size_t _toIndex);

inline Tuple3F Vector3F_BackScalar(void);

void Vector3F_Copy(const Vector3F* const _from, const size_t _fromIndex,
	               Vector3F* const _to, const size_t _toIndex, const size_t _count);

inline void Vector3F_CopyScalar(const Vector3F* const _from, const size_t _fromIndex,
	                            Vector3F* const _to, const size_t _toIndex);

Vector3F* Vector3F_Create(const float _x, const float _y, const float _z, const size_t _size);

Vector3F* Vector3F_CreateZero(const size_t _size);

void Vector3F_Cross(Vector3F* const _result, const size_t _resultIndex,
	                const Vector3F* const _left, const size_t _leftIndex,
	                const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_CrossScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_Destroy(Vector3F** _vector);

void Vector3F_Distance(ArrayF* const _result, const size_t _resultIndex,
	                  const Vector3F* const _from, const size_t _fromIndex,
	                  const Vector3F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector3F_DistanceScalar(const Vector3F* const _from, const size_t _fromIndex,
	                                 const Vector3F* const _to, const size_t _toIndex);

void Vector3F_DistanceSquared(ArrayF* const _result, const size_t _resultIndex,
	                          const Vector3F* const _from, const size_t _fromIndex,
	                          const Vector3F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector3F_DistanceSquaredScalar(const Vector3F* const _from, const size_t _leftIndex,
	                                        const Vector3F* const _to, const size_t _rightIndex);

void Vector3F_Divide(Vector3F* const _result, const size_t _resultIndex,
	                 const Vector3F* const _left, const size_t _leftIndex,
	                 const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_DivideScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                 const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_Dot(ArrayF* const _result, const size_t _resultIndex,
	             const Vector3F* const _left, const size_t _leftIndex,
	             const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline float Vector3F_DotScalar(const Vector3F* const _left, const size_t _leftIndex,
	                            const Vector3F* const _right, const size_t _rightIndex);

inline Tuple3F Vector3F_DownScalar(void);

inline bool Vector3F_Equals(const Vector3F* const _left, const size_t _leftIndex,
	                       const Vector3F* const _right, const size_t _rightIndex);

inline Tuple3F Vector3F_ForwardScalar(void);

inline Tuple3F Vector3F_Get(const Vector3F* const _vector, const size_t _index);

inline bool Vector3F_IsNull(const Vector3F* const _vector);

inline Tuple3F Vector3F_LeftScalar(void);

void Vector3F_Length(ArrayF* const _result, const size_t _resultIndex,
	                 const Vector3F* const _vector, const size_t _vectorIndex, const size_t _count);

inline float Vector3F_LengthScalar(const Vector3F* const _vector, const size_t _index);

void Vector3F_LengthSquared(ArrayF* const _result, const size_t _resultIndex,
	                        const Vector3F* const _vector, const size_t _vectorIndex, const size_t _count);

inline float Vector3F_LengthSquaredScalar(const Vector3F* const _vector, const size_t _index);

void Vector3F_Lerp(Vector3F* const _result, const size_t _resultIndex,
	               const Vector3F* const _left, const size_t _leftIndex,
	               const Vector3F* const _right, const size_t _rightIndex,
	               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count);

inline Tuple3F Vector3F_LerpScalar(const Vector3F* const _left, const size_t _leftIndex,
	                               const Vector3F* const _right, const size_t _rightIndex,
	                               const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex);

void Vector3F_LerpUnclamped(Vector3F* const _result, const size_t _resultIndex,
	                        const Vector3F* const _left, const size_t _leftIndex,
	                        const Vector3F* const _right, const size_t _rightIndex,
	                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex, const size_t _count);

inline Tuple3F Vector3F_LerpUnclampedScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                        const Vector3F* const _right, const size_t _rightIndex,
	                                        const ArrayF* const _interpolationFactor, const size_t _interpolationFactorIndex);

void Vector3F_Max(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_MaxScalar(const Vector3F* const _left, const size_t _leftIndex,
	                       const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_Min(Vector3F* const _result, const size_t _resultIndex,
	              const Vector3F* const _left, const size_t _leftIndex,
	              const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_MinScalar(const Vector3F* const _left, const size_t _leftIndex,
	                              const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_MoveTowards(Vector3F* const _result, const size_t _resultIndex,
	                      const Vector3F* const _current, const size_t _currentIndex,
	                      const Vector3F* const _target, const size_t _targetIndex,
	                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex, const size_t _count);

inline Tuple3F Vector3F_MoveTowardsScalar(const Vector3F* const _current, const size_t _currentIndex,
	                                      const Vector3F* const _target, const size_t _targetIndex,
	                                      const ArrayF* const _maxDistanceDelta, const size_t _maxDistanceDeltaIndex);

void Vector3F_Multiply(Vector3F* const _result, const size_t _resultIndex,
	                   const Vector3F* const _left, const size_t _leftIndex,
	                   const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_MultiplyScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                   const Vector3F* const _right, const size_t _rightIndex);

void Vector3F_Normalize(Vector3F* const _vector, const size_t _index, const size_t _count);

inline void Vector3F_NormalizeScalar(Vector3F* const _vector, const size_t _index);

inline Tuple3F Vector3F_OneScalar(void);

void Vector3F_Project(Vector3F* const _result, const size_t _resultIndex,
	                  const Vector3F* const _vector, const size_t _vectorIndex,
	                  const Vector3F* const _onNormal, const size_t _onNormalIndex, const size_t _count);

inline Tuple3F Vector3F_ProjectScalar(const Vector3F* const _vector, const size_t _vectorIndex,
	                                  const Vector3F* const _onNormal, const size_t _onNormalIndex);

void Vector3F_ProjectOnPlane(Vector3F* const _result, const size_t _resultIndex,
	                         const Vector3F* const _vector, const size_t _vectorIndex,
	                         const Vector3F* const _planeNormal, const size_t _planeNormalIndex, const size_t _count);

inline Tuple3F Vector3F_ProjectOnPlaneScalar(const Vector3F* const _vector, const size_t _vectorIndex,
	                                         const Vector3F* const _planeNormal, const size_t _planeNormalIndex);

void Vector3F_Reflect(Vector3F* const _result, const size_t _resultIndex,
	                  const Vector3F* const _inDirection, const size_t _inDirectionIndex,
	                  const Vector3F* const _inNormal, const size_t _inNormalIndex, const size_t _count);

inline Tuple3F Vector3F_ReflectScalar(const Vector3F* const _inDirection, const size_t _inDirectionIndex,
	                                  const Vector3F* const _inNormal, const size_t _inNormalIndex);

inline Tuple3F Vector3F_RightScalar(void);

inline void Vector3F_Set(Vector3F* const _vector, const size_t _index, const Tuple3F _value);

void Vector3F_SignedAngle(ArrayF* const _result, const size_t _resultIndex,
	                      const Vector3F* const _from, const size_t _fromIndex,
	                      const Vector3F* const _to, const size_t _toIndex, const size_t _count);

inline float Vector3F_SignedAngleScalar(const Vector3F* const _from, const size_t _fromIndex,
	                                    const Vector3F* const _to, const size_t _toIndex);

void Vector3F_SmoothDamp(Vector3F* const _result, const size_t _resultIndex,
	                     const Vector3F* const _current, const size_t _currentIndex,
	                     const Vector3F* const _target, const size_t _targetIndex,
	                     Vector3F* const _currentVelocity, const size_t _currentVelocityIndex,
	                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex, const size_t _count);

inline Tuple3F Vector3F_SmoothDampScalar(const Vector3F* const _current, const size_t _currentIndex,
	                                     const Vector3F* const _target, const size_t _targetIndex,
	                                     Vector3F* const _currentVelocity, const size_t _currentVelocityIndex,
	                                     const ArrayF* const _smoothTime, const size_t _smoothTimeIndex,
	                                     const ArrayF* const _maxSpeed, const size_t _maxSpeedIndex,
	                                     const ArrayF* const _deltaTime, const size_t _deltaTimeIndex);

void Vector3F_Subtract(Vector3F* const _result, const size_t _resultIndex,
	                   const Vector3F* const _left, const size_t _leftIndex,
	                   const Vector3F* const _right, const size_t _rightIndex, const size_t _count);

inline Tuple3F Vector3F_SubtractScalar(const Vector3F* const _left, const size_t _leftIndex,
	                                   const Vector3F* const _right, const size_t _rightIndex);

inline void Vector3F_ToString(char* _result, const size_t _resultSize, const Vector3F* const _vector, const size_t _index);

inline Tuple3F Vector3F_UpScalar(void);

inline Tuple3F Vector3F_ZeroScalar(void);


#ifdef __cplusplus
}
#endif