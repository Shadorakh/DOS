#include "Intrinsics/VectorF.h"

#include <stdbool.h> 

#if defined(_MSC_VER)

#include <intrin.h>

#endif


bool VectorF_IsSupported(void)
{
    static bool isSupported = false;
    static bool initialized = false;

    if (!initialized)
    {
        int result[4] = { 0 };

#if defined(_MSC_VER)
        __cpuid(result, 1);
#elif defined(__GNUC__) || defined(__clang__)
        asm volatile
            (
                "cpuid"
                : "=a"(result[0]), "=b"(result[1]), "=c"(result[2]), "=d"(result[3])
                : "a"(1), "c"(0)
            );
#endif

        isSupported = result[3] & (1 << 25);
        initialized = true;
    }

    return isSupported;
}