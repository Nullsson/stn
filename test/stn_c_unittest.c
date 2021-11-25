#include "../HyperTest/code/hypertest.cpp"
#define STN_USE_ALL
#include "../stn.h"

TEST(STN_Math, Lerp)
{
    UNITTEST_ASSERT_EQUAL(Lerp(0.0f, 1.0f, 0.0f), 0.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(-25.0f, 50.0f, 1.0f), 50.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(-25.0f, 50.0f, 0.0f), -25.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(100.0f, 10.0f, 0.0f), 100.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(0.0f, 100.0f, 0.5f), 50.0f);
}

TEST(STN_Math, VectorAdd)
{
    vector2 V21 = Vector2Init(1.0f, 1.0f);
    vector2 V22 = Vector2Init(2.0f, 2.0f);
    
    vector2 V2R = Vector2Add(V21, V22);
    UNITTEST_EXPECT_EQUAL(V2R.X, 3.0f);
    UNITTEST_EXPECT_EQUAL(V2R.Y, 3.0f);

    vector3 V31 = Vector3Init(1.0f, 1.0f, 1.0f);
    vector3 V32 = Vector3Init(1.0f, 1.0f, 1.0f);
    
    vector3 V3R = Vector3Add(V31, V32);
    UNITTEST_EXPECT_EQUAL(V3R.X, 2.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 2.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, 2.0f);
}

TEST(STN_String, StringLength)
{
    UNITTEST_ASSERT_EQUAL(StringLength("Nullsson"), 8);
    UNITTEST_ASSERT_EQUAL(StringLength("Stn Library"), 11);
    UNITTEST_ASSERT_EQUAL(StringLength("Oskar"), CalculateCStringLength("Robot"));
    UNITTEST_ASSERT_NOTEQUAL(StringLength("AWordLongerThanRobot"), CalculateCStringLength("Robot"));
    UNITTEST_ASSERT_EQUAL(StringLength("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."), 445);
}

typedef struct byte8 byte8;
struct byte8
{
    u32 Number1;
    u32 Number2;
};

TEST(STN_Memory, MemoryArenaInit)
{
    void *Memory = (void *)malloc(1024);
    memory_arena Arena = MemoryArenaInit(Memory, 1024, 8);

    UNITTEST_ASSERT_EQUAL(Arena.Memory, Memory);
    UNITTEST_ASSERT_EQUAL(Arena.MemorySize, 1024);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 1024);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);

    void *OtherMemory = (void *)malloc(512);
    memory_arena ArenaWithAlignment = MemoryArenaInit(OtherMemory, 512, 16);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.Memory, OtherMemory);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemorySize, 512);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemoryLeft, 512);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MinimumAlignment, 16);

    free(Memory);
    free(OtherMemory);
}


TEST(STN_Memory, MemoryArenaAllocate)
{
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256, 8);

    UNITTEST_ASSERT_EQUAL(Arena.Memory, Memory);
    UNITTEST_ASSERT_EQUAL(Arena.MemorySize, 256);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);

    UNITTEST_EXPECT_EQUAL(sizeof(byte8), 8);
    byte8 *AllocatedStruct = (byte8 *)MemoryArenaAllocate(&Arena, sizeof(byte8), 1);
    AllocatedStruct->Number1 = 5;
    AllocatedStruct->Number2 = 10;

    UNITTEST_ASSERT_EQUAL(AllocatedStruct->Number1, 5);
    UNITTEST_ASSERT_EQUAL(AllocatedStruct->Number2, 10);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 8);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - 8);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);
    
    MemoryArenaAllocate(&Arena, 50, 1);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 58);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - 58);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);
    
    free(Memory);
}