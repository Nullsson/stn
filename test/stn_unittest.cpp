#include "../HyperTest/code/win32_hypertest.cpp"

#define STN_NO_TYPES
#include "../stn.h"

TEST(STN, Max)
{
    u32 Big = 1250;
    u32 Small = 500;

    UNITTEST_ASSERT_TRUE(STN_Max(Big, Small) == 1250);

    Big = 420;
    Small = 4000;

    UNITTEST_ASSERT_TRUE(STN_Max(Small, Big) == 4000);
}

TEST(STN, Min)
{
    u32 Big = 502584;
    u32 Small = 2359;

    UNITTEST_ASSERT_TRUE(STN_Min(Big, Small) == 2359);

    Big = 4392;
    Small = 9765;

    UNITTEST_ASSERT_TRUE(STN_Min(Big, Small) == 4392);
}