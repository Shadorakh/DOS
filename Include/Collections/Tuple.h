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


inline Tuple2F Tuple2F_Create(const float _x, const float _y);

inline Tuple3F Tuple3F_Create(const float _x, const float _y, const float _z);


#ifdef __cplusplus
}
#endif