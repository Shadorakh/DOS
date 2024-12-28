#include "Mathematics/Math.h"


const double E = 2.7182818284590452354;

const double PI = 3.14159265358979323846;

const double TAU = 6.283185307179586476925;

const float EPSILON = 1.0E-6F;


inline float AbsF(const float _value)
{
    return fabsf(_value);
}

inline double AbsD(const double _value)
{
    return fabs(_value);
}

inline long double AbsLD(const long double _value)
{
    return fabsl(_value);
}

inline float AcosF(const float _value)
{
    return acosf(_value);
}

inline double AcosD(const double _value)
{
    return acos(_value);
}

inline long double AcosLD(const long double _value)
{
    return acosl(_value);
}

inline float AcoshF(const float _value)
{
    return acoshf(_value);
}

inline double AcoshD(const double _value)
{
    return acosh(_value);
}

inline long double AcoshLD(const long double _value)
{
    return acoshl(_value);
}

inline float AsinF(const float _value)
{
    return asinf(_value);
}

inline double AsinD(const double _value)
{
    return asin(_value);
}

inline long double AsinLD(const long double _value)
{
    return asinl(_value);
}

inline float AsinhF(const float _value)
{
    return asinhf(_value);
}

inline double AsinhD(const double _value)
{
    return asinh(_value);
}

inline long double AsinhLD(const long double _value)
{
    return asinhl(_value);
}

inline float AtanF(const float _value)
{
    return atanf(_value);
}

inline double AtanD(const double _value)
{
    return atan(_value);
}

inline long double AtanLD(const long double _value)
{
    return atanl(_value);
}

inline float Atan2F(const float _left, const float _right)
{
    return atan2f(_left, _right);
}

inline double Atan2D(const double _left, const double _right)
{
    return atan2(_left, _right);
}

inline long double Atan2LD(const long double _left, const long double _right)
{
    return atan2l(_left, _right);
}

inline float AtanhF(const float _value)
{
    return atanhf(_value);
}

inline double AtanhD(const double _value)
{
    return atanh(_value);
}

inline long double AtanhLD(const long double _value)
{
    return atanhl(_value);
}

inline float CbrtF(const float _value)
{
    return cbrtf(_value);
}

inline double CbrtD(const double _value)
{
    return cbrt(_value);
}

inline long double CbrtLD(const long double _value)
{
    return cbrtl(_value);
}

inline float CeilF(const float _value)
{
    return ceilf(_value);
}

inline double CeilD(const double _value)
{
    return ceil(_value);
}

inline long double CeilLD(const long double _value)
{
    return ceill(_value);
}

inline int32_t ClampI(const int32_t _value, const int32_t _min, const int32_t _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline uint32_t ClampUI(const uint32_t _value, const uint32_t _min, const uint32_t _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline int64_t ClampL(const int64_t _value, const int64_t _min, const int64_t _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline uint64_t ClampUL(const uint64_t _value, const uint64_t _min, const uint64_t _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline float ClampF(const float _value, const float _min, const float _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline double ClampD(const double _value, const double _min, const double _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline long double ClampLD(const long double _value, const long double _min, const long double _max)
{
    if (_value > _max)
    {
        return _max;
    }
    else if (_value < _min)
    {
        return _min;
    }

    return _value;
}

inline float Clamp01F(const float _value)
{
    if (_value > 1.0F)
    {
        return 1.0F;
    }
    else if (_value < 0.0F)
    {
        return 0.0F;
    }

    return _value;
}

inline double Clamp01D(const double _value)
{
    if (_value > 1.0)
    {
        return 1.0;
    }
    else if (_value < 0.0)
    {
        return 0.0;
    }

    return _value;
}

inline long double Clamp01LD(const long double _value)
{
    if (_value > 1.0L)
    {
        return 1.0L;
    }
    else if (_value < 0.0L)
    {
        return 0.0l;
    }

    return _value;
}

inline float CosF(const float _value)
{
    return cosf(_value);
}

inline double CosD(const double _value)
{
    return cos(_value);
}

inline long double CosLD(const long double _value)
{
    return cosl(_value);
}

inline float CoshF(const float _value)
{
    return coshf(_value);
}

inline double CoshD(const double _value)
{
    return cosh(_value);
}

inline long double CoshLD(const long double _value)
{
    return coshl(_value);
}

inline float ExpF(const float _value)
{
    return expf(_value);
}

inline double ExpD(const double _value)
{
    return exp(_value);
}

inline long double ExpLD(const long double _value)
{
    return expl(_value);
}

inline float FloorF(const float _value)
{
    return floorf(_value);
}

inline double FloorD(const double _value)
{
    return floor(_value);
}

inline long double FloorLD(const long double _value)
{
    return floorl(_value);
}

inline float LogF(const float _value)
{
    return logf(_value);
}

inline double LogD(const double _value)
{
    return log(_value);
}

inline long double LogLD(const long double _value)
{
    return logl(_value);
}

inline float Log10F(const float _value)
{
    return log10f(_value);
}

inline double Log10D(const double _value)
{
    return log10(_value);
}

inline long double Log10LD(const long double _value)
{
    return log10l(_value);
}

inline float Log2F(const float _value)
{
    return log2f(_value);
}

inline double Log2D(const double _value)
{
    return log2(_value);
}

inline long double Log2LD(const long double _value)
{
    return log2l(_value);
}

inline int32_t MaxI(const int32_t _left, const int32_t _right)
{
    return _left > _right ? _left : _right;
}

inline uint32_t MaxUI(const uint32_t _left, const uint32_t _right)
{
    return _left > _right ? _left : _right;
}

inline int64_t MaxL(const int64_t _left, const int64_t _right)
{
    return _left > _right ? _left : _right;
}

inline uint64_t MaxUL(const uint64_t _left, const uint64_t _right)
{
    return _left > _right ? _left : _right;
}

inline float MaxF(const float _left, const float _right)
{
    return _left > _right ? _left : _right;
}

inline double MaxD(const double _left, const double _right)
{
    return _left > _right ? _left : _right;
}

inline long double MaxLD(const long double _left, const long double _right)
{
    return _left > _right ? _left : _right;
}

inline int32_t MinI(const int32_t _left, const int32_t _right)
{
    return _left < _right ? _left : _right;
}

inline uint32_t MinUI(const uint32_t _left, const uint32_t _right)
{
    return _left < _right ? _left : _right;
}

inline int64_t MinL(const int64_t _left, const int64_t _right)
{
    return _left < _right ? _left : _right;
}

inline uint64_t MinUL(const uint64_t _left, const uint64_t _right)
{
    return _left < _right ? _left : _right;
}

inline float MinF(const float _left, const float _right)
{
    return _left < _right ? _left : _right;
}

inline double MinD(const double _left, const double _right)
{
    return _left < _right ? _left : _right;
}

inline long double MinLD(const long double _left, const long double _right)
{
    return _left < _right ? _left : _right;
}

inline float PowF(const float _left, const float _right)
{
    return powf(_left, _right);
}

inline double PowD(const double _left, const double _right)
{
    return pow(_left, _right);
}

inline long double PowLD(const long double _left, const long double _right)
{
    return powl(_left, _right);
}

inline float RoundF(const float _value)
{
    return roundf(_value);
}

inline double RoundD(const double _value)
{
    return round(_value);
}

inline long double RoundLD(const long double _value)
{
    return roundl(_value);
}

inline int32_t SignF(const float _value)
{
    return _fdsign(_value);
}

inline int32_t SignD(const double _value)
{
    return _dsign(_value);
}

inline int32_t SignLD(const long double _value)
{
    return _ldsign(_value);
}

inline float SinF(const float _value)
{
    return sinf(_value);
}

inline double SinD(const double _value)
{
    return sin(_value);
}

inline long double SinLD(const long double _value)
{
    return sinl(_value);
}

inline float SinhF(const float _value)
{
    return sinhf(_value);
}

inline double SinhD(const double _value)
{
    return sin(_value);
}

inline long double SinhLD(const long double _value)
{
    return sinl(_value);
}

inline float SqrtF(const float _value)
{
    return sqrtf(_value);
}

inline double SqrtD(const double _value)
{
    return sqrt(_value);
}

inline long double SqrtLD(const long double _value)
{
    return sqrtl(_value);
}

inline float TanF(const float _value)
{
    return tanf(_value);
}

inline double TanD(const double _value)
{
    return tan(_value);
}

inline long double TanLD(const long double _value)
{
    return tanl(_value);
}

inline float TanhF(const float _value)
{
    return tanhf(_value);
}

inline double TanhD(const double _value)
{
    return tanh(_value);
}

inline long double TanhLD(const long double _value)
{
    return tanhl(_value);
}