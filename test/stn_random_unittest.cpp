#include "../HyperTest/code/hypertest.cpp"
#define STN_USE_RANDOM
#include "../stn.h"

TEST(STN_Random, RandomSeed)
{
    random_sequence NormalSeed = RandomSeed(4096/2);
    random_sequence OverflownSeed = RandomSeed(4097);

    UNITTEST_ASSERT_EQUAL(NormalSeed.Index, 4096/2);
    UNITTEST_ASSERT_EQUAL(OverflownSeed.Index, 1);
}

TEST(STN_Random, RandomNextU32)
{
    random_sequence RandomSequence = RandomSeed(0);

    UNITTEST_ASSERT_EQUAL(RandomNextU32(&RandomSequence), RandomNumberTable[0]);
    UNITTEST_ASSERT_EQUAL(RandomNextU32(&RandomSequence), RandomNumberTable[1]);

    random_sequence OverflowSequence = RandomSeed(4095);
    UNITTEST_ASSERT_EQUAL(RandomNextU32(&OverflowSequence), RandomNumberTable[4095]);
    UNITTEST_ASSERT_EQUAL(RandomNextU32(&OverflowSequence), RandomNumberTable[0]);
}

TEST(STN_Random, RandomSingleNumerical)
{
    random_sequence RandomSequence = RandomSeed(0);

    for (u32 Index = 0; Index < STN_ArrayCount(RandomNumberTable); ++Index)
    {
        f32 RandomNumber = RandomSingleNumerical(&RandomSequence);
        UNITTEST_ASSERT_TRUE(RandomNumber <= 1.0f);
        UNITTEST_ASSERT_TRUE(RandomNumber >= 0.0f);
    }
}

TEST(STN_Random, RandomBetweenI32)
{
    random_sequence RandomSequence = RandomSeed(0);

    for (u32 Index = 0; Index < STN_ArrayCount(RandomNumberTable) / 2; ++Index)
    {
        u32 Min = RandomNextU32(&RandomSequence);
        u32 Max = RandomNextU32(&RandomSequence);

        if (Max < Min)
        {
            u32 Temp = Max;
            Max = Min;
            Min = Temp;
        }

        i32 RandomNumber = RandomBetweenI32(&RandomSequence, (i32)Min, (i32)Max);
        UNITTEST_ASSERT_TRUE(RandomNumber >= Min);
        UNITTEST_ASSERT_TRUE(RandomNumber <= Max);
    }
}

TEST(STN_Random, RandomBetweenF32)
{
    random_sequence RandomSequence = RandomSeed(0);

    for (u32 Index = 0; Index < STN_ArrayCount(RandomNumberTable) / 2; ++Index)
    {
        u32 Min = RandomNextU32(&RandomSequence);
        u32 Max = RandomNextU32(&RandomSequence);

        if (Max < Min)
        {
            u32 Temp = Max;
            Max = Min;
            Min = Temp;
        }

        i32 RandomNumber = RandomBetweenF32(&RandomSequence, (f32)Min, (f32)Max);
        UNITTEST_ASSERT_TRUE(RandomNumber >= Min);
        UNITTEST_ASSERT_TRUE(RandomNumber <= Max);
    }
}