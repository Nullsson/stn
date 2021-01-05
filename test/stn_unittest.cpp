#include "../HyperTest/code/hypertest.cpp"
#include "../stn.h"

TEST(STN, ArrayCount)
{
    u32 FirstArray[10];
    UNITTEST_ASSERT_EQUAL(STN_ArrayCount(FirstArray), 10);

    u32 SecondArray[6532];
    u32 (*SecondArrayCopy)[6532] = &SecondArray;
    UNITTEST_ASSERT_EQUAL(STN_ArrayCount(SecondArray), 6532);
    UNITTEST_ASSERT_EQUAL(STN_ArrayCount(*SecondArrayCopy), 6532);
}

TEST(STN, Max)
{
    UNITTEST_ASSERT_TRUE(STN_Max(1250, 500) == 1250);
    UNITTEST_ASSERT_TRUE(STN_Max(4000, 420) == 4000);
    UNITTEST_ASSERT_TRUE(STN_Max(0, 0) == 0);
    UNITTEST_ASSERT_TRUE(STN_Max(1, 0) == 1);
    UNITTEST_ASSERT_TRUE(STN_Max(0, 1) == 1);
}

TEST(STN, Min)
{
    UNITTEST_ASSERT_TRUE(STN_Min(502584, 2359) == 2359);
    UNITTEST_ASSERT_TRUE(STN_Min(4392, 9765) == 4392);
    UNITTEST_ASSERT_TRUE(STN_Min(0, 0) == 0);
    UNITTEST_ASSERT_TRUE(STN_Min(1, 0) == 0);
    UNITTEST_ASSERT_TRUE(STN_Min(0, 1) == 0);
}

TEST(STN, Align4_Positive)
{
    UNITTEST_ASSERT_EQUAL(STN_Align4(0), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align4(1), 4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(2), 4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(3), 4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(4), 4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(5), 8);
}

TEST(STN, Align4_Negative)
{
    UNITTEST_ASSERT_EQUAL(STN_Align4(-1), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align4(-4), -4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(-5), -4);
    UNITTEST_ASSERT_EQUAL(STN_Align4(-8), -8);
}

// NOTE(Oskar): This might need some additional thought put into it.
TEST(STN, Align4_Memory)
{
    u8 *Memory = (u8 *)malloc(STN_Bytes(256) * sizeof(u8));
    UNITTEST_ASSERT_FALSE(Memory == NULL);

    for (u32 I = 0; I < 256-1; ++I)
    {
        u8 *Temp = Memory + I;
        *Temp = STN_Align4(I);
    }

    for (u32 I = 0; I < 256-1; I+=4)
    {
        u8 *Temp = Memory + STN_Align4(I);
        UNITTEST_ASSERT_EQUAL(*Temp, STN_Align4(I));
    }

    free(Memory);
}

TEST(STN, Align8_Positive)
{
    UNITTEST_ASSERT_EQUAL(STN_Align8(0), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align8(1), 8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(2), 8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(3), 8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(4), 8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(5), 8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(9), 16);
}

TEST(STN, Align8_Negative)
{
    UNITTEST_ASSERT_EQUAL(STN_Align8(-1), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align8(-4), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align8(-8), -8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(-9), -8);
    UNITTEST_ASSERT_EQUAL(STN_Align8(-16), -16);
}

// NOTE(Oskar): This might need some additional thought put into it.
TEST(STN, Align8_Memory)
{
    u8 *Memory = (u8 *)malloc(STN_Bytes(256) * sizeof(u8));
    UNITTEST_ASSERT_FALSE(Memory == NULL);

    for (u32 I = 0; I < 256-1; ++I)
    {
        u8 *Temp = Memory + I;
        *Temp = STN_Align8(I);
    }

    for (u32 I = 0; I < 256-1; I+=8)
    {
        u8 *Temp = Memory + STN_Align8(I);
        UNITTEST_ASSERT_EQUAL(*Temp, STN_Align8(I));
    }

    free(Memory);
}

TEST(STN, Align16_Positive)
{
    UNITTEST_ASSERT_EQUAL(STN_Align16(0), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align16(1), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(2), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(3), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(4), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(5), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(9), 16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(17), 32);
}

TEST(STN, Align16_Negative)
{
    UNITTEST_ASSERT_EQUAL(STN_Align16(-1), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-4), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-8), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-9), 0);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-16), -16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-17), -16);
    UNITTEST_ASSERT_EQUAL(STN_Align16(-32), -32);
}

// NOTE(Oskar): This might need some additional thought put into it.
TEST(STN, Align16_Memory)
{
    u8 *Memory = (u8 *)malloc(STN_Bytes(256) * sizeof(u8));
    UNITTEST_ASSERT_FALSE(Memory == NULL);

    for (u32 I = 0; I < 256-1; ++I)
    {
        u8 *Temp = Memory + I;
        *Temp = STN_Align16(I);
    }

    for (u32 I = 0; I < 256-1; I+=16)
    {
        u8 *Temp = Memory + STN_Align16(I);
        UNITTEST_ASSERT_EQUAL(*Temp, STN_Align16(I));
    }

    free(Memory);
}