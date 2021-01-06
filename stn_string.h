
#ifndef STN_STRING_H
#define STN_STRING_H

struct string
{
    char *Data;
    u32 Length;
    u32 Size;
    u32 MaxSize;
    b32 IsMutable;
};

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
StringContains(char *A, char *B)
{
    b32 Result = false;

    if (A && B)
    {
        while (*A != '\0')
        {
            if ((*A == *B) && StringsAreEqual(A, B))
            {
                Result = true;
                break;
            }
            A++;
        }
    }

    return (Result);
}

STN_INTERNAL b32
CharIsSpace(char C)
{
    return (C <= 32);
}

STN_INTERNAL b32
CharIsAlpha(char C)
{
    return ((C >= 'a' && C <= 'z') ||
            (C >= 'A' && C <= 'Z'));
}

STN_INTERNAL b32
CharIsDigit(char C)
{
    return (C >= '0' && C <= '9');
}

STN_INTERNAL b32
CStringMatchCaseSensitive(const char *String1, const char *String2)
{
    b32 Result = 1;

    if (String1 && String2)
    {
        for (u32 Index = 0;; ++Index)
        {
            if (String1[Index] != String2[Index])
            {
                Result = 0;
                break;
            }

            if (String1[Index] == 0 && String2[Index] == 0)
            {
                break;
            }
        }
    }
    else if (String1 || String2)
    {
        Result = 0;
    }

    return (Result);
}

// NOTE(Oskar): This does not verify that the destination buffer is of the correct size.
//              users of this function will have to verify themselves.
STN_INTERNAL void
CopyCStringToFixedSizeBuffer(char *Destination, u32 DestinationMax, char *Source)
{
    for(u32 Index = 0; Index < DestinationMax; ++Index)
    {
        Destination[Index] = Source[Index];
        if(Source[Index] == 0)
        {
            break;
        }
    }
    Destination[DestinationMax - 1] = 0;
}

STN_INTERNAL i32
GetFirstI32FromCString(char *String)
{
    i32 Result = 0;

    int LastDigit = -1;

    for (u32 Index = 0; String[Index]; ++Index)
    {
        if (CharIsDigit(String[Index]))
        {
            LastDigit = Index;
        }
        else if (LastDigit != -1)
        {
            break;
        }
    }

    if (LastDigit >= 0)
    {
        int DigitMultiplier = 1;

        for (int Index = LastDigit; Index >= 0; --Index)
        {
            if (CharIsDigit(String[Index]))
            {
                int Digit = String[Index] - '0';
                Result += DigitMultiplier * Digit;
                DigitMultiplier *= 10;
            }
            else
            {
                if (String[Index] == '-')
                {
                    Result *= -1;
                }
                break;
            }
        }
    }

    return (Result);
}

STN_INTERNAL u32
HashCString(char *String)
{
    u32 Hash = 5381;
    int C;
    while((C = *String++))
    {
        Hash = ((Hash << 5) + Hash) + C;
    }

    return (Hash);
}

#endif // STN_STRING_H