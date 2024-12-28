#include "Collections/Tuple.h"


inline Tuple2F Tuple2F_Create(const float _x, const float _y)
{
    Tuple2F tuple = { _x, _y };
    return tuple;
}

inline Tuple3F Tuple3F_Create(const float _x, const float _y, const float _z)
{
    Tuple3F tuple = { _x, _y, _z };
    return tuple;
}