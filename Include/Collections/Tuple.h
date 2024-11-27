#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Tuple2F
{
    float x;
    float y;
} Tuple2F;

typedef struct Tuple3F
{
    float x;
    float y;
    float z;
} Tuple3F;


Tuple2F Tuple2F_Create(const float _x, const float _y);

Tuple3F Tuple3F_Create(const float _x, const float _y, const float _z);


inline Tuple2F Tuple2F_Create(const float _x, const float _y)
{
    Tuple2F tuple;
    tuple.x = _x;
    tuple.y = _y;

    return tuple;
}

inline Tuple3F Tuple3F_Create(const float _x, const float _y, const float _z)
{
    Tuple3F tuple;
    tuple.x = _x;
    tuple.y = _y;
    tuple.z = _z;

    return tuple;
}

#ifdef __cplusplus
}
#endif