
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
#include <stddef.h>
#include <limits.h>
#include <float.h>

#define STN_GLOBAL          static
#define STN_INTERNAL        static
#define STN_LOCAL_PERSIST   static

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

#define STN_PI                              (3.1415926535897f)
#define STN_PIf                             3.1415926535897f
#define STN_ONE_OVER_SQUARE_ROOT_OF_TWO_PI  0.3989422804
#define STN_ONE_OVER_SQUARE_ROOT_OF_TWO_PIf 0.3989422804f
#define STN_EULERS_NUMBER                   2.7182818284590452353602874713527
#define STN_EULERS_NUMBERf                  2.7182818284590452353602874713527f

#define STN_Bytes(n)      (n)
#define STN_Kilobytes(n)  (Bytes(n)*1024)
#define STN_Megabytes(n)  (Kilobytes(n)*1024)
#define STN_Gigabytes(n)  (Megabytes(n)*1024)

#define STN_Align4(Value)   ((Value + 3) & ~3)
#define STN_Align8(Value)   ((Value + 7) & ~7)
#define STN_Align16(Value)  ((Value + 15) & ~15)

#define STN_Min(a, b) ((a) < (b) ? (a) : (b))
#define STN_Max(a, b) ((a) > (b) ? (a) : (b))

#endif // STN_H