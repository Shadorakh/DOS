#pragma once

#include <math.h>
#include <stdlib.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


extern const double E;

extern const double PI;

extern const double TAU;

extern const float EPSILON;


inline float AbsF(const float _value);

inline double AbsD(const double _value);

inline long double AbsLD(const long double _value);

inline float AcosF(const float _value);

inline double AcosD(const double _value);

inline long double AcosLD(const long double _value);

inline float AcoshF(const float _value);

inline double AcoshD(const double _value);

inline long double AcoshLD(const long double _value);

inline float AsinF(const float _value);

inline double AsinD(const double _value);

inline long double AsinLD(const long double _value);

inline float AsinhF(const float _value);

inline double AsinhD(const double _value);

inline long double AsinhLD(const long double _value);

inline float AtanF(const float _value);

inline double AtanD(const double _value);

inline long double AtanLD(const long double _value);

inline float Atan2F(const float _left, const float _right);

inline double Atan2D(const double _left, const double _right);

inline long double Atan2LD(const long double _left, const long double _right);

inline float AtanhF(const float _value);

inline double AtanhD(const double _value);

inline long double AtanhLD(const long double _value);

inline float CbrtF(const float _value);

inline double CbrtD(const double _value);

inline long double CbrtLD(const long double _value);

inline float CeilF(const float _value);

inline double CeilD(const double _value);

inline long double CeilLD(const long double _value);

inline int32_t ClampI(const int32_t _value, const int32_t _min, const int32_t _max);

inline uint32_t ClampUI(const uint32_t _value, const uint32_t _min, const uint32_t _max);

inline int64_t ClampL(const int64_t _value, const int64_t _min, const int64_t _max);

inline uint64_t ClampUL(const uint64_t _value, const uint64_t _min, const uint64_t _max);

inline float ClampF(const float _value, const float _min, const float _max);

inline double ClampD(const double _value, const double _min, const double _max);

inline long double ClampLD(const long double _value, const long double _min, const long double _max);

inline float Clamp01F(const float _value);

inline double Clamp01D(const double _value);

inline long double Clamp01LD(const long double _value);

inline float CosF(const float _value);

inline double CosD(const double _value);

inline long double CosLD(const long double _value);

inline float CoshF(const float _value);

inline double CoshD(const double _value);

inline long double CoshLD(const long double _value);

inline float ExpF(const float _value);

inline double ExpD(const double _value);

inline long double ExpLD(const long double _value);

inline float FloorF(const float _value);

inline double FloorD(const double _value);

inline long double FloorLD(const long double _value);

inline float LogF(const float _value);

inline double LogD(const double _value);

inline long double LogLD(const long double _value);

inline float Log10F(const float _value);

inline double Log10D(const double _value);

inline long double Log10LD(const long double _value);

inline float Log2F(const float _value);

inline double Log2D(const double _value);

inline long double Log2LD(const long double _value);

inline int32_t MaxI(const int32_t _left, const int32_t _right);

inline uint32_t MaxUI(const uint32_t _left, const uint32_t _right);

inline int64_t MaxL(const int64_t _left, const int64_t _right);

inline uint64_t MaxUL(const uint64_t _left, const uint64_t _right);

inline float MaxF(const float _left, const float _right);

inline double MaxD(const double _left, const double _right);

inline long double MaxLD(const long double _left, const long double _right);

inline int32_t MinI(const int32_t _left, const int32_t _right);

inline uint32_t MinUI(const uint32_t _left, const uint32_t _right);

inline int64_t MinL(const int64_t _left, const int64_t _right);

inline uint64_t MinUL(const uint64_t _left, const uint64_t _right);

inline float MinF(const float _left, const float _right);

inline double MinD(const double _left, const double _right);

inline long double MinLD(const long double _left, const long double _right);

inline float PowF(const float _left, const float _right);

inline double PowD(const double _left, const double _right);

inline long double PowLD(const long double _left, const long double _right);

inline float RoundF(const float _value);

inline double RoundD(const double _value);

inline long double RoundLD(const long double _value);

inline int32_t SignF(const float _value);

inline int32_t SignD(const double _value);

inline int32_t SignLD(const long double _value);

inline float SinF(const float _value);

inline double SinD(const double _value);

inline long double SinLD(const long double _value);

inline float SinhF(const float _value);

inline double SinhD(const double _value);

inline long double SinhLD(const long double _value);

inline float SqrtF(const float _value);

inline double SqrtD(const double _value);

inline long double SqrtLD(const long double _value);

inline float TanF(const float _value);

inline double TanD(const double _value);

inline long double TanLD(const long double _value);

inline float TanhF(const float _value);

inline double TanhD(const double _value);

inline long double TanhLD(const long double _value);


#ifdef __cplusplus
}
#endif