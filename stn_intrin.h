/*
   stn_intrin.h - v1.0.1

   ----------------------------------------------------------------------------

   MIT License

   Copyright (c) 2021 Nullsson

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#ifndef STN_INTRIN_H
#define STN_INTRIN_H

#ifdef STN_COMPILER_MSVC

#define CompletePreviousReadsBeforeFutureReads _ReadBarrier()
#define CompletePreviousWritesBeforeFutureWrites _WriteBarrier();

STN_INTERNAL u32 
AtomicCompareExchangeU32(u32 volatile *Value, u32 New, u32 Expected)
{
    u32 Result = _InterlockedCompareExchange((long *)Value, New, Expected);

    return (Result);
}

STN_INTERNAL u32 
AtomicExchangeU32(u32 volatile *Value, u32 New)
{
    u32 Result = _InterlockedExchange((long *)Value, New);

    return (Result);
}

STN_INTERNAL u32 
AtomicAddU32(u32 volatile *Value, u32 Addend)
{
    // NOTE(Oskar): Returns the original value before adding.
    u32 Result = _InterlockedExchangeAdd((long *)Value, Addend);

    return (Result);
}

STN_INTERNAL u64 
AtomicExchangeU64(u64 volatile *Value, u64 New)
{
    u64 Result = _InterlockedExchange64((__int64 *)Value, New);

    return (Result);
}

STN_INTERNAL u64 
AtomicAddU64(u64 volatile *Value, u64 Addend)
{
    // NOTE(Oskar): Returns the original value before adding.
    u64 Result = _InterlockedExchangeAdd64((__int64 *)Value, Addend);

    return (Result);
}

#elif COMPILER_LLVM

#define CompletePreviousReadsBeforeFutureReads asm volatile("" ::: "memory")
#define CompletePreviousWritesBeforeFutureWrites asm volatile("" ::: "memory")

STN_INTERNAL uint32 
AtomicCompareExchangeUInt32(uint32 volatile *Value, uint32 New, uint32 Expected)
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

STN_INTERNAL s32
RoundReal32ToInt32(f32 F32)
{
    u32 Result = (u32)_mm_cvtss_si32(_mm_set_ss(F32));
    return (Result);
}

STN_INTERNAL i32
FloorReal32ToInt32(f32 F32)
{
    // TODO(Oskar): SSE 4.1?
    i32 Result = _mm_cvtss_si32(_mm_floor_ss(_mm_setzero_ps(), _mm_set_ss(F32)));
    
    return(Result);
}

STN_INTERNAL i32
CeilReal32ToInt32(f32 F32)
{
    // TODO: SSE 4.1?
    i32 Result = _mm_cvtss_si32(_mm_ceil_ss(_mm_setzero_ps(), _mm_set_ss(F32)));
    
    return(Result);
}

#endif // STN_INTRIN_H