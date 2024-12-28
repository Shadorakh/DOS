#pragma once

#include "Collections/ArrayF.h"

#include <xmmintrin.h>
#include <stdbool.h> 


#ifdef __cplusplus
extern "C" {
#endif


typedef struct VectorF
{
	__m128 vector;
} VectorF;


inline VectorF* VectorF_Add(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_And(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_AndNot(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_Clamp(VectorF* const _result, const VectorF* const _value, const float _min, const float _max);

inline VectorF* VectorF_Clamp01(VectorF* const _result, const VectorF* const _value);

inline VectorF* VectorF_CompareEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareNotEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareNotGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareNotGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareNotLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareNotLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareOrdered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_CompareUnordered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_ConvertScalarToVectorF(VectorF* const _result, const VectorF* const _upper, const int _value);

inline int VectorF_ConvertToInt32(const VectorF* const _value);

inline int VectorF_ConvertToInt32WithTruncation(const VectorF* const _value);

inline VectorF* VectorF_Divide(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

bool VectorF_IsSupported(void);

inline VectorF* VectorF_Load(VectorF* const _result, const ArrayF* const _value, const size_t _index);

inline VectorF* VectorF_LoadUnaligned(VectorF* const _result, const ArrayF* const _value, const size_t _index);

inline VectorF* VectorF_Max(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_Min(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_MoveHighToLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_MoveLowToHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline int VectorF_MoveMask(const VectorF* const _value);

inline VectorF* VectorF_MoveScalar(VectorF* const _result, const VectorF* const _upper, const VectorF* const _value);

inline VectorF* VectorF_Multiply(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_Or(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_Reciprocal(VectorF* const _result, const VectorF* const _value);

inline VectorF* VectorF_ReciprocalSqrt(VectorF* const _result, const VectorF* const _value);

inline VectorF* VectorF_SetZero(VectorF* const _result);

inline VectorF* VectorF_SetValue(VectorF* const _result, const float _value);

inline VectorF* VectorF_Set(VectorF* const _result, const float _v0, const float _v1, const float _v2, const float _v3);

inline size_t VectorF_Size(void);

inline VectorF* VectorF_Sqrt(VectorF* const _result, const VectorF* const _value);

inline void VectorF_Store(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

inline void VectorF_StoreUnaligned(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

inline void VectorF_StoreNonTemporal(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

inline VectorF* VectorF_Subtract(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_UnpackHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_UnpackLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

inline VectorF* VectorF_Xor(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);


#ifdef __cplusplus
}
#endif