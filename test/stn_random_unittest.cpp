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

}

TEST(STN_Random, RandomSingleNumerical)
{

}

TEST(STN_Random, RandomBetweenI32)
{

}

TEST(STN_Random, RandomBetweenF32)
{

}