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


VectorF* VectorF_Add(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_And(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_AndNot(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_Clamp(VectorF* const _result, const VectorF* const _value, const float _min, const float _max);

VectorF* VectorF_Clamp01(VectorF* const _result, const VectorF* const _value);

VectorF* VectorF_CompareEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareNotEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareNotGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareNotGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareNotLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareNotLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareOrdered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_CompareUnordered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_ConvertScalarToVectorF(VectorF* const _result, const VectorF* const _upper, const int _value);

int VectorF_ConvertToInt32(const VectorF* const _value);

int VectorF_ConvertToInt32WithTruncation(const VectorF* const _value);

VectorF* VectorF_Divide(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

bool VectorF_IsSupported(void);

VectorF* VectorF_Load(VectorF* const _result, const ArrayF* const _value, const size_t _index);

VectorF* VectorF_LoadUnaligned(VectorF* const _result, const ArrayF* const _value, const size_t _index);

VectorF* VectorF_Max(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_Min(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_MoveHighToLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_MoveLowToHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

int VectorF_MoveMask(const VectorF* const _value);

VectorF* VectorF_MoveScalar(VectorF* const _result, const VectorF* const _upper, const VectorF* const _value);

VectorF* VectorF_Multiply(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_Or(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

void VectorF_Prefetch(const char* _address, int32_t _local);

VectorF* VectorF_Reciprocal(VectorF* const _result, const VectorF* const _value);

VectorF* VectorF_ReciprocalSqrt(VectorF* const _result, const VectorF* const _value);

VectorF* VectorF_SetZero(VectorF* const _result);

VectorF* VectorF_SetValue(VectorF* const _result, const float _value);

VectorF* VectorF_Set(VectorF* const _result, const float _v0, const float _v1, const float _v2, const float _v3);

VectorF* VectorF_Shuffle(VectorF* const _result, const VectorF* const _left, const VectorF* const _right, const uint32_t _control);

size_t VectorF_Size(void);

VectorF* VectorF_Sqrt(VectorF* const _result, const VectorF* const _value);

void VectorF_Store(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

void VectorF_StoreUnaligned(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

void VectorF_StoreNonTemporal(const VectorF* const _source, ArrayF* const _destination, const size_t _index);

VectorF* VectorF_Subtract(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_UnpackHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_UnpackLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);

VectorF* VectorF_Xor(VectorF* const _result, const VectorF* const _left, const VectorF* const _right);



inline VectorF* VectorF_Add(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_add_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_And(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_and_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_AndNot(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_andnot_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_Clamp(VectorF* const _result, const VectorF* const _value, const float _min, const float _max)
{
	_result->vector = _mm_min_ps(_mm_max_ps(_value->vector, _mm_set_ps1(_min)), _mm_set_ps1(_max));
	return _result;
}

inline VectorF* VectorF_Clamp01(VectorF* const _result, const VectorF* const _value)
{
	return VectorF_Clamp(_result, _value, 0.0F, 1.0F);
}

inline VectorF* VectorF_CompareEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpeq_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpgt_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpge_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmplt_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmple_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareNotEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpneq_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareNotGreaterThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpngt_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareNotGreaterThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpnge_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareNotLessThan(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpnlt_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareNotLessThanOrEqual(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpnle_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareOrdered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpord_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_CompareUnordered(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_cmpunord_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_ConvertScalarToVectorF(VectorF* const _result, const VectorF* const _upper, const int _value)
{
	_result->vector = _mm_cvt_si2ss(_upper->vector, _value);
	return _result;
}

inline int VectorF_ConvertToInt32(const VectorF* const _value)
{
	return _mm_cvt_ss2si(_value->vector);
}

inline int VectorF_ConvertToInt32WithTruncation(const VectorF* const _value)
{
	return _mm_cvtt_ss2si(_value->vector);
}

inline VectorF* VectorF_Divide(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_div_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_Load(VectorF* const _result, const ArrayF* const _value, const size_t _index)
{
	_result->vector = _mm_load_ps(&_value->data[_index]);
	return _result;
}

inline VectorF* VectorF_LoadUnaligned(VectorF* const _result, const ArrayF* const _value, const size_t _index)
{
	_result->vector = _mm_loadu_ps(&_value->data[_index]);
	return _result;
}

inline VectorF* VectorF_Max(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_max_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_Min(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_min_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_MoveHighToLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_movehl_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_MoveLowToHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_movelh_ps(_left->vector, _right->vector);
	return _result;
}

inline int VectorF_MoveMask(const VectorF* const _value)
{
	return _mm_movemask_ps(_value->vector);
}

inline VectorF* VectorF_MoveScalar(VectorF* const _result, const VectorF* const _upper, const VectorF* const _value)
{
	_result->vector = _mm_move_ss(_upper->vector, _value->vector);
	return _result;
}

inline VectorF* VectorF_Multiply(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_mul_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_Or(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_or_ps(_left->vector, _right->vector);
	return _result;
}

inline void VectorF_Prefetch(const char* _address, int32_t _local)
{
	_mm_prefetch(_address, _local);
}

inline VectorF* VectorF_Reciprocal(VectorF* const _result, const VectorF* const _value)
{
	_result->vector = _mm_rcp_ps(_value->vector);
	return _result;
}

inline VectorF* VectorF_ReciprocalSqrt(VectorF* const _result, const VectorF* const _value)
{
	_result->vector = _mm_rsqrt_ps(_value->vector);
	return _result;
}

inline VectorF* VectorF_SetZero(VectorF* const _result)
{
	_result->vector = _mm_setzero_ps();
	return _result;
}

inline VectorF* VectorF_SetValue(VectorF* const _result, const float _value)
{
	_result->vector = _mm_set_ps1(_value);
	return _result;
}

inline VectorF* VectorF_Set(VectorF* const _result, const float _v0, const float _v1, const float _v2, const float _v3)
{
	_result->vector = _mm_set_ps(_v0, _v1, _v2, _v3);
	return _result;
}

inline VectorF* VectorF_Shuffle(VectorF* const _result, const VectorF* const _left, const VectorF* const _right, const uint32_t _control)
{
	_result->vector = _mm_shuffle_ps(_left->vector, _right->vector, _control);
	return _result;
}

inline size_t VectorF_Size(void)
{
	static size_t vectorSize = 0;

	if (vectorSize == 0)
	{
		vectorSize = VectorF_IsSupported() ? 4 : 1;
	}

	return vectorSize;
}

inline VectorF* VectorF_Sqrt(VectorF* const _result, const VectorF* const _value)
{
	_result->vector = _mm_sqrt_ps(_value->vector);
	return _result;
}

inline void VectorF_Store(const VectorF* const _source, ArrayF* const _destination, const size_t _index)
{
	_mm_store_ps(&_destination->data[_index], _source->vector);
}

inline void VectorF_StoreUnaligned(const VectorF* const _source, ArrayF* const _destination, const size_t _index)
{
	_mm_storeu_ps(&_destination->data[_index], _source->vector);
}

inline void VectorF_StoreNonTemporal(const VectorF* const _source, ArrayF* const _destination, const size_t _index)
{
	_mm_stream_ps(&_destination->data[_index], _source->vector);
}

inline VectorF* VectorF_Subtract(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_sub_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_UnpackHigh(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_unpackhi_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_UnpackLow(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_unpacklo_ps(_left->vector, _right->vector);
	return _result;
}

inline VectorF* VectorF_Xor(VectorF* const _result, const VectorF* const _left, const VectorF* const _right)
{
	_result->vector = _mm_xor_ps(_left->vector, _right->vector);
	return _result;
}

#ifdef __cplusplus
}
#endif