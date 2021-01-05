#include "../HyperTest/code/hypertest.cpp"
#define STN_USE_STRING
#include "../stn.h"

TEST(STN_String, MatchPattern)
{
    UNITTEST_ASSERT_TRUE(MatchPattern("Null*", "Nullsson"));
    UNITTEST_ASSERT_TRUE(MatchPattern("*sson", "Nullsson"));
    UNITTEST_ASSERT_FALSE(MatchPattern("son", "Nullsson"));
    UNITTEST_ASSERT_FALSE(MatchPattern("*Nallsen", "Nullsson"));
    UNITTEST_ASSERT_FALSE(MatchPattern("Nullsson*", "Nullsson"));
    UNITTEST_ASSERT_TRUE(MatchPattern("Nullsson*", "Nullsson!"));
    UNITTEST_ASSERT_TRUE(MatchPattern("Null*sson", "NullIsson"));
    UNITTEST_ASSERT_TRUE(MatchPattern("Null*on", "Nullson"));
    UNITTEST_ASSERT_TRUE(MatchPattern("Nul**on", "Nullsson"));
}

TEST(STN_String, StringLength)
{
    UNITTEST_ASSERT_EQUAL(StringLength("Nullsson"), 8);
    UNITTEST_ASSERT_EQUAL(StringLength("Stn Library"), 11);
    UNITTEST_ASSERT_EQUAL(StringLength("Oskar"), CalculateCStringLength("Robot"));
    UNITTEST_ASSERT_NOTEQUAL(StringLength("AWordLongerThanRobot"), CalculateCStringLength("Robot"));
}

TEST(STN_String, StringsAreEqual)
{
    UNITTEST_ASSERT_TRUE(StringsAreEqual("Nullsson", "Nullsson"));
    UNITTEST_ASSERT_TRUE(StringsAreEqual("Stn Library", "Stn Library"));
    UNITTEST_ASSERT_FALSE(StringsAreEqual("Oskar", "Robot"));
    UNITTEST_ASSERT_FALSE(StringsAreEqual("AWordLongerThanRobot", "Robot"));
    UNITTEST_ASSERT_FALSE(StringsAreEqual("Nullsson", "NULLSSON"));
}

TEST(STN_String, StringContains)
{
    UNITTEST_ASSERT_TRUE(StringContains("Nullsson", "Nullsson"));
    UNITTEST_ASSERT_TRUE(StringContains("Stn Library", "Stn Library"));
    UNITTEST_ASSERT_FALSE(StringContains("Oskar", "Robot"));
    UNITTEST_ASSERT_TRUE(StringContains("AWordLongerThanRobot", "Robot"));
    UNITTEST_ASSERT_FALSE(StringContains("Nullsson", "NULLSSON"));
    UNITTEST_ASSERT_TRUE(StringContains("Made by Nullsson", "Nullsson"));
}

TEST(STN_String, CharIsSpace)
{
    UNITTEST_ASSERT_TRUE(CharIsSpace(' '));
    UNITTEST_ASSERT_FALSE(CharIsSpace('a'));
    UNITTEST_ASSERT_FALSE(CharIsSpace('1'));
    UNITTEST_ASSERT_FALSE(CharIsSpace('#'));
}

TEST(STN_String, CharIsAlpha)
{
    UNITTEST_ASSERT_FALSE(CharIsAlpha(' '));
    UNITTEST_ASSERT_TRUE(CharIsAlpha('a'));
    UNITTEST_ASSERT_TRUE(CharIsAlpha('H'));
    UNITTEST_ASSERT_FALSE(CharIsAlpha('1'));
    UNITTEST_ASSERT_FALSE(CharIsAlpha('#'));
}

TEST(STN_String, CharIsDigit)
{
    UNITTEST_ASSERT_FALSE(CharIsDigit(' '));
    UNITTEST_ASSERT_FALSE(CharIsDigit('a'));
    UNITTEST_ASSERT_FALSE(CharIsDigit('H'));
    UNITTEST_ASSERT_FALSE(CharIsDigit('#'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('0'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('1'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('2'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('3'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('4'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('5'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('6'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('7'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('8'));
    UNITTEST_ASSERT_TRUE(CharIsDigit('9'));
}