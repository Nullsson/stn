#ifndef STN_INTRIN_H
#define STN_INTRIN_H

#if COMPILER_MSVC
#define CompletePreviousReadsBeforeFutureReads _ReadBarrier()
#define CompletePreviousWritesBeforeFutureWrites _WriteBarrier();

inline u32 AtomicCompareExchangeUInt32(u32 volatile *Value, u32 New, u32 Expected)
{
    u32 Result = _InterlockedCompareExchange((long *)Value, New, Expected);

    return (Result);
}
#elif COMPILER_LLVM
#define CompletePreviousReadsBeforeFutureReads asm volatile("" ::: "memory")
#define CompletePreviousWritesBeforeFutureWrites asm volatile("" ::: "memory")

inline uint32 AtomicCompareExchangeUInt32(uint32 volatile *Value, uint32 New, uint32 Expected)
{
    uint32 Result = __sync_val_compare_and_swap(Value, Expected, New);

    return (Result);
}
#else
    // TODO(Oskar): Support GCC etc..
#endif

// NOTE(Oskar): Intel intristics helper defines.
#define STN_MMSquare(A) _mm_mul_ps(A, A)
#define STN_MMSquare256(A) _mm256_mul_ps(A, A)
#define STN_MMIndexF(A, I) ((f32 *)&(A))[I]
#define STN_MMIndexI(A, I) ((u32 *)&(A))[I]

inline s32
RoundReal32ToInt32(f32 F32)
{
    u32 Result = (u32)_mm_cvtss_si32(_mm_set_ss(F32));
    return (Result);
}

inline i32
FloorReal32ToInt32(f32 F32)
{
    // TODO(Oskar): SSE 4.1?
    i32 Result = _mm_cvtss_si32(_mm_floor_ss(_mm_setzero_ps(), _mm_set_ss(F32)));
    
    return(Result);
}

inline i32
CeilReal32ToInt32(f32 F32)
{
    // TODO: SSE 4.1?
    i32 Result = _mm_cvtss_si32(_mm_ceil_ss(_mm_setzero_ps(), _mm_set_ss(F32)));
    
    return(Result);
}

#endif // STN_INTRIN_H