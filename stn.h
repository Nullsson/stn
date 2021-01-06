
#ifndef STN_H
#define STN_H

#if defined(_WIN32) && !defined(__MINGW32__)
   #ifndef _CRT_SECURE_NO_WARNINGS
   #define _CRT_SECURE_NO_WARNINGS
   #endif
   #ifndef _CRT_NONSTDC_NO_DEPRECATE
   #define _CRT_NONSTDC_NO_DEPRECATE
   #endif
   #ifndef _CRT_NON_CONFORMING_SWPRINTFS
   #define _CRT_NON_CONFORMING_SWPRINTFS
   #endif
   #if !defined(_MSC_VER) || _MSC_VER > 1700
   #include <intrin.h>
   #endif
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <xmmintrin.h>
#include <time.h>

#define STN_GLOBAL          static
#define STN_INTERNAL        static
#define STN_LOCAL_PERSIST   static

#define MemoryCopy memcpy
#define MemoryMove memmove
#define MemorySet  memset
#define CalculateCStringLength (u32)strlen

// NOTE(Oskar): Had to add this define for legacy projects of mine that already
//              have all of theese typedefs.
#ifndef STN_NO_TYPES
   typedef float           r32;
   typedef double          r64;
   typedef unsigned char   ubyte;
   typedef unsigned int    uint;
   typedef char            i8;
   typedef unsigned char   u8;
   typedef int16_t         i16;
   typedef uint16_t        u16;
   typedef int32_t         i32;
   typedef uint32_t        u32;
   typedef int64_t         i64;
   typedef uint64_t        u64;
   typedef i32             b32;
   typedef i8              s8;
   typedef i16             s16;
   typedef i32             s32;
   typedef i64             s64;

   typedef uintptr_t       umm;
   typedef intptr_t        smm;
#endif

#define STN_U16MAX 65535
#define STN_I32MIN ((i32)0x80000000)
#define STN_I32MAX ((i32)0x7fffffff)
#define STN_U32MIN 0
#define STN_U32MAX ((u32)-1)
#define STN_U64MAX ((u64)-1)
#define STN_R32MAX FLT_MAX
#define STN_R32MIN -FLT_MAX

#define STN_Bytes(n)      (n)
#define STN_Kilobytes(n)  (Bytes(n)*1024)
#define STN_Megabytes(n)  (Kilobytes(n)*1024)
#define STN_Gigabytes(n)  (Megabytes(n)*1024)

#define STN_Align4(Value)   ((Value + 3) & ~3)
#define STN_Align8(Value)   ((Value + 7) & ~7)
#define STN_Align16(Value)  ((Value + 15) & ~15)

#define STN_Min(a, b) ((a) < (b) ? (a) : (b))
#define STN_Max(a, b) ((a) > (b) ? (a) : (b))

#define STN_ArrayCount(a) (sizeof(a) / sizeof((a)[0]))

#ifdef STN_USE_ALL
   #include "stn_intrin.h"
   #include "stn_math.h"
   #include "stn_string.h"
   #include "stn_memory.h"
#else
   #ifdef STN_USE_INTRIN
   #include "stn_intrin.h"
   #endif

   #ifdef STN_USE_MATH
   #include "stn_math.h"
   #endif

   #ifdef STN_USE_STRING
   #include "stn_string.h"
   #endif

   #ifdef STN_USE_MEMORY
   #include "stn_memory.h"
   #endif
#endif

#endif // STN_H