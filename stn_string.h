
#ifndef STN_STRING_H
#define STN_STRING_H

#include "stn.h"

struct buffer
{
   umm Count;
   u8 *Data;
};
typedef buffer string;

enum string_pattern_match_flag
{
    StringPatternMatchFlag_None = 0x00,
    StringPatternMatchFlag_MaySkip = 0x01,
    StringPatternMatchFlag_Restarted = 0x02,
};

STN_INTERNAL b32
MatchPattern(char *Pattern, char *String)
{
    b32 Result = false;
    u32 Flags = StringPatternMatchFlag_None;
    char *P = Pattern;
    char *S = String;
    
    while (*S)
    {
        if (*P == '*')
        {
            Flags = StringPatternMatchFlag_MaySkip;
            ++P;
        }
        else if (Flags == StringPatternMatchFlag_MaySkip)
        {
            Result = true;
            if (*S == *P)
            {
                Flags = StringPatternMatchFlag_None;
                ++P;
                ++S;
            }
            else
            {
                Flags = StringPatternMatchFlag_MaySkip;
                ++S;
            }
        }
        else if (*S != *P)
        {
            if (Flags == StringPatternMatchFlag_Restarted)
            {
                break;
            }
            
            Result = false;
            Flags = StringPatternMatchFlag_Restarted;
            P = Pattern;
        }
        else
        {
            Result = true;
            Flags = StringPatternMatchFlag_None;
            ++P;
            ++S;
        }
    }
    
    return (Result && (*P == 0));
}

inline u32
StringLength(char *String)
{
    u32 Count = 0;
    if (String)
    {
        while (*String++)
        {
            ++Count;
        }
    }
    
    return (Count);
}

STN_INTERNAL b32
StringsAreEqual(char *A, char *B)
{
    b32 Result = (A == B);
    
    if(A && B)
    {
        while(*A && *B && (*A == *B))
        {
            ++A;
            ++B;
        }
        
        Result = ((*A == 0) && (*B == 0));
    }

    return (Result);
}

STN_INTERNAL b32
StringCompare(char *A, char *B)
{
    b32 Result = false;

    while (*A && *B)
    {
        if (*A != *B)
        {
            return (Result);
        }
        A++;
        B++;
    }

    if (*B == '\0')
    {
        Result = true;
    }

    return (Result);
}

STN_INTERNAL b32
StringContains(char *A, char *B)
{
    b32 Result = false;

    if (A && B)
    {
        while (*A != '\0')
        {
            if ((*A == *B) && StringCompare(A, B))
            {
                Result = true;
                break;
            }
            A++;
        }
    }

    return (Result);
}

#endif // STN_STRING_H